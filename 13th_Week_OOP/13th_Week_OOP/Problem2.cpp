#include <iostream>
#include <algorithm>
#include <forward_list>

template<typename ForwardIterator, typename Compare>	// ���ø� �Լ�, iterator�� compare �̿�
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {	// ���� �ּ�, �� �ּ�, ���� ���
	for (std::forward_list<int>::iterator it1 = first; it1 != last; it1++) {	// ���� �ּҺ��� �˻� ����
		comp.setNum(*it1);		// compare�� �ּ� �� ���� �� ����
		for (std::forward_list<int>::iterator it2 = first; it2 != it1; it2++) {	// �˻� �����ϴ� ������ it1 �ּұ��� ��
			if (comp(*it2)) std::swap(*it1, *it2);	// �� ��� �����ؾ��ϸ� swap���� ��ġ ����
		}
	}
}

class compGreater {		// �������� ���� Functor
private: int num;		// ���� �� ����
public:
	void setNum(int n) { num = n; }					// ���� �� ����
	bool operator() (int n) { return num <= n; }	// ���� ���� ��, ���� �ʿ� �� true
};

class compLess {		// �������� ���� Functor
private: int num;		// ���� �� ����
public:
	void setNum(int n) { num = n; }					// ���� �� ����
	bool operator() (int n) { return num >= n; }	// ���� ���� ��, ���� �ʿ� �� true
};
 
int main() {
	std::forward_list<int> values{ 7,0,6,1,5,2,4,3 };	// ������ �迭

	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), compGreater());	// �������� ���� ���� �ǽ�
	for (std::forward_list<int>::iterator it = values.begin(); it != values.end(); it++) {
		std::cout << *it << " ";		// ���� �� ��� Ȯ��
	}
	std::cout << std::endl;		// �� �ٲ�

	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), compLess());		// �������� ���� ���� �ǽ�
	for (std::forward_list<int>::iterator it = values.begin(); it != values.end(); it++) {
		std::cout << *it << " ";		// ���� �� ��� Ȯ��
	}
	std::cout << std::endl;		// �� �ٲ�

	return 0;
}