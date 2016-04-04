#include <cctype>
#include "cn_string.hpp"

namespace webcpp {

	const size_t cn_string::gbk_t = 2, cn_string::utf8_t = 3, cn_string::utf16_t = 4;

	cn_string::cn_string(size_t charset_t) : data(""), charset_t(charset_t) {

	}

	cn_string::cn_string(const cn_string& orig, size_t charset_t) : data(orig.data), charset_t(charset_t) {

	}

	cn_string::cn_string(const std::string& orig, size_t charset_t) : data(orig), charset_t(charset_t) {
		this->replacePrintOrCntrl();
	}

	cn_string::cn_string(const char* orig, size_t charset_t) : data(orig), charset_t(charset_t) {
		this->replacePrintOrCntrl();

	}

	cn_string::~cn_string() {
	}

	cn_string& cn_string::operator=(const cn_string& str) {
		this->data = str.data;
		return *this;
	}

	cn_string& cn_string::operator=(const std::string& str) {
		this->data = str;
		return this->replacePrintOrCntrl();
	}

	cn_string& cn_string::operator=(const char* str) {
		this->data = str;
		return this->replacePrintOrCntrl();
	}

	std::string cn_string::operator[](size_t p)const {
		std::string tmp = this->data.substr(p * this->charset_t, this->charset_t);
		if (tmp[0] == ' ') {
			tmp.erase(0, 2);
		}
		return tmp;
	}

	cn_string& cn_string::replace(size_t p, size_t len, const cn_string& str) {
		return this->erase(p, len).insert(p, str);
	}

	cn_string& cn_string::replace(size_t p, size_t len, const std::string& str) {
		return this->erase(p, len).insert(p, str);
	}

	cn_string& cn_string::replace(size_t p, size_t len, const char* str) {
		return this->erase(p, len).insert(p, str);
	}

	cn_string cn_string::substr(size_t p, size_t len)const {
		cn_string str;
		str.data.append(this->data.substr(p * this->charset_t, len * this->charset_t));
		return str;
	}

	size_t cn_string::size()const {
		return this->data.size() / this->charset_t;
	}

	cn_string& cn_string::append(const cn_string& str) {
		this->data.append(str.data);
		return *this;
	}

	cn_string& cn_string::insert(size_t p, const cn_string& str) {
		this->data.insert(p * this->charset_t, str.data);
		return *this;
	}

	cn_string& cn_string::erase(size_t p, size_t len) {
		this->data.erase(p * this->charset_t, len * this->charset_t);
		return *this;
	}

	void cn_string::clear() {
		this->data.clear();
	}

	bool cn_string::empty() {
		return this->data.empty();
	}

	size_t cn_string::find(const std::string str) {
		size_t p = this->data.find(str);
		if (p == std::string::npos) {
			return std::string::npos;
		}
		return p / this->charset_t;
	}

	size_t cn_string::find(const char* str) {
		size_t p = this->data.find(str);
		if (p == std::string::npos) {
			return std::string::npos;
		}
		return p / this->charset_t;
	}

	size_t cn_string::find(const cn_string& str) {
		size_t p = this->data.find(str.data);
		if (p == std::string::npos) {
			return std::string::npos;
		}
		return p / this->charset_t;
	}

	cn_string& cn_string::replacePrintOrCntrl() {
		std::string space(this->charset_t - 1, ' ');
		for (size_t i = 0; i<this->data.size(); ++i) {
			if (this->isPrintOrCntrl(this->data[i])) {
				this->data.insert(i, space);
				i += this->charset_t - 1;
			}
		}
		return *this;
	}

	bool cn_string::isPrintOrCntrl(char c) {
		return std::isprint(c) || std::iscntrl(c);
	}

	std::ostream& operator<<(std::ostream& out, const cn_string& str) {
		size_t len = str.size();
		for (size_t i = 0; i < len; ++i) {
			out << str[i];
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, cn_string& str) {
		std::string tmp;
		in >> tmp;
		str = tmp;
		return in;
	}

	void cn_string::swap(cn_string& str) {
		this->data.swap(str.data);
	}

	cn_string& cn_string::operator+=(const cn_string& str) {
		return this->append(str);
	}

	cn_string& cn_string::operator-=(const cn_string& str) {
		size_t p = this->find(str);
		if (p != std::string::npos) {
			return this->erase(p, str.size());
		}
		return *this;
	}

	bool operator==(const cn_string& lStr, const cn_string& rStr) {
		return lStr.data == rStr.data;
	}

	const cn_string operator+(const cn_string& lStr, const cn_string& rStr) {
		cn_string result;
		result.data = lStr.data + rStr.data;
		return result;
	}

	const cn_string operator-(const cn_string& lStr, const cn_string& rStr) {
		cn_string result(lStr);
		size_t p = result.find(rStr);
		if (p != std::string::npos) {
			return result.erase(p, rStr.size());
		}
		return result;
	}

}