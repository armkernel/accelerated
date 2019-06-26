#include <stdexcept>
#include <vector>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;


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
   // 메모리 공간을 유지해야한다는 단점이 존재함. 
   // 충분한 메모리 공간이 필요.. 
   // 두개의 정보를 유지하지 말고 요소를 제거하는 방향으로 생각해보자.
   // 즉, fail vector만 유지하고 student vector에서 요소를 제거하는 방향 
   // => 요소를 제거하는 overhead가 발생함
   //   1. 알고리즘에 더 적합한 데이터 구조를 만듦
   //   2. 오버헤드를 피하는 더 똑똑한 알고리즘을 사용 
   vector<Student_info> fail; 
    
   typedef vector<Student_info>::size_type vec_sz;

   // 불변성 : students 백터의 [0, i) 범위에 있는 요소들은 과목을 통과한 학생들의 정보.
   vec_sz i = 0; 
   while (i != student.size()) {
       if (fgrade(student[i])) {
           fail.push_back(student[i]);
           student.erase(student.begin() + i);
           // erase는 container에서 제공해줌.
           // 즉, 요소별로 제공해주는 것이 아니다. 인덱스로 접근해서 하나씩 지우는 게 아니라
           // 컨테이너 자체에서 제공해주는 것이며, 하나의 요소를 제거하고 다음 요소를 가리키게 한 후
           // 모든 요소를 다 옮김.
       } 
       else
          ++i; 

   }
   
   return fail;
}

