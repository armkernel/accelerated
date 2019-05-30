#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void read (std::vector<std::string>& vc) {
	
	std::string tmp_str;	

	while(std::cin >> tmp_str) {
		vc.push_back(tmp_str);
	}
}

// const & 변화 없이 메모리 낭비 줄이겠다는 의미 
std::string::size_type width (const std::vector<std::string>& str_vc) {
	
	std::string::size_type maxlen = 0;

	for (std::vector<std::string>::size_type i = 0 ; i != str_vc.size(); i++ ){
		maxlen = std::max(maxlen, str_vc[i].size());
	}

	return maxlen;
}

std::vector<std::string> frame (const std::vector<std::string>& str_vc) {
	
	std::vector<std::string> tmp_vec;

	std::string::size_type maxlen = width(str_vc); 
	std::string border(maxlen + 4, '*'); // 4 는 공백 * 이다. 

	tmp_vec.push_back(border);
	
	for (std::vector<std::string>::size_type i = 0; i != str_vc.size(); i++) {
		tmp_vec.push_back("* " + str_vc[i] + std::string(maxlen - str_vc[i].size(), ' ') + " *"); 	
	}

	tmp_vec.push_back(border);

	return tmp_vec;

}

int main () {

	std::vector<std::string> vc,ret;	
	read(vc);

	typedef std::vector<std::string>::size_type vc_sz;
	vc_sz i = 0;

	ret = frame(vc);
	for (; i != ret.size(); i++) {
		std::cout << ret[i] << std::endl;
	}
}

