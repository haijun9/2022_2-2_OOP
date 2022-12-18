#include <iostream>

template <typename T>						// 템플릿 함수
auto sum(T x) { return x; }					// 재귀에서 base case에 해당

template<typename T, typename...Args>		// 템플릿 함수, 가변 개수의 인자
auto sum(T x, Args...args) {				// 재귀에서 recursive case에 해당
	return x + sum(args...);				// 원소 하나씩 더하여 종합
}

template<typename... Args>					// 템플릿 함수, 가변 개수의 인자
auto average(Args... args) {				// 가변 개수의 인자들의 평균
	return  sum(args...) / sizeof...(args);	// 위의 sum + sizeof 이용한 평균 계산
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;

	return 0; 
}