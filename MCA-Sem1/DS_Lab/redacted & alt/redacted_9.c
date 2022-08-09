#include<stdio.h>

void main()
{
	char s1[32] = "Flowers";
	char s2[] = "low";
	char s3[] = " are beautiful";
	char s4[] = "lol";
	int i, j, k, l = strlen(s2), a, b;
	system("cls"); // use clrscr() in DOS, obviously under conio.h
	printf("The length of string '%s' is %d", s1, strlen(s1)); // 1. To display length of string S1
	printf("\nString after concatenation is '%s", s1, strcat(s1, s3)); // 2. To concatenate strings S1,S3

	for (i = 0; s1[i] != '\0';i++)
	{
		k = i;
		for (j = 0; s2[j] != '\0';j++)
		{
			if (s1[k] != s2[j])
			{
				break;
			}
			k++;
		}
		if (j == l)
		{
			printf("\nSubstring '%s' is at: %d", s2, i); // 3. Extract a substring
			for (a = i, b = 0;s1[a] != '\0', s4[b] != '\0';a++) // 4. Replace substring
			{
				s1[a] = s4[b];
				b++;
			}
			printf("\nAfter replacing the substring, String is: %s",s1);
			break;
		}
	}
	if (j != l)
	{
		printf("\nSubstring not found!");
	}/
}