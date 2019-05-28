#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
	std::vector<std::string> str_arr;
	
	std::map<string,int> map_str;
	std::string tmp;
	while(std::cin >> tmp) {
		str_arr.push_back(tmp);
	}

	for (int i = 0; i < str_arr.size(); i++) {
		map_str.insert(make_pair(str_arr[i],
	}

	std::cout << str_arr.size() << std::endl;
}

