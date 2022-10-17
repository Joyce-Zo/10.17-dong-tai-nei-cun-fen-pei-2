#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

				calloc
int main()
{
	int* p = calloc(10, sizeof(int));
	void* n=calloc(size_t num,size_t size);
	 为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0
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
	free(p);	// 释放动态开辟的空间
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
	 此时只有20个字节的动态内存空间，想要有40个字节的空间
	 用 realloc 调整空间
	int* p2 = realloc(p1, 444);
	 1.如果p指向的空间后有足够的空间可以追加所需的字节，则直接追加，返回原来p的地址
	 2.如果后面空间不足无法追加，则realloc函数重新找一块新的满足可以开辟所需的内存区域
		 并把原来内存中的数据拷贝过来，释放旧的空间，返回新的地址
	int j = 5;
	 3.如果要开辟的空间过大，则可能开辟失败，将返回NULL空指针到原来的p1里，导致原来存储数据的空间丢失，所以应避免使用
	 所以用一块新的变量来接受改变后的地址，如果成功追加，则赋值到原来的地址，否则不赋值
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
	p1 = NULL;// 如果情况1.则释放p1
	 如果情况2.则realloc自动释放原先的p1空间
	
	return 0;
}

				动态内存开辟的错误案例
 
	 1.对空指针NULL解引用操作
int main()
{
	int* p = (int*)malloc(40);
	 如果malloc失败，返回NULL空指针，则下面的代码都将越界访问，非法访问，所以使用完malloc后一定要判断
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

   2.对动态开辟的内存的越界访问
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
		{				// 上面只开辟了20个字节的动态内存空间，但是这里要开辟了40个字节，越界访问
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	return 0;
}

    3.对非动态开辟内存空间的free
int main()
{
	int a = 10;
	int* p = &a; // 栈区的p
	*p = 20;

	free(p);	 // 堆区的free
	p = NULL;
	return 0;
}