#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

#include "split.h"

using namespace std;

using std::vector;

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;


int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to narand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}





// 문법 컬렉션 
// Grammer를 만들어 반환한다. 
Grammer read_grammer(istream& in)
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
// 룰을 찾고 문법 테이블을 만듬

bool bracketed(const string& s) 
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}


// 임의 문장을 만들 차례
// 카테고리와 일반 문자를 구별해야함 
void gen_aux(const Grammer& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    }
    else {
        // word와 연관 규칙을 찾음
        Grammer::const_iterator it = g.find(word); // sentence 관련 category가 있는지 확인 해봄 
        // key 값을 기준으로 find함 
        
        if (it == g.end()) {
            throw logic_error("empty rule..!");
        }

        // sentence category에 속하는 rule들을 다 가져옴 
        const Rule_collection& c = it -> second;

        // 임의로 하나 선택 
        const Rule& r = c[nrand(c.size())];

        // 선택한 규칙을 가지고 재귀적 확장 
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
           gen_aux(g, *i, ret); 
    }

}

// 1. <sentence> 해당 규칙을 찾아야한다. 
// 2. 여러가지 규칙을 조합하여 조각난 결과물을 만듬
vector<string> gen_sentence(const Grammer& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret; 
}


// <sentence> the <noun-phrase> <verb> <location>
// category - <sentence> 
// rule collection - the, <noun-pharse>, <verb>, <location>
// rule 들이 여러개가 될 수 없어 
// <sentence> 일 때 여러개를 가지고 오는거야 

int main() {
    // 문장 생성 
    vector<string> sentence = gen_sentence(read_grammer(cin));

    // 첫 번째 단어 출력 
    vector<string>::const_iterator it = sentence.begin();

    if(!sentence.empty()) {
        cout << *it;
        ++it;
    }

    while (it != sentence.end()) {

        cout << " " << *it;
        ++it;
    }

    cout << endl;

    return 0;
}
