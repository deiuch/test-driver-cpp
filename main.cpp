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

bool perform_test(const fs::path &src, const std::string &compiler, const std::string &run_path)
{
	std::string src_path = src.string();

#ifdef _WIN32
	std::replace(src_path.begin(), src_path.end(), '\\', '/');  // Useful for `wsl'
#endif

	const std::string command = compiler + " \"" + src_path + "\"";
	if (system((command).c_str()))  // If compilation failed...
	{
		// Check if compilation was supposed to fail
		return src_path.find('e') != std::string::npos;
	}
	else
	{
		// Check if the compiled app executes successfully
		return !system(run_path.c_str());
	}
}

inline bool is_cpp_extension(const std::string &str)
{
	static const std::vector<std::string> CPP_EXTS
		= { ".C", ".cc", ".cpp", ".cxx", ".c++" };

	return std::find(CPP_EXTS.begin(), CPP_EXTS.end(), str) != CPP_EXTS.end();
}

bool is_cpp_file(const fs::directory_entry &file)
{
	return !fs::is_directory(file) &&
		file.path().has_extension() &&
		is_cpp_extension(file.path().extension().string());
}

int main(const int argc, const char * const * const argv) {
	static const std::string log_path = "tests.log";
	static const fs::path test_dir = fs::path("tests");
	static const std::vector<std::string> compiler_list = { "g++", "clang++" };
	static const std::string run_path = "./a.out";

	std::ofstream log_file;
	log_file.open(log_path, std::ios_base::app);

	for (const auto &dir : fs::directory_iterator(test_dir))
	{

		if (!fs::is_directory(dir)) continue;

		// log_file << dir;

		for (const auto &file : fs::directory_iterator(dir.path()))
		{
			if (!is_cpp_file(file)) continue;

			for (const auto &compiler : compiler_list)
			{
				bool res = perform_test(file.path(), compiler, run_path);

				// log_file << res;
			}
		}
	}

	log_file.close();

	return 0;
}
