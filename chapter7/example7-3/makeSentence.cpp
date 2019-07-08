#include <iostream>
#include <vector>

#include "split.h"

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef vecotr<string, Rule_collection> Grammer;

// 문법 컬렉션 
// Grammer를 만들어 반환한다. 
Grammer read_grammer(istream in)
{
    Grammer ret;
    string line;

    while (getline(in, line)) {
        // 입력 데이터를 단어로 나눔
        vector<string> entry = split(line); 
        if (!entry.empty()) 
            // 카테고리 및 연관된 규칙을 맵에 저장 
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
            // 첫 번쨰 entry 같은 경우 카테고리 일거니 
            // 그 이후  string의 배열 push_back함. vector<string>( iterator.beign +1 , iterator.end  ) --> iterator 요소를 가지고 배열을 하나씩 만드는데.. 그 배열의 정보를 rule_collcetion에 저장함 
    }
    return ret;
}   

// 임의 문장을 만들 차례
