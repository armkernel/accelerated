#include <iostream>

using namespace std;

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
    // 일반함수 equal() 반대인 두 문자열이 같은 값인지 판별하기 위해 비교하는 함수
    // 인수로 전달되는 첫 2개의 반복자는 첫번째 순차열의 범위를 나타냄 
    // 마지막 인수는 두번쨰 순차열의 시작점을 나타냄
    // 지금은 회문을 표현해야하니까. 끝네서부터 나타내면됨.

}

// 회문을 검사하는 프로그램
// c로 짯다면 엄청 길어졌을 것인데 라이브러리를 이용하니까 쉽게 적용됨 

int main() 
{
    string str;

    cin >> str;

    cout << is_palindrome(str) << endl;
}
