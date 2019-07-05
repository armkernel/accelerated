#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

// 과락 여부 
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

// 과제를 하나도 내지 않은 학생과 과제를 전부 제출한 친구와의 점수차이가 얼마나 나지 않거나 잘못하면 역전하는 경우가 발생함
// 이 문제를 해결하기 위해 2가지 방법이 필요함
// 1. 중앙 값 대신 평균값을 사용할것. 학생이 제출하지 않은 과제는 0점으로 처리
// 2. 학생이 실제로 제출한 과제들만 중앙값을 추출함.

// --> 1. 모든 학생의 정보를 읽고 과제를 모두 제출한 학생과 그렇지 않은 학생을 분류
// --> 2. 두 집단에 각각의 성적 산출방식을 적용한 후 집단의 중앙값을 추출 

 
double median_analysis(const std::vector<Student_info>& );
void write_analysis(std::ostream& , const std::string&, double (*ptr)(const std::vector<Student_info>&),
                    const std::vector<Student_info>&, const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>& );


#endif
