#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void Add()
{
	char n, l,m;
	FILE*f;
	if (!(f = fopen("Users.txt", "a+")))
	{
		printf("Can't open file");
	}
	printf("Enter name:");
	scanf("%s", &n); fputs("\n", f);
	fputs(&n,f);
	printf("Enter Last Name:");
	scanf(" %s", &l);
	fputs(&l,f);
	printf("Enter Number:");
	scanf(" %s", &m);
	fputs(&m,f);
}
void Del()
{
	printf("Nice");
	FILE *f;
	if (!(f = fopen("Uses.txt", "rt")))
	{
		printf("Could Not Open File");
	}

}
void Find()
{
	FILE *f;
	if (!(f = fopen("Users.txt", "rt")))
	{
		printf("Could Not Open File");
	}

}

int main(int argc, char **argv)
{
	int com;
	
	printf("Type Command:\n1)Add\n2)Del\n3)Find\n");
	scanf("%d",&com);
	switch (com)
	{
	case 1:
		Add();
		break;
	case 2:
		Del();
		break;	
	case 3:
		Find();
		break;
	}

	

	getchar();
	getchar();
	return 0;
	

}
