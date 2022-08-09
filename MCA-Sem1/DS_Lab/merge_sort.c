#include <stdio.h>

#define max 10

int a[11];
int b[10];

/**
 * It takes the two sorted sub-arrays and merges them into one sorted array
 * 
 * @param low the lowest index of the array
 * @param mid the middle index of the array
 * @param high the highest index of the array
 */
void merging(int low, int mid, int high) {
	int low1, low2, i;

	for (low1 = low, low2 = mid + 1, i = low; low1 <= mid && low2 <= high; i++) {
		if (a[low1] <= a[low2])
			b[i] = a[low1++];
		else
			b[i] = a[low2++];
	}

	while (low1 <= mid)
		b[i++] = a[low1++];

	while (low2 <= high)
		b[i++] = a[low2++];

	for (i = low; i <= high; i++)
		a[i] = b[i];
}

/**
 * If the array is not empty, sort the left half of the array, sort the right half of the array, and
 * merge the two halves
 * 
 * @param low the lowest index of the array
 * @param high the highest index of the array
 * 
 * @return the sorted array.
 */
void sort(int low, int high) {
	int mid;

	if (low < high) {
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid + 1, high);
		merging(low, mid, high);
	}
	else {
		return;
	}
}

/**
 * The function takes the first and last index of the array and sorts the array by dividing it into two
 * parts and sorting them recursively
 */
void main() {
	system("cls");
	printf("Enter 10 elements:\n");
	for (int i = 0;i < 10;i++)
		scanf("%d", &a[i]);
	printf("List before sorting\n");
	for (int i = 0; i <= max; i++)
		printf("%d ", a[i]);

	sort(0, max);

	printf("\nList after sorting\n");
	for (int i = 0; i <= max; i++)
		printf("%d ", a[i]);
}