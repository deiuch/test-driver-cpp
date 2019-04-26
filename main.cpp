#if defined __GNUC__ || defined __clang__
// g++ main.cpp -lstdc++fs -o test_driver.out
# include <experimental/filesystem>
#else
# include <filesystem>
#endif

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::
#if defined __GNUC__ || defined __clang__
	experimental::
#endif
	filesystem;


namespace Logging
{

static const fs::path log_path = fs::path("tests.log");
static const fs::path tmp_log_path = fs::path("tmp.log");

template<bool verbose = true>
class Logger
{
	std::ofstream log_file { log_path };
	std::ifstream tmp_log_file { tmp_log_path };

	size_t n_dirs = 0;
	size_t n_files = 0;
	size_t succeeded = 0;
	size_t failed = 0;

	fs::path cur_dir;
	fs::path cur_file;
	std::string cur_compiler;

	void log_intro()
	{
		if constexpr (verbose)
			std::cout << "C++ Compilers Test Driver.\n"
				"See " << log_path << " for results.";

		log_file << "C++ Test Driver Results"
			// << "Date: " << ...;
			<< std::endl;
	}

	void log_outro()
	{
		log_file << "\nRESULTS:"
			"\n# of directories: " << n_dirs
			<< "\n# of files: " << n_files
			<< "\n# of tests: " << succeeded + failed
			<< "\n# of tests succeeded: " << succeeded
			<< "\n# of tests failed: " << failed
			<< "\nSee " << log_path << " for details."
			<< std::endl;
	}

public:

	Logger()
	{
		log_intro();
	}

	void dir_entered(const fs::path &dir)
	{
		cur_dir = dir;
		++n_dirs;
		if constexpr (verbose)
			std::cout << "\n\n===== Enter directory: " << dir << std::endl;

		log_file << "\n\n\n==================== DIRECTORY: "
			<< dir << " ====================" << std::endl;
	}

	void file_opened(const fs::path &file)
	{
		cur_file = file;
		++n_files;
		if constexpr (verbose) std::cout << file << std::endl;

		log_file << "\n\n~~~~~~~~~~~~~~~~~~~~~~~ FILE: " << file
			<< "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}

	void compiler_considered(const std::string &command)
	{
		cur_compiler = command;
		// if constexpr (verbose) std::cout << "\n";
	}

	void log_test(const bool &res)
	{
		++(res ? succeeded : failed);
		if constexpr (verbose)
			std::cout << cur_compiler << ": "
				<< (res ? "OK" : "FAIL") << std::endl;

		tmp_log_file.open(tmp_log_path);
		log_file << "\n\nTEST #" << succeeded + failed
			<< " " << (res ? "succeeded" : "FAILED")
			<< "\nFile: " << cur_file
			<< "\nCompiler: \"" << cur_compiler << '\n'
			<< "Program/Compiler output (stderr):" << std::endl;
		// FIXME: efficiency, work with streams?
		char c;
		while (tmp_log_file.get(c))
			log_file << c;
		log_file << std::endl;
		tmp_log_file.close();
	}

	bool overall_report()
	{
		if constexpr (verbose)
			std::cout << "\n\nSucceeded: " << succeeded << std::endl
				<< "Failed: " << failed << std::endl;

		log_outro();
		return /*(bool)*/ failed;
	}
};

} // namespace Logging


namespace Testing
{

static const std::vector<std::string> compiler_list =
{
	"g++-8 -std=c++2a -pedantic-errors -o ",
	"clang++-7 -std=c++2a -pedantic-errors -o ",
	// "cl /std:c++latest /permissive- /Fe a.exe",
};
static const fs::path exec_path = fs::path("a.exe");

static const fs::path test_dir = fs::path("tests");

bool perform_test(
	const fs::path &src,
	const std::string &compile_command,
	const std::string &executable = exec_path.string(),
	const fs::path &err_log = Logging::tmp_log_path
	)
{
	std::string src_path = src.string();
	std::string log_ending = " > " + err_log.string() + " 2>&1";

#ifdef _WIN32
	std::replace(src_path.begin(), src_path.end(), '\\', '/');  // Useful for `wsl'
#endif

	const std::string compile_str
		= compile_command + executable + " \"" + src_path + "\"" + log_ending;
	if (system(compile_str.c_str()))  // If compilation failed...
	{
		// Check if compilation was supposed to fail
		return src_path.find('e') != std::string::npos;
	}
	else
	{
		// Check if the compiled app executes successfully
		const std::string run_str = "./" + executable + log_ending;
		return !system(run_str.c_str());
	}
}

} // namespace Testing


inline bool is_cpp_extension(const std::string &str)
{
	static const std::vector<std::string> CPP_EXTS
		= { ".C", ".cc", ".cpp", ".cxx", ".c++" };

	return std::find(CPP_EXTS.begin(), CPP_EXTS.end(), str) != CPP_EXTS.end();
}

inline bool is_cpp_file(const fs::directory_entry &file)
{
	return !fs::is_directory(file) &&
		file.path().has_extension() &&
		is_cpp_extension(file.path().extension().string());
}

int main(const int argc, const char * const * const argv)
{
	Logging::Logger log;

	for (const auto &dir : fs::directory_iterator(Testing::test_dir))
	{
		if (!fs::is_directory(dir)) continue;

		log.dir_entered(dir);

		for (const auto &file : fs::directory_iterator(dir.path()))
		{
			if (!is_cpp_file(file)) continue;

			log.file_opened(file);

			for (const auto &compiler : Testing::compiler_list)
			{
				log.compiler_considered(compiler + Testing::exec_path.string());

				log.log_test(Testing::perform_test(file, compiler));
				fs::remove(Testing::exec_path);
			}
		}
	}

	fs::remove(Logging::tmp_log_path);
	return log.overall_report();
}
