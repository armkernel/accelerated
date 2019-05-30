#include <iostream>
#include <cctype> // c에서 사용하는 문법들을 상속받아 구현 
#include <vector>

//  i       j
//	|       |
// ----------------------
// Given the existence as
// ----------------------

std::vector<std::string> split (const std::string& s)
{
	std::vector<std::string> ret;

	typedef std::string::size_type string_sz;
	
	string_sz i = 0;

	while (i != s.size()) {

		// 선행하는 공백들을 무시
		// 끝이 아니고 공백이 아니라는 것은 단어의 시작 부이다. 따라서 한칸씩 세감
		// 단어의 시작부를 찾는 것 
		while (i != s.size() && isspace(s[i])) ++i; 

		string_sz j = i; // 단어의 끝까지 찾을 변수 설정

		while (j != s.size() && !isspace(s[j])) ++j;

		if (i != j) {
			// i에서 부터 j - i개의 문자들을 s에 복사 
			ret.push_back(s.substr(i,j-i)); 
			i = j;
		}
	}

	return ret; 
} 


int main() 
{
	// split 함수 테스트 
	
	std::string s;

	#if 0
	while (std::cin >> s) 
		std::cout << s << std::endl;
	#endif

	while (getline(std::cin, s)) {
		std::vector<std::string> v = split(s); 
		
		// 백터 v에 저장한 단어를 각각 출력 

		for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) 
			std::cout << v[i] << std::endl;
	}
	return 0;
}
