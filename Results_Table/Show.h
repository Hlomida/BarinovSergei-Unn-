/*#pragma once
void Show()
{
	FILE* f;
	int cnt = 1;
	char c;
	f = fopen("Users.txt", "r");
	printf("1 ");
	c = getc(f);
	while (c != EOF)

	{

		printf("%c", c);
		if (c == '\n')
		{
			cnt++;
			c = getc(f);
			if (c != EOF)
				printf("%d ", cnt);

		}
		else c = getc(f);
	}
	fclose(f);
	getchar();
}*/