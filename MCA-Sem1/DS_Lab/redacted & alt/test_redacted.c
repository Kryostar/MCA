#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char s1[] = "Riya";
	char s2[] = "ya";
	int i, j, k, l = strlen(s1),f=0;
	for (i = 0;s1[i] != '\0';i++)
	{
		for (j = 0, k = i;s2[j] != '\0';j++)
		{
			if (s1[k] != s2[j])
			{
				break;
			}
			k++;
		}
		if (j == l)
		{
			printf("Substring is at %d", i + 1);
		}
	}
	getch();
	/*if (f != 1)
	{
		printf("Substring not found");
	}*/
}
