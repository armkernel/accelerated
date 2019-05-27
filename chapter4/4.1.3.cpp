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
using std::domain_error; using std::istream;

double grade(double midterm, double finalTerm, double homework);
double grade(double midterm, double fianlTerm, const vector<double>& hw);
double median(vector<double> vec);
istream& read_hw(istream& in, vector<double>& hw);

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

// const 키워드가 없는 것은 전달받은 매게 변수를 변경하지 않겠다는 뜻
istream& read_hw(istream& in, vector<double>& hw) {

	#if 0 
		이건 재대로 동작 x
			1. 첫 번째 이유는 vector<double>& hw 인자가 우리가 정의한게 아니라 전달받았음.
				1.1 hw 내에 어떤 데이터가 존재할지 모른다.
				1.2 hw.clear(); vector 내에 모든 데이터를 정리할 필요가 있음 
			2. 반복문을 언제 멈출지 알 수 없다. 
				2.1 EOF에 도달해서 멈출 수도 있지만 error로 인해 멈출 수도 있다. 
				2.2 EOF, error인한 failure state (입력 실패 상태) 에서 멈추지 않고 무시하고 지나가도록 해야함.
					즉, 무시하고 지나가서 계속 읽을 데이터를 기다리게 해야함. istream에 clear함수를 쓰면 됨
				2.3 in.clear() 사용 -> 오류 표시를 재설정한다고 생각하면 됨. 멈추지 않고 계속하도록.. 
				2.4 다만, vector<T> 에서 정의된 clear와 istream에서 정의된 clear가 다르다는 것만 인지하면 된다.
		function read_hw(cin, homework) 
		double x;
		while (in >> x) 
			hw.push_back(x);
	#endif

	if (in) {
		// 이전 내용 제거		
		hw.clear();
		
		double x;
		
		while(in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
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

	read_hw(cin,homework);
	
	// 최종 점수 구해서 출력 
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) 
		<< grade(midterm, finalterm, homework) 
		<< setprecision(prec) << endl;

	return 0;

}
