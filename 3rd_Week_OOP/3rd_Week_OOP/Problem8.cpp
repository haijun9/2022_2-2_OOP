#include <iostream>
int main() {
	int array[3] = { 8,1,7 };
	int (&re)[3] = array; // array 배열과 연결되는 레퍼런스 배열 re 정의
	int tmp = re[1];	  // swap으로 re에 값 입력
	re[1] = re[2];		
	re[2] = tmp;
	std::cout << "Array: " << array[0] << array[1] << array[2] << std::endl;
	std::cout << "Reference: " << re[0] << re[1] << re[2] << std::endl;
	return 0;
}