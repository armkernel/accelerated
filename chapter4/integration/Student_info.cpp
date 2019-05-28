#include "Student_info.h"

using std::istream;
using std::vector;

/* 
	소스파일에는 using 선언이 문제되지 않는다. 헤더파일과는 달리 소스 파일에서는 using 선언을 사용하더라도 프로그램에 영향을 주지 않는다.
*/

bool compare(const Student_info& x, const Student_info& y) 
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info s)
{

}

istream& read_hw(istream& in, vector<double>& hw)
{

}
