#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class InsTab
{
public:
	
		char name, math, pe, prog;
		void Add()
		{
		FILE* f;
		f = fopen("Results.txt", "a+");
		if (f)
		{
			fprintf(f, "%s ", "\n");
			printf("Enter Students' name:-");
			scanf("%s", &name);
			fprintf(f, " %s ", &name);
			printf("Enter Math mark:-");
			scanf(" %s", &math);
			fprintf(f, "%s ", &math);
			printf("Enter PE mark:-");
			scanf(" %s", &pe);
			fprintf(f, "%s ", &pe);
			printf("Enter Programming mark:-");
			scanf(" %s", &prog);
			fprintf(f, "%s ", &prog);
			fclose(f);
		}
		else
		{
			printf("Can't open file");
		}
	}
		void Show()
		{
			FILE* f;
			//int cnt = 1;
			char c;
			f = fopen("Results.txt", "r");
			c = getc(f);
			while (c != EOF)

			{

				printf("%c", c);
				if (c == '\n')
				{
					//cnt++;
					c = getc(f);
					//if (c != EOF);
				//printf("%d ", cnt);

				}
				else c = getc(f);
			}
			fclose(f);
			getchar();
		}
};