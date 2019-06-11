#include <iostream>

using namespace std;

using LREF = int&;
using RREF = int&&;

int main()
{

	int n1 = 10;
	int n2 = 20;

	reference_wrapper<int> r1(n1);
	reference_wrapper<int> r2(n2);

	r1 = r2;

	cout << n1 << ", ";
	cout << n2 << ", ";
	cout << r1 << ", ";
	cout << r2 << ", ";


	#if 0 
	int n = 10;

	LREF& r1 = n;
	LREF&& r2 = n;
	RREF& r3 = n;
	RREF&& r4 = n;
	int x[3] = { 1,2,3 };

	auto a1 = x[0];
	decltype(x[0]) d1;
	auto a2 = x;
	decltype(auto) d2 = x;
	#endif
}
