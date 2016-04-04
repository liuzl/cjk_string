#ifndef CN_STRING_HPP
#define CN_STRING_HPP
#include <string>
#include <iostream>

namespace webcpp {
	class cn_string;
	typedef cn_string cjk_string;

	class cn_string {
	public:
		cn_string(size_t charset_t = cn_string::utf8_t);
		cn_string(const cn_string& orig, size_t charset_t = cn_string::utf8_t);
		cn_string(const std::string& orig, size_t charset_t = cn_string::utf8_t);
		cn_string(const char* orig, size_t charset_t = cn_string::utf8_t);
		cn_string& operator=(const cn_string& str);
		cn_string& operator=(const std::string& str);
		cn_string& operator=(const char* str);
		virtual ~cn_string();
		std::string operator[](size_t p)const;
		cn_string& replace(size_t p, size_t len, const cn_string& str);
		cn_string& replace(size_t p, size_t len, const std::string& str);
		cn_string& replace(size_t p, size_t len, const char* str);
		cn_string substr(size_t p, size_t len)const;
		size_t size()const;
		cn_string& append(const cn_string& str);
		cn_string& insert(size_t p, const cn_string& str);
		cn_string& erase(size_t p, size_t len);
		void clear();
		bool empty();
		size_t find(const std::string str);
		size_t find(const char* str);
		size_t find(const cn_string& str);
		void swap(cn_string& str);
		cn_string& operator+=(const cn_string& str);
		cn_string& operator-=(const cn_string& str);
		friend std::ostream& operator<<(std::ostream& out, const cn_string& str);
		friend std::istream& operator>>(std::istream& in, cn_string& str);
		friend bool operator==(const cn_string& lStr, const cn_string& rStr);
		friend const cn_string operator+(const cn_string& lStr, const cn_string& rStr);
		friend const cn_string operator-(const cn_string& lStr, const cn_string& rStr);
	private:
		cn_string& replacePrintOrCntrl();
		bool isPrintOrCntrl(char c);
	private:
		std::string data;
		size_t charset_t;
	public:
		static const size_t gbk_t, utf8_t, utf16_t;
	};

}
#endif /* CN_STRING_HPP */

