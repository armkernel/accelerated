move 예외는 큰 문제가 아님
계속 쓸 수 있음


Test t1;

Test t2 = t1; // copy

#include <type_traits>

bool b = is_nothrow_move_constructible<Test>::value;

Test t4 = move_if_noexcept(t1);  // 예외가없으먀ㅕㄴ 

buffer 복사ㅏ할때 move생성자에 예외가업을때만..

class 만들때 예외 없이 ㅈ가성하고 키워드 적어야함..
 
