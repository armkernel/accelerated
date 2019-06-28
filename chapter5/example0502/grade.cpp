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
   /*
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
   }*/

  
   vector<Student_info>::iterator iter = student.begin(); // 만약 iterator가 +연산을 지원하지 않는다면 erase에서 오류남. 
   // 컨테이너의 반복자를 사용하면, 내가 순차적으로 접근할 수 있지만 임의로 접근하는 것을 막을 수 있다.
   // 즉, +연산을 막아버리면? 구현을 안하면 접근을 할 수없다.
   // 다만, index접근을 하게 된다면 문제가됨.
   
   while (iter != student.end()) 
   {
       if(fgrade(*iter)) {
           fail.push_back(*iter);
           iter = student.erase(iter);

           // 이 부분이 중요하다. 
           // iter 변수에 erase를 지우고 반환하는 건 무슨 의미일까? 
           // 반복자가 제거하고 나면 제거된 이후의 요소가 다 당겨짐. 
           // 그렇다면 반복자가 무효화 됨. 다시 돌아야지?
           // 어떻게 기억해? 
           // 참조 되던 놈이 사라지니까.. 이걸 찾을 방법이 없는데. 반환값으로 이후 참조되는 놈을 반환함.
           // 그래서 else문에서 증가시켜가면서 찾을 수 있음
       }
       else {
           iter++;
       }
   }  


   return fail;
}

