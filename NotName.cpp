#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <conio.h>

#include <stdlib.h>



void Add()

{

	char n, l, m;

	FILE*f;
	filepath = "s"
	f = fopen("Users.txt", "a+");

	if (f)

	{

	printf("Enter name:");

	scanf("%s", &n);

	fprintf(f, "%s", &n);

	printf("Enter Last Name:");

	scanf(" %s", &l);

	fprintf(f, "%s", &l);

	printf("Enter Number:");

	scanf(" %s", &m);

	fprintf(f, "%s", &m);
	fclose(f);
}
	else
	{
	printf("Can't open file");
}

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

	scanf("%d", &com);

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



/*FILE*f;
	while (!(f = fopen("f.txt", "rt")))
		printf("Can't open file\n");




	/*static char arr[1024][1024];
	int i = 0;

	while (!feof(f))
	{
		fgets(arr[i], sizeof(arr), f);
		printf(arr[i]);
		++i;
	}


	/*int n = 0, p;
	while (fscanf(f, "%d", &p) != EOF)
		n += 1;

	int*arr = (int*)malloc(n * sizeof(int));

	int i;
	rewind(f);
	for (i = 0; i < n; i++)
	{
		fscanf(f, "%d", &arr[i]);
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	printf("Countf of elements: %d", i);

	free(arr);

	fclose(f);*/
