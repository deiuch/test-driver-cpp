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


namespace Testing
{

static const std::vector<std::string> compiler_list = { "g++", "clang++-7" };
static const std::string run_path = "./a.out";

static const fs::path test_dir = fs::path("tests");

bool perform_test(
	const fs::path &src,
	const std::string &compile_command,
	const std::string &run_command = run_path,
	const fs::path &err_log = Logging::tmp_log_path
	)
{
	std::string src_path = src.string();
	std::string log_ending = " 2> " + err_log.string();

#ifdef _WIN32
	std::replace(src_path.begin(), src_path.end(), '\\', '/');  // Useful for `wsl'
#endif

	const std::string compile_str
		= compile_command + " \"" + src_path + "\"" + log_ending;
	if (system(compile_str.c_str()))  // If compilation failed...
	{
		// Check if compilation was supposed to fail
		return src_path.find('e') != std::string::npos;
	}
	else
	{
		// Check if the compiled app executes successfully
		const std::string run_str = run_command + log_ending;
		return !system(run_str.c_str());
	}
}

} // namespace Testing


namespace Logging
{

static const fs::path log_path = fs::path("tests.log");
static const fs::path tmp_log_path = fs::path("tmp.log");

class Logger
{
	std::ofstream log_file { log_path };
	std::ifstream tmp_log_file { tmp_log_path };

	long long int succeeded = 0;
	long long int failed = 0;

	fs::path cur_dir;
	fs::path cur_file;
	std::string cur_compiler;

public:

	void dir_entered(const fs::path &dir)
	{
		cur_dir = dir;
		// TODO
	}

	void file_opened(const fs::path &file)
	{
		cur_file = file;
		// TODO
	}

	void compiler_considered(const std::string &command)
	{
		cur_compiler = command;
		// TODO
	}

	void log_test(const bool &res)
	{
		// TODO
		++(res ? succeeded : failed);
	}

	bool overall_report()
	{
		// TODO
		std::cout << "Succeeded: " << succeeded << std::endl
			<< "Failed: " << failed << std::endl;
		return /*(bool)*/ failed;
	}

	~Logger()
	{
		fs::remove(tmp_log_path);
	}
} log;

} // namespace Logging


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
	using Logging::log;

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
				log.compiler_considered(compiler);

				log.log_test(Testing::perform_test(file, compiler));
			}
		}
	}

	return log.overall_report();
}
