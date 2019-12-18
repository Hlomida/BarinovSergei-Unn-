#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define SIZE 1024
using namespace std;
void Add()
{
	char n, l, m;
	FILE* f;
	f = fopen("Users.txt", "a+");
	if (f)
	{
		printf("Enter name:");
		scanf("%s", &n);
		fprintf(f, "%s ", &n);
		printf("Enter Last Name:");
		scanf(" %s", &l);
		fprintf(f, "%s ", &l);
		printf("Enter Number:");
		scanf(" %s", &m);
		fprintf(f, "%s ", &m);
		fputs("\n", f);
		fclose(f);
	}
	else
	{
		printf("Can't open file");
	}

}	
	void Del()
{
	FILE* f, * fp2;
	char c;
	int del_line, cnt = 0, temp = 1;
	f = fopen("Users.txt", "r");
	c = getc(f);
	while (c != EOF)
	{
		printf("%c", c);
		c = getc(f);
	}
	rewind(f);
		
	printf(" \n Enter line number of the line to be deleted:");
	scanf("%d", &del_line);
		while (!feof(f)) {
		fscanf(f, "%*[^\n]%*c");
		cnt++;
	}
	if (del_line >= cnt)
		printf("No User with such number");
	else 
	{
	fp2 = fopen("temp.txt", "w");
		rewind(f);
	c = getc(f);
	while (c != EOF) {
		if (c == '\n')
			temp++;
		if (temp != del_line)
		{
			putc(c, fp2);
		}
		c = getc(f);
	}
	fclose(f);
	fclose(fp2);
	remove("Users.txt");
	rename("temp.txt", "Users.txt");
	f = fopen("Users.txt", "r");
	c = getc(f);
	while (c != EOF) {
		printf("%c", c);
		c = getc(f);
	}
	}	
	fclose(f);
}
void Find()
{
	FILE* f;

	if (!(f = fopen("Users.txt", "rt")))
	{
		printf("Could Not Open File");
	}	
	char word[20];
	printf("Enter abonent:1");
	scanf("%s", &word);
	ifstream input("Users.txt");
	char buffer[1024];
	while (input.getline(buffer, 1024)) {
		if (strstr(buffer, word))
			printf("%s\n", buffer);
	}
	fclose(f);
}
int main(int argc, char** argv)
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
	return 0;
}
