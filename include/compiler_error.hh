/* 
 * File:   CompilerError.hh
 * Author: mario
 *
 * Created on June 23, 2014, 10:55 PM
 */

#ifndef COMPILERERROR_HH
#define	COMPILERERROR_HH

#include <string>
#include <sstream>
#include <ostream>

namespace mlang {
class CompilerError;
typedef mlang::CompilerError* p_CompilerError;
#define new_CompilerError(...) new mlang::CompilerError (##__VA_ARGS__)

class Location {
	std::string m_file_name;

	int m_timestamp;
	int m_first_line;
	int m_first_column;
	int m_last_line;
	int m_last_column;
public:
	Location() {
		this->m_file_name = "";
		this->m_timestamp = -1;
		this->m_first_line = -1;
		this->m_first_column = -1;
		this->m_last_line = -1;
		this->m_last_column = -1;
	}

	inline void file_name(std::string value) {
		this->m_file_name = value;
	}

	inline std::string file_name() {
		return this->m_file_name;
	}

	inline void first_line(int value) {
		this->m_first_line = value;
	}

	inline void first_column(int value) {
		this->m_first_column = value;
	}

	inline void last_line(int value) {
		this->m_last_line = value;
	}

	inline void last_column(int value) {
		this->m_last_column = value;
	}

	inline int first_line() {
		return this->m_first_line;
	}

	inline int first_column() {
		return this->m_first_column;
	}

	inline int last_line() {
		return this->m_last_line;
	}

	inline int last_column() {
		return this->m_last_column;
	}

	inline std::string to_string() {
		std::ostringstream ret;
		ret << this->file_name() << ": ";

		if (((m_last_line > 0) | (m_last_column > 0))
				& ((m_last_line != m_first_line)
						| ((m_last_column - m_first_column) > 1))) {
			ret << "(" << m_first_line << "," << m_first_column << " - "
					<< m_last_line << "," << m_last_column << ")";
		} else if (m_first_line >= 0 && m_first_column >= 0) {
			ret << "(" << m_first_line << "," << m_first_column << ")";
		} else {
			ret << "(-,-)";
		}

		return ret.str();
	}
};

class CompilerError {
public:
	CompilerError();
	CompilerError(const CompilerError& orig);
	virtual ~CompilerError();
	void message(std::string message);
	std::string message();

	void location(Location* location);
	Location* location();

	bool has_location();

private:
	bool m_has_location;
	std::string m_message;
	Location* m_location;
};
}

#endif	/* COMPILERERROR_HH */

