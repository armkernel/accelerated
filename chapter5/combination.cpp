#include <iostream>
#include <string>
#include <vector>


void read (std::vector<std::string>& vc) {
	
	std::string tmp_str;	

	while(std::cin >> tmp_str) {
		vc.push_back(tmp_str);
	}
}


int main () {

	std::vector<std::string> vc;	
	read(vc);

	typedef std::vector<std::string>::size_type vc_sz;
	vc_sz i = 0;

	for (; i != vc.size(); i++) {
		std::cout << vc[i] << std::endl;
	}
}

