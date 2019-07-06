#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, finalterm;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

// 모든 과제를 제출 했는가를 검사하는 함수 
bool did_all_hw(const Student_info&);


#endif
