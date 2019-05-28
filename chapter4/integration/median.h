// #include <algorithm> // sort 함수 선언을 가져옴
// #include <stdexcept> // domain error 예외를 가져옴 
/* 위 두개는 실제 함수를 선언할 때 정의부에서 적어도 됨 */ 

#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector> // vector 타입의 선언을 가져옴


#if 0
using std::domain_error;
using std::sort;
using std::vector;
#endif 
// 사용자가 원하지 않을 수도 있음. using자체를 그래서.. 최대한 유연한 프로그램을 위해 using을 사용하지 않음

// vector<double> 타입 객체의 중앙값을 구함
// 이 함수를 호출하면 인수로 전달된 벡터 전체를 복사

double median(std::vector<double>);


#endif
