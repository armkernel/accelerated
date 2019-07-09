#include <algorithm>
#include <stdexcept> 
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

template<class T>
T median(vector<T> vec) 
{
    // vector의 요소를 꺼낼 때 typename을 써줘야함 
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)  
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid]; // 홀수 : 짝수
}

/*
double median(vector<double> vec) 
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)  
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid]; // 홀수 : 짝수
}*/
