#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h 헤더 파일

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, finalTerm;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&); 

// 패키지로 만들떄는 관련된 함수들만 엮는 것이 좋다. 즉, Student_info에 관련된 함수만 묶을 것.

#endif
