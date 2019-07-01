/*
 *  split 함수 바꿈. 
 *  copy 함수를 이용함. copy 함수(begin,end,out ) // out-> iterator
 *  copy함수를 이러한 방식으로 설계한 이유 -> 요소복사와 컨테이너 확장 개념을 분리하면 프로그래머는 자신에게 가장 알맞는 연산을 사용할 
 *  수 있음.
 *
 * */


#include <iostream>
#include <vector>
#include <cctype> // c style의 기능을 cpp에서 상속 받은 것.

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin(); //begin 은 반복자를 반환함

    while (i != str.end()) {
        // 선행 공백 무시
        i = find_if(i, str.end(), not_space);

        // 단어의 끝을 찾아야해
        iter j = find_if(i, str.end(), space);

        /*
         * find_if 함수는 첫 두 인수가 순차열을 나타내는 반복자를 가지고 있음.
         * 세 번쨰 인수는 서술함수를 인자로 전달함. 
         * 서술 함수는 참과 거짓을 반환하는 함수 
         * find_if는 서술함수가 참을 반환하면 멈춘다.
         * find_if는 해당하는 값이 없으면 두번째 인자인 str.end()를 반환함. 따라서, i를 굳이 계속 검사할 필요가 없다. 끝인지 아닌지..
         * */

        //[i,j] 범위의 문자복사 
        if ( i != str.end() ) {
            // 이전의 split에서는 substr을 써서 그 문자를 잘라내서 백터에 저장함
            // 하지만 이제 반복자를 이용함 (즉, ㅅ인덱스를 사용하지 않는다 따라서, substr 사용 불가)
            // 반복자를 복사하기 위해서 string을 임시객체로 만들어서 넣어줘야함.:
            ret.push_back(string(i,j)); //string의 임시객체를 만듬 이후,,  반환
        }

        i = j;
    }

    return ret;
}




int main() 
{
    string s;

    while( getline(cin, s) ) {
        vector<string> v = split(s);

        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }
}
