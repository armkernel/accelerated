#include <iostream>
#include <map>

using namespace std;

/*
 * 단어의 빈도를 나타내는 프로그램
 * 단어를 입력받으면서 개별 단어의 빈도를 구하는 프로그램이다.
 * */


int main() 
{
    string s;

    // 각 단어와 빈도를 저장하는 맵 
    // 입력을 읽으면서 각 단어와 빈도를 저장

    map<string, int> counters;

    while(cin >> s)
        ++counters[s];

    for (map<string, int>::const_iterator it = counters.begin();
            it != counters.end(); 
            ++it) {
        cout << it-> first << "\t" << it->second << endl;
    }
    return 0;
}
