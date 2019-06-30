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

// 참조로 전달받은 값을 새로운 메모리에 할당하는 것이 아니다. 즉, 메모리 효율성을 위해 const &로 많이 받음 
// 값을 바꾸지 않는다는 것을 알때는 const를 사용!
vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_sz;

    // 초기화 해주지 않으면 오류남. segmentation fault로 접근하지 못할 영역에 접근했다고 나옴. 예상으로는 null ptr로 초기화하는 것이 아닐까 의심됨.
    string_sz i = 0 ;
    while (i != s.size()) {
       
        // 공백이 아닌 문자열 까지 돌아간다. 
        while( i != s.size() && isspace(s[i])) {
            ++i;
        }

        // 공백아 아닌 문자의 위치를 j에 추가함
        string_sz j = i;

        // 공백이 아닌 문자가 공백이 나올때 까지 순회 
        while( j != s.size() && !isspace(s[j])) {
            j++;
        }

        // 다 돌고 나서 현재 내 위치가 i의 위치랑 같은지를 비교한다. 
        // 같다면? 문자열을 다 돈 것이 때문에 복사할 필요가 없어. 다르다면 도중에 찾은것이기 때문에 복사 
        if (i != j) {
            ret.push_back(s.substr(i,j-1));
            // 문자열 복사.. 
            i = j;
        } 
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
