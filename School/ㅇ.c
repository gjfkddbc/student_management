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
	c = a / b;  //�ڷ��� ��ȯ �ʿ�
	printf("%d\n", c);
	return 0;
}

