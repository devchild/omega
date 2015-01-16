/*
 * File:   file_system.hh
 * Author: mario
 *
 * Created on June 24, 2014, 11:11 PM
 */

#ifndef FILESYSTEM_HH
#define	FILESYSTEM_HH

#include <string>
#include <list>

#include <sys/types.h>
#include <sys/stat.h>

struct stat info;

class SourceFile {
public:
	SourceFile(std::string path) {
		this->m_path = path;
		if (file_exists(path)) {
			add_import_file_source(get_directory(path));
		}
	}

	void add_import_file_source(const std::string& dir) {
		if (directory_exists(dir)) {
			m_import_file_source.push_back(dir);
		}
	}

	std::list<std::string> import(const std::string& search) {
		std::list<std::string> ret;

		for (auto x : m_import_file_source) {
			std::string potential_file = x + "/" + search;
			if (file_exists(potential_file)) {
				ret.push_back(potential_file);
			}
		}

		return ret;
	}

	static inline std::string get_file_name(const std::string& path) {
		auto splitted = split(path);
		return splitted.back();
	}

	static inline std::string get_directory(const std::string& path) {
		std::string ret = "";
		auto splitted = split(path);

		int i = 0;
		for (std::list<std::string>::const_iterator iterator = splitted.begin(),
				end = splitted.end(); iterator != end; ++iterator) {
			if (i < splitted.size() - 1)
			{
				if (i > 0)
					ret += "/";
				ret += *iterator;
				i++;
			}
		}
		return ret;
	}

	static bool directory_exists(const std::string& dir) {
		bool ret = false;
		if (stat(dir.c_str(), &info ) == 0 && info.st_mode & S_IFDIR)  // S_ISDIR() doesn't exist on my windows
			ret = true;
		return ret;
	}

	static inline bool file_exists(const std::string& path) {
		bool ret = false;
		std::ifstream f(path.c_str());
		if (f.good()) {
			f.close();
			ret = true;
		}
		return ret;
	}

private:
	std::string m_path;
	std::list<std::string> m_import_file_source;

	static bool starts_with(const std::string& s1, const std::string& s2) {
		return s2.size() <= s1.size() && s1.compare(0, s2.size(), s2) == 0;
	}

	static inline std::list<std::string> split(const std::string& path) {
		std::list<std::string> ret;
		char delim = '/';
		std::stringstream ss(path);
		std::string item;
		while (std::getline(ss, item, delim)) {
			ret.push_back(item);
		}
		return ret;
	}
};

#endif	/* FILESYSTEM_HH */

