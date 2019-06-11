#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

int main()
{
	Test* p1 = new Test[2];

	Test* p2 = new Test[4];
	// 코드에 문제.. 

	두개의 버퍼를 만들면 두개 만들필요있나?
	default를 이용해 또 할 당 받을 필요없다

	메모리만 있으면 되지. 굳이 생성자를 불러서.. 
	할필요없음
 
	Test *p2 = static_cast<Test*>(operator new(sizeof(Test) * 4); // 생성자 부를 필요없음. 신규 버퍼.. 


    for (int i = 0; i < 10; i++) 
	{
		new(&p2[i]) Test; // default 생성자 학생 이름 같은거.

		//new(&p2[i]) Test(p1[i]); // 복사 생성자.. 
		// new(&p2[i]) Test(move(p1[i])); // 무브 생성자.. 
		new(&p2[i]) Test(move_if_noexcept(p1[i])); // 무브 생성자..
	}
	
	// default 생성자를 부르면됨

	for (int i = 2; i <10 ;i++) {
		new(&p2[i]) Test; // 디폴트 생성자. 
	}

}
