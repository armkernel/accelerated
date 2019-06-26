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
   vector<Student_info> pass, fail; 
    
   typedef vector<Student_info>::size_type vec_sz;

   for (vec_sz i = 0; i != student.size(); ++i) {
       if (fgrade(student[i])){
           fail.push_back(student[i]);
           std::cout << "sdk"<< student[i].name << std::endl;
       }
       else
           pass.push_back(student[i]);
   }

   student = pass;
   return fail;
}

