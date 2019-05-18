#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;

// 해결하려는 문제의 핵심을 파악해 함수에 알맞는 이름을 붙인다면 프로그램을 이해하기가 더 쉬워지고 간단하게 문제 해결 가능 
double grade(double midterm, double finalTerm, double homework) {
	 return 0.2 * midterm + 0.4 * finalTerm + 0.4 * homework ;
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

	// 과제 점수의 입력 유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades. "
			"Please try again. " << endl;
		return 1;
	}

	// 점수를 정렬	
	sort(homework.begin(), homework.end());

	// 과제점수의 중앙 값을 구함
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 :
		homework[mid];

	// 최종 점수 구해서 출력 
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) 
		<< grade(midterm, finalterm, median) 
		<< setprecision(prec) << endl;

	return 0;

}
