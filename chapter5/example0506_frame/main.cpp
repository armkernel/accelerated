#include <iostream>
#include <string>

#include "deco.h"

using namespace std;

// 백터타입은 모든 라이브러리 컨테이너 중 가장 강력한 반복자인 임의 접근 반복자 제공 

int main()
{
    vector<string> tmp;

    string s;

    while(cin >> s) 
        tmp.push_back(s);

    vector<string> ret = frame(tmp);

    for (vector<string>::size_type i = 0; i != ret.size(); i++) {
        cout << ret[i] << endl;
    }

    vector<string> tmp_ret = vcat(ret,ret);


    for (vector<string>::size_type i = 0; i != tmp_ret.size(); i++) {
        cout << tmp_ret[i] << endl;
    }

    vector<string> tmp_hcat_ret = hcat(ret,ret);

    for (vector<string>::size_type i = 0; i != tmp_hcat_ret.size(); i++) {
        cout << tmp_hcat_ret[i] << endl;
    }
    

    return 0;
}
