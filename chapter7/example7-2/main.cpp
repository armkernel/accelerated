#include <iostream>
#include <vector>
#include <map>

#include "split.h"

using namespace std;

map<string, vector<int> > xref(istream& in,
        vector<string> find_word(const string&) = split)
{
    string line;
    int line_count = 0;
    map<string, vector<int> > ret;

    //다음 행을 읽어

    while(getline(in, line)) {
        ++line_count;

        vector<string> words = find_word(line);
        //현재 행에 등장한 모든 단어를 저장 
        for (vector<string>::const_iterator it = words.begin(); 
                it != words.end(); it++) {
            cout << "[SDK]" <<*it << endl;
            ret[*it].push_back(line_count);
        }
    }

    return ret;
}

int main() 
{
    // xref함수 호출 시 split관련 함수를 전달하지 않으면 
    // split 함수 즉, default로 저장된 함수가 호출됨 
    map<string, vector<int> >ret = xref(cin); 

    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); it++) {

        // 단어 출력 
        cout << it->first << " occurs on line(s) ";

        // line출력 
        vector<int>::const_iterator line_it = it->second.begin(); // second -> vector<int>::iterator 
        cout << *line_it;
        line_it++;

        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            line_it++;
        }

        // 각 단어별 구분 
        cout << endl;
    }

    return 0;
}
