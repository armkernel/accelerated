#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;
using std::list;
using std::transform;
using std::accumulate;

double grade(double midterm, double finalterm, double homework) 
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const std::vector<double>& hw) 
{
    if (hw.size() == 0) 
        throw domain_error("Student has done no homework");

    return grade(midterm,finalterm, median(hw));
}
double grade(const Student_info& s) 
{
    return grade(s.midterm, s.finalterm, s.homework);
}


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& student)
{
    // 반복자를 사용하면서 vector의 index 의존성을 제거함. 
    // 좀 더 효율적으로 요소를 제거하는 방법을 고안해보자

    // 벡터는 지원하지만 리스트는 지원하지 않는건 index 한가지다. 
    
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = student.begin();

    while(iter != student.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = student.erase(iter);
        }
        else 
            ++iter;
    }    

    return fail;
}

double grade_aux(const Student_info& s) 
{
    try {
        return grade(s);
    } 
    catch (domain_error) {
        return grade(s.midterm, s.finalterm, 0);
    }
}

double median_analysis(const std::vector<Student_info>& students) 
{
    vector<double> grades;
    // grade가 overloading되어 어떤 grade를 선택해야하는지 알 수 없다.
    // 또한 과제가 0점 일경우 예외 처리를 해야하는데 그 부분을 할 수 없다
    // 그 부분이 가능하도록 만드는 grade_aux함수를 만들어줘야한다 
    // transform(students.begin(), students.end(), back_inserter(grades), grade);
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
   
    // libc++abi.dylib: terminating with uncaught exception of type std::domain_error: median of an empty vector
    // 예외처리가 안되서 나는 에러 
    // catch 한후 처리하도록 해야함  
    try{
        return median(grades);
    } 
    catch (domain_error) {
        return 0.0;
    }
}

double average(const vector<double>& v)
{
    // #include <numeric> 함수에 있음
    // 3번째 인자로 0이 아니라 0.0 으로 주는게 중요하다. 그래야 double형으로 암시적 변환이 되며
    // 그 값을 기준으로 평균을 냄 
    // accumulate는 summary함수이다 
    return accumulate(v.begin(), v.end(), 0.0) / v.size(); 
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.finalterm, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    try {
        return median(grades);
    }
    catch (domain_error) {
        return 0.0;
    }
}

// 함수 이름이 optimistic인 이유는 과제를 하지 않았는데, 한 부분에 대해서만 
// 중앙 값을 매기겠다는 이유에서.

double optimistic_median(const Student_info& s) 
{
    vector<double> nonzero;
    // 제거.. 
    // 해당 값을 제거하고 복사하라. 해당값은 4번째 인자로 주어짐. 
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty()) {
        return grade(s.midterm, s.finalterm, 0);
    } else {
        return grade(s.midterm, s.finalterm, median(nonzero));
    }
}

double optimistic_median_analysis(const std::vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    try{
        return median(grades);
    }
    catch (domain_error) {
        return 0.0;
    }
}


void write_analysis(std::ostream& out, const std::string& name,
        double analysis(const std::vector<Student_info>&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did)
        << ",median(didnt) = " << analysis(didnt) << std::endl;
}
