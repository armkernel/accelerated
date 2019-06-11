#include <iostream>

using namespace std;

int g = 0;

int main()
{
    int v1 = 10;
    int v2 = 10;

    auto f1 = [](int a) { return a + g; };      // 1
    auto f2 = [](int a) { return a + v1; };     // 2
    auto f3 = [=](int a) { return a + v1; };    // 3
    auto f4 = [=](int a) { v1 = a; };           // 4
}
