#include <iostream>
#include "cn_string.hpp"

void print(const webcpp::cn_string & str);

int main(int argc, char** argv) {
	std::cout << "任意英文、中文、韩文、日文文本." << std::endl;
	webcpp::cn_string cStr = "没有付出就没有收获。";
	print(cStr);

	webcpp::cn_string jStr = "世界が终るまでは、离れることも无い";
	print(jStr);

	webcpp::cn_string kStr = "고통이 없으면 얻는 것도 없다.";
	print(kStr);

	webcpp::cjk_string eStr = "In love folly is always sweet.";
	print(eStr);

	webcpp::cn_string mixStr = cStr;
	mixStr.append(jStr).append(kStr).append(eStr);
	print(mixStr);

	webcpp::cn_string oldStr("付出"), newStr("替换");
	size_t p = cStr.find(oldStr);

	if (p != std::string::npos) {
		print(cStr.replace(p, oldStr.size(), newStr));
	} else {
		std::cout << "Not Found" << std::endl;
	}

	mixStr -= kStr;
	mixStr -= jStr;
	mixStr -= eStr;
	mixStr.replace(p, oldStr.size(), newStr);
	std::cout << (mixStr == cStr) << std::endl;
	print(mixStr);
	mixStr.swap(kStr);
	print(mixStr);
	print(kStr);
	return 0;
}

void print(const webcpp::cn_string & str) {
	std::cout << str << std::endl;
	for (size_t i = 0; i < str.size(); ++i) {
		std::cout << "str[" << i << "]=" << str[i] << std::endl;
	}
	std::cout << "size:" << str.size() << std::endl;
}
