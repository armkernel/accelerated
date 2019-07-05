#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;

int main()
{
//    vector<Student_info> students;
//  학생을 숙제를 제출한 학생과 하지 않은 학생으로 나눈다.i
    
    vector<Student_info> did, didnt;

    Student_info record;

    string::size_type maxlen = 0;

    while (read(cin, record))
    {
        if (did_all_hw(record)) {
            maxlen = max(maxlen, record.name.size());
            did.push_back(record);
        } else 
            didnt.push_back(record);
    }

    // 두 집ㄱ단에 데이터가 있는지 확인
    // empty 해당 컨테이너가 비어있는지 아닌지를 확인하는 함수 
    // size를 파악해 0개인지 파악하는 것 보다 empty를 사용하는 것이 더 낫다. ㅈ컨테이너 종류에 따라 컨테이너에 정확히
    // 몇개의 요소가 있는지 파악하는 것 보다 컨테이너에 요소가 있는지 확인하는 것이 더 효율적임 
    
    if (did.empty()) {
        cout << "No Student did all the homework" << endl;
        return 1;
    } 

    if (didnt.empty()) {
        cout << " Every student did all the homework! " << endl;
    }

    // 분석 실행
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    /*
    sort(students.begin(),students.end(),compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }
    */
    return 0;
}
