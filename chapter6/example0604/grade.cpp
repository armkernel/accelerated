#include <stdexcept>
#include <vector>
#include <list>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;
using std::list;

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

double median_analysis(const std::vector<Student_info>& students) 
{
    vector<double> grades;
    // grade가 overloading되어 어떤 grade를 선택해야하는지 알 수 없다.
    // 또한 과제가 0점 일경우 예외 처리를 해야하는데 그 부분을 할 수 없다
    // 그 부분이 가능하도록 만드는 grade_aux함수를 만들어줘야한다 
    transform(students.begin(), students.end(), back_inserter(grades), grade);
    return median(grades);
}
