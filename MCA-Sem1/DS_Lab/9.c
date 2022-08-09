#include  <stdio.h>
#include  <string.h>
int main() {
	char str[256], substr[128], replace[128], output[256], cat[256];
	int i = 0, j = 0, flag = 0, start = 0;
	//Accepts all the inputs
	printf("Enter your input string:\n");
	gets(str);
	printf("Enter the string to be concatenated with the Input:\n");
	gets(cat);
	printf("Enter the string to be removed:\n");
	gets(substr);
	printf("Enter the string to replace:\n");
	gets(replace);

	/*str[strlen(str)] = '\0';
	cat[strlen(cat)] = '\0';
	substr[strlen(substr)] = '\0';
	replace[strlen(replace)] = '\0';*/

	// 1. Display Length Of String
	printf("\nLength of '%s' is %d", str, strlen(str));

	// 2. String after Concatenation
	printf("\nAfter Concatenation, the String is: %s", strcat(str, cat));

	// 3. Check if substring is present, and Extract it
	while (str[i] != '\0') //TODO:Change all to function
	{
		if (str[i] == substr[j])
		{
			if (!flag)
				start = i;
			j++;
			if (substr[j] == '\0')
				break;
			flag = 1;
		}
		else
		{
			flag = start = j = 0;
		}
		i++;
	}
	if (flag)
	{
		printf("\nSubstring is present at: %d", start + 1);
	}

	// 4. Replace
	if (substr[j] == '\0' && flag)
	{
		for (i = 0; i < start; i++)
			output[i] = str[i];
		// replace substring with another string
		for (j = 0; j < strlen(replace); j++)
		{
			output[i] = replace[j];
			i++;
		}

		// copy remaining portion of the input string "str"
		for (j = start + strlen(substr); j < strlen(str); j++)
		{
			output[i] = str[j];
			i++;
		}

		// print the final string
		output[i] = '\0';
		printf("\nOutput: %s\n", output);
	}
	else {
		printf("%s is not a substring of %s\n", substr, str);
	}
	return 0;
}