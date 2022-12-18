#include <iostream>
#include <algorithm>
#include <forward_list>

template<typename ForwardIterator, typename Compare>	// 템플릿 함수, iterator와 compare 이용
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {	// 시작 주소, 끝 주소, 정렬 방법
	for (std::forward_list<int>::iterator it1 = first; it1 != last; it1++) {	// 시작 주소부터 검사 시작
		comp.setNum(*it1);		// compare에 주소 속 원소 값 저장
		for (std::forward_list<int>::iterator it2 = first; it2 != it1; it2++) {	// 검사 시작하는 곳부터 it1 주소까지 비교
			if (comp(*it2)) std::swap(*it1, *it2);	// 비교 결과 정렬해야하면 swap으로 위치 변경
		}
	}
}

class compGreater {		// 오름차순 정렬 Functor
private: int num;		// 기준 값 저장
public:
	void setNum(int n) { num = n; }					// 기준 값 설정
	bool operator() (int n) { return num <= n; }	// 기준 값과 비교, 정렬 필요 시 true
};

class compLess {		// 내림차순 정렬 Functor
private: int num;		// 기준 값 저장
public:
	void setNum(int n) { num = n; }					// 기준 값 설정
	bool operator() (int n) { return num >= n; }	// 기준 값과 비교, 정렬 필요 시 true
};
 
int main() {
	std::forward_list<int> values{ 7,0,6,1,5,2,4,3 };	// 정렬할 배열

	std::cout << "오름차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), compGreater());	// 오름차순 버블 정렬 실시
	for (std::forward_list<int>::iterator it = values.begin(); it != values.end(); it++) {
		std::cout << *it << " ";		// 정렬 후 결과 확인
	}
	std::cout << std::endl;		// 줄 바꿈

	std::cout << "내림차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), compLess());		// 내림차순 버블 정렬 실시
	for (std::forward_list<int>::iterator it = values.begin(); it != values.end(); it++) {
		std::cout << *it << " ";		// 정렬 후 결과 확인
	}
	std::cout << std::endl;		// 줄 바꿈

	return 0;
}