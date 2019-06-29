#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

// 과락 여부 
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

#endif
