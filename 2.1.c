	
#include <stdio.h>		

//����������� ���������� ����� ��������� ����������(� ���������, ��� ��� n ~37 ��� ������� ��������), ����������� ����������, ������������� �������.


int fibonacci(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}

int antiFibonacci(int n)
{
	int a = 0, b = 1, c;

	while (n != 0)
	{
		c = a + b;
		printf("%i\n", c );
		a = b;
		b = c;
		n--;
	}

}

int main()
{
	antiFibonacci(37);

	return 0;
}
