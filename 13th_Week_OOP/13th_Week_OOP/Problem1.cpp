#include <iostream>

template <typename T>						// ���ø� �Լ�
auto sum(T x) { return x; }					// ��Ϳ��� base case�� �ش�

template<typename T, typename...Args>		// ���ø� �Լ�, ���� ������ ����
auto sum(T x, Args...args) {				// ��Ϳ��� recursive case�� �ش�
	return x + sum(args...);				// ���� �ϳ��� ���Ͽ� ����
}

template<typename... Args>					// ���ø� �Լ�, ���� ������ ����
auto average(Args... args) {				// ���� ������ ���ڵ��� ���
	return  sum(args...) / sizeof...(args);	// ���� sum + sizeof �̿��� ��� ���
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;

	return 0; 
}