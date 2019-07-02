#include <iostream>
#include <vector>
// url 찾아내는 함수를 구현할 것이다.
// 여기서 정하는 url의 기준은 ://를 기준으로 앞부분은 프로토콜의 이름 뒷 부분은 리소스 이름으로 구성된다고 가정함

////////////// url_end함수 부터 다시 볼 것 //////////////////

using namespace std;

bool not_url_char(char c)
{
    //url에 들어갈 수 있는 알파벳과 숫자 이외의 문자
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    //c가 url에 들어갈 수 있는 문자인지 확인하면 음수를 반환 
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
    // find_if와 다른 find함수는 서술함수를 호출하는 것이 아닌 특정 값을 찾는 함수이다.
    
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
    // 서술함수를 넣어줘야함
    // false면 넘어가고 ture면 멈춰 
    // :// 아니면 false를 반환하도록함 
}


// url_beg 함수가 복잡한 이유 
// url의 문자인 ://를 포함하지만 url이 아닌 경우가 존재한다. 
// url 프로토콜의 앞뒤에 유효한 문자가 하나이상 포함될경우 url로 인식하도록 한다. 

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) 
{
    static const string sep = "://"; // 구분자 (delimiter)
    typedef string::const_iterator iter;

    // i는 구분기호를 발견한 위치를 표시 
    
    iter i = b;
    while ( (i = search(i, e, sep.begin(), sep.end())) != e ) {
        // ://를 찾을 경우 여기로 들어옴 
        if (i != b && i + sep.size() != e) {
            iter beg = i;

            while (beg != b && isalpha(beg[-1]))
                --beg;

            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        i += sep.size();
    }

    return e;
}



vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;

    iter b = s.begin(), e = s.end();

    // 전달받은 문자열을 전체적으로 탐색한다는 의미
    while (b != e) {
        
        // ://의 앞쪽에서 하나 이상의 문자를 탐색
        b = url_beg(b,e);

        if ( b != e ) {
            // 해당 문자를 찾았다면 url의 나머지 부분을 탐색 
            iter after = url_end(b,e);

            // url 저장 
            ret.push_back(string(b,after));

            // 인수로 전달받은 문자열에서 또 다른 url을 찾기위해 b 증가 
            b = after;
        }
    }

    return ret;
}

int main(){

    string tmp = "https://j";
    vector<string> ret = find_urls(tmp);

    for(vector<string>::size_type i = 0; i != ret.size(); i++) {
        cout << ret[i] << endl;
    }
    
}
