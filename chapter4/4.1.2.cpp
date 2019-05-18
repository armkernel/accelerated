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

double grade(double midterm, double finalTerm, double homework);
double grade(double midterm, double fianlTerm, const vector<double>& hw);
double median(vector<double> vec);

double grade(double midterm, double finalTerm, double homework) {
	 return 0.2 * midterm + 0.4 * finalTerm + 0.4 * homework ;
}

// overloading 
// 중간점수, 기말점수, 과제 점수를 이용해 종합점수를 구함 
// 이 함수는 인수를 복사하지 않고 median 함수가 해당 작업을 실행함
// const는 homework에 대한 데이터를 하나도 변경하지 않겠다는 약속을 함
double grade(double midterm, double fianlTerm, const vector<double>& hw) {
	
	if (hw.size() == 0){
		throw domain_error("Student has done no homework");
	}
	return grade(midterm,fianlTerm,median(hw));
}

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	
	if (size == 0) {
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

	
	// 최종 점수 구해서 출력 
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) 
		<< grade(midterm, finalterm, homework) 
		<< setprecision(prec) << endl;

	return 0;

}
