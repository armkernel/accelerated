#include <iostream>
#include <iomanip>

int main() 
{

	for (int i = 1; i <= 100; i++) {
	
		//std::cout << std::setw(10);
		// i 이후 7칸 확보 후 출력하라 
		// 열 맞추기..
		std::cout << i << std::setw(7) <<  i * i << std::endl;
	}

}
