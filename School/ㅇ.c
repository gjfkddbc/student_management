#include <stdio.h>

int m()
{
	int a, b, c;
	scanf_s("%d %d",&a, &b);;
	c = a + b;
	printf("%d\n", c);
	c = a - b;
	printf("%d\n", c);
	c = a * b;
	printf("%d\n", c);
	c = a / b;  //자료형 변환 필요
	printf("%d\n", c);
	return 0;
}

