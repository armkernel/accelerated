#include <iostream>
#include <iomanip>

int main() 
{

	int row;
	std::cin >> row;

	for (int i = 1; i <= 1000; i++) {
	
		//std::cout << std::setw(10);
		// i 이후 7칸 확보 후 출력하라 
		// 열 맞추기..
		std::cout << i << std::setw(row) <<  i * i << std::endl;
	}

}
