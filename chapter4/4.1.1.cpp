#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept> // domain_error를 사용하기 위한 표준 라이브러리 

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;
using std::domain_error;

// 해결하려는 문제의 핵심을 파악해 함수에 알맞는 이름을 붙인다면 프로그램을 이해하기가 더 쉬워지고 간단하게 문제 해결 가능 
double grade(double midterm, double finalTerm, double homework) {
	 return 0.2 * midterm + 0.4 * finalTerm + 0.4 * homework ;
}

// vector<double> 의 중앙값을 구함
// 함수를 호출하면 인수로 제공된 벡터를 통쨰로 복사.. (homework 뿐만아니라 좀 더 gerneral한 vector median 값 구하는 함수)
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	
	if (size == 0) {
		#if 0
		기존의 median error 처리 => general 하게 median함수가 변형됨에 따라 예외도 변형됨 
		cout << endl << "You must enter your grades. "
			"Please try again. " << endl;
		#endif
		// 어떤 값을 처리하다가 에러난 건지 모르기 떄문에 throw를 통해 예외를 던져버림. 사용자가 알아서 처리 
		// 예외를 던지면 호출자에게 전달할 정보가 있는 exception object와 함꼐 다른 부분으로 이동 
		throw domain_error("median of an empty vector");
	}

	sort(vec.begin(), vec.end());
	
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}


int main() 
{
	// 학생의 이름을 묻고 입력받음
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// 중간고사과 기말시험의 점수를 묻고 입력 받음
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, finalterm;
	cin >> midterm >> finalterm;


	// 과제 점수를 묻고 입력받음
	cout << "Enter all your homework grades, "
			"followed by end-of-file";
	vector<double> homework;

	double x;

	// 불변성: homework는 지금까지 입력받은 과제 점수가 있음
	while (cin >> x)
		homework.push_back(x);

	double medianValue = median(homework);
	
	// 최종 점수 구해서 출력 
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) 
		<< grade(midterm, finalterm, medianValue) 
		<< setprecision(prec) << endl;

	return 0;

}
