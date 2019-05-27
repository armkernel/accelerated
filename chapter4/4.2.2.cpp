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

struct Student_info {
	string name;
	double midterm, finalTerm;
	vector<double> homework;
};
 
double grade(double midterm, double finalTerm, double homework);
double grade(double midterm, double fianlTerm, const vector<double>& hw);
double grade(const Student_info& s);
double median(vector<double> vec);
istream& read_hw(istream& in, vector<double>& hw);
istream& read(istream& in, Student_info& s); 
bool compare(const Student_info& x, const Student_info& y);


/*
	학생들의 점수를 다루는 개념을 쉽게 3단계로 나눌 수 있음	
		1. Student_info 객체에 데이터를 입력
		2. Student_info 객체의 종합 점수를 생성	
		3. Student_info 객체들을 요소로 갖는 백터 정렬 
			{
				sort(vec.begin(), vec.end) 를 이용해 기본 자료형 double형을 정렬함. 
				sort(student_info.begin(), student_info.end()) 를 이용해 정렬 불가능. 
					대소 연산자를 이용해 정렬하는데, 사용자가 정의한 student_info같은 경우 대소비교 연산자를 이용핸 비교 불가. 
				sort함수에는 3번째 인자로 predicate 함수가 존재함. 
				=> 서술함수는 bool타입인 진릿값을 반환하는 함수 
			}

*/

// 사전순서대로 문자열 비교.
bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

double grade(const Student_info& s) {  // const 변수를 통해 메모리에 통쨰로 구조체를 복사하는 overhead를 피하는 작업.
	return grade(s.midterm, s.finalTerm,s.homework); 
	// 별도의 예외처리를 하지 않는다. 그 이유는 내부에서 호출한 grade가 수행되었을 때, 호출되는 error가 담겨 있을 것이기 때문
}

double grade(double midterm, double finalTerm, double homework) {
	 return 0.2 * midterm + 0.4 * finalTerm + 0.4 * homework ;
}

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

/* 이름을 read로 짓는 것이 모호할 수도 있다. 하지만, Student_info라는 타입으로 인해 구별이 가능하다.
실제로 read라는 이름을 명명하여, 오버로딩을 통해 많이 사용한다. */
istream& read(istream& in, Student_info& s) {

	// 학생의 이름, 중간고사 점수, 기말고사 점수를 읽어 저장 
	in >> s.name >> s.midterm >> s.finalTerm;
	read_hw(in, s.homework); // 학생의 모든 과제 점수를 읽어 저장 
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
	// try 개념이 가장 중요하다. 
	try{
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3) 
			<< grade(midterm, finalterm, homework) 
			<< setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You must enter your grade.. " 
			"Please try again.." << endl;
		return 1;
	}
	
	return 0;

}
