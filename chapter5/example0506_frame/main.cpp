#include <iostream>
#include <string>

#include "deco.h"

using namespace std;


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
    return 0;
}
