#include "deco.h"

using namespace std;
using std::vector;
using std::string;


string::size_type width(const vector<string>& v) 
{
    string::size_type maxlen = 0;

    for(vector<string>::size_type i = 0; i != v.size(); i++) 
        maxlen = max(maxlen, v[i].size());

    return maxlen;
}

vector<string> frame(const vector<string>& v) 
{
    vector<string> ret;

    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // 상단 테두리 추가 
    
    ret.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}


vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    // 위쪽 문자열 복사
    vector<string> ret = top;

    /*
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) 
        ret.push_back(*it);
    */
    // library를 이용해서 더 간단하게 구현 가능
    ret.insert(ret.end(),bottom.begin(),bottom.end());
    return ret;
}


vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    // 상단 기준으로 맞추기로 함. category.. 내가 rule을 정함 
    
    vector<string> ret;

    // 두문자 사이에 공백을 남김

    string::size_type width1 = width(left) + 1; // 왼쪽 문자열에서 가장 긴걸 기준으로 뽑고 거기에 공백을 남길 한자리 추가

    vector<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size()) {
    
        string s;

        if (i != left.size()) 
            s = left[i++];
        
        s += string(width1 - s.size(), ' '); // 남는 부분 공백으로 채우기 
   
       if (j != right.size())
          s += right[j++];  
        
       ret.push_back(s);
    }

    return ret;
}
