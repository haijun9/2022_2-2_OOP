#include <iostream>
int main() {
	int array[3] = { 8,1,7 };
	int (&re)[3] = array; // array �迭�� ����Ǵ� ���۷��� �迭 re ����
	int tmp = re[1];	  // swap���� re�� �� �Է�
	re[1] = re[2];		
	re[2] = tmp;
	std::cout << "Array: " << array[0] << array[1] << array[2] << std::endl;
	std::cout << "Reference: " << re[0] << re[1] << re[2] << std::endl;
	return 0;
}