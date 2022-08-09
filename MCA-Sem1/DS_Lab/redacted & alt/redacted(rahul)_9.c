#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char s1[100];
	char s2[100];
	char s3[100];
	char s4[100];
	char s5[100];
	char ch;
	printf("Enter the value of the first string: \n");
	gets(s1);
	printf("Enter the value of the Second string: \n");
	gets(s2);
	int len = strlen(s1);
	int i, j, k, y, a, b, r;
	do
	{
		printf("\n\nEnter your choice: \n");
		printf("1. Find the length of %s \n", s1);
		printf("2. To Concatenate '%s' and '%s' \n", s1, s2);
		printf("3. Find the Substring from '%s':\n", s1);
		printf("4. Replace the Substring from '%s':\n\n", s2);
		scanf("%c", &ch);
		switch (ch)
		{
		case '1':
			printf("\nThe Length of %s is %d\n", s1, len);
			break;
		case '2':
			printf("\nThe Concatenated String is '%s'", strcat(s1, s2));
			break;
		case '3':
			printf("\nEnter the Substring to be searched from '%s':\n", s1);
			scanf("%s", s3);
			int l = strlen(s3);
			{
				for (i = 0;s1[i] != '\0';i++)
				{

					for (j = 0, k = i;s1[k] != '\0';j++)
					{
						if (s1[k] != s3[j])
						{
							break;
						}
						k++;
					}
					if (j == l)
					{
						printf("The Substring '%s' is at: %d\n", s3, i + 1);
						break;
					}
				}
				if (j != l)
				{
					printf("The Substring is NOT present\n");

					break;
				}

			}
			break;

		case '4':
			printf("\nEnter the Substring to be changed from '%s':\n", s2);
			scanf("%s", s5);
			printf("Enter the String that will change '%s':\n", s5);
			scanf("%s", s4);
			int li = strlen(s5);
			for (i = 0; s2[i] != '\0';i++)
			{
				for (j = 0, k = i;s2[k] != '\0';j++)
				{
					if (s2[k] != s5[j])
					{
						break;
					}
					k++;
				}
				if (j == li)
				{
					for (a = i, b = 0;s2[a] != '\0', s4[b] != '\0';a++, b++) // Replace s2 substring
					{
						s2[a] = s4[b];
					}
					printf("\nAfter replacing the substring, The String is: %s", s2);
					break;
				}
			}
			if (j != li)
			{
				printf("Substring not found!");
				break;
			}
			break;
		}
	} while (ch != 0);
	getch();
}