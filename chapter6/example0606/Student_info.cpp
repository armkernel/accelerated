#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    is >> s.name >> s.midterm >> s.finalterm;
    read_hw(is, s.homework);
    return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();

        double x;

        while( in >> x ) {
            std::cout << "sdk.. " << x << std::endl;
            hw.push_back(x);
        }

        in.clear();
    }

    return in;
}


bool did_all_hw(const Student_info& s) 
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
    // 낸 과제 중에 하나도 0점이 없다는 건 모든 과제를 다 제출했다는 말이다.
}
