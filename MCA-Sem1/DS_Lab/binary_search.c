#include<stdio.h>
/**
 * It finds the first occurrence of a number in a sorted array
 * 
 * @param arr The array to search in
 * @param start the start index of the array
 * @param end the last index of the array
 * @param search the number you're looking for
 * 
 * @return The index of the first occurrence of the search value.
 */
int occur(int arr[], int start, int end, int search) {
	while (start <= end) {
		int middle = start + (end - start) / 2;
		if (arr[middle] == search) {
			if (middle - 1 > 0 && arr[middle - 1] == search) {
				end = middle - 1;
				continue;
			}
			return middle;
		}
		else if (arr[middle] < search)
		{
			start = middle + 1;
		}
		else
			end = middle - 1;
	}
	return -1;
}

void main()
{
	/* The main function. */
	system("cls");
	int arr[] = { 1,2,2,4,8,9 }, size = sizeof(arr)-1, search, final;
	printf("\nEnter the value to be searched: ");
	scanf("%d", &search);
	final = occur(arr, 0, size, search);
	if (final == -1)
		printf("Element not found");
	else
		printf("%d is at position %d", search, final+1);
}
