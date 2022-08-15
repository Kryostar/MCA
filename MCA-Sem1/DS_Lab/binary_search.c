#include<stdio.h>
int occur(int arr[], int start, int end, int search) {
	while (start <= end) {
		int middle = start + (end - start) / 2;
		if (arr[middle] < search)
			start = middle + 1;
		else if (arr[middle] > search)
			end = middle - 1;
		else if (start != middle)
			end = middle;
		else
			return middle;
	}
	return -1;
}

void main()
{
	system("cls");
	int arr[] = { 1,1,2,2,4,8,9 }, size = (sizeof(arr) / sizeof(int)) - 1, search, final;
	// Give dynamic input for array.
	printf("\nEnter the value to be searched: ");
	scanf("%d", &search);
	final = occur(arr, 0, size, search);
	if (final == -1)
		printf("Element not found");
	else
		printf("%d is at position %d", search, final + 1);
}