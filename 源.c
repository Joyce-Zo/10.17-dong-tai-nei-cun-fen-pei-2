#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

				calloc
int main()
{
	int* p = calloc(10, sizeof(int));
	void* n=calloc(size_t num,size_t size);
	 Ϊnum����СΪsize��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0
	if (p == NULL)
	{
		printf("%s ", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p+i));
		}
	}
	free(p);	// �ͷŶ�̬���ٵĿռ�
	p = NULL;
	return 0;
}

int main()
{
	int* p1 = (int*)malloc(20);
	if (p1 == NULL)
	{
		printf("%s ", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p1 + i) = i;
			printf("%d ", *(p1 + i));
		}
	}
	printf("\n");
	 ��ʱֻ��20���ֽڵĶ�̬�ڴ�ռ䣬��Ҫ��40���ֽڵĿռ�
	 �� realloc �����ռ�
	int* p2 = realloc(p1, 444);
	 1.���pָ��Ŀռ�����㹻�Ŀռ����׷��������ֽڣ���ֱ��׷�ӣ�����ԭ��p�ĵ�ַ
	 2.�������ռ䲻���޷�׷�ӣ���realloc����������һ���µ�������Կ���������ڴ�����
		 ����ԭ���ڴ��е����ݿ����������ͷžɵĿռ䣬�����µĵ�ַ
	int j = 5;
	 3.���Ҫ���ٵĿռ��������ܿ���ʧ�ܣ�������NULL��ָ�뵽ԭ����p1�����ԭ���洢���ݵĿռ䶪ʧ������Ӧ����ʹ��
	 ������һ���µı��������ܸı��ĵ�ַ������ɹ�׷�ӣ���ֵ��ԭ���ĵ�ַ�����򲻸�ֵ
	if (p2 != NULL)
	{
		p1 = p2;
		for (j = 5; j < 10; j++)
		{
			*(p1 + j) = j;
			printf("%d ", *(p1 + j));
		}
	}
	else if(p2 == NULL)
	{
		printf("%s ", strerror(errno));
	}
	free(p1);
	p1 = NULL;// ������1.���ͷ�p1
	 ������2.��realloc�Զ��ͷ�ԭ�ȵ�p1�ռ�
	
	return 0;
}

				��̬�ڴ濪�ٵĴ�����
 
	 1.�Կ�ָ��NULL�����ò���
int main()
{
	int* p = (int*)malloc(40);
	 ���mallocʧ�ܣ�����NULL��ָ�룬������Ĵ��붼��Խ����ʣ��Ƿ����ʣ�����ʹ����malloc��һ��Ҫ�ж�
	if (p != NULL)
	{
		*p = 1;
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
 free(p);
 p=NULL;
	return 0;
}

   2.�Զ�̬���ٵ��ڴ��Խ�����
int main()
{
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{				// ����ֻ������20���ֽڵĶ�̬�ڴ�ռ䣬��������Ҫ������40���ֽڣ�Խ�����
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	return 0;
}

    3.�ԷǶ�̬�����ڴ�ռ��free
int main()
{
	int a = 10;
	int* p = &a; // ջ����p
	*p = 20;

	free(p);	 // ������free
	p = NULL;
	return 0;
}