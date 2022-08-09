#include<stdio.h>
#include<conio.h>

/**
 * Swap the values of two integers.
 * 
 * @param a The array to be sorted
 * @param b the array of numbers
 */
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * It takes an array, a low index, and a high index. It then sets the pivot to the value at the high
 * index. It then sets i to the low index - 1. It then iterates through the array from the low index to
 * the high index. If the value at the current index is less than or equal to the pivot, it increments
 * i and swaps the values at i and j. It then swaps the values at i + 1 and high. It then returns i +
 * 1.
 * 
 * @param array the array to be sorted
 * @param low the lowest index of the array
 * @param high the last index of the array
 * 
 * @return The index of the pivot.
 */
int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1);
	for (int j = low;j < high;j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return(i + 1);
}

/**
 * If the array has more than one element, partition the array into two parts, sort the two parts
 * independently, and then merge the results
 * 
 * @param array the array to be sorted
 * @param low the index of the first element of the array
 * @param high the last index of the array
 */
void quickSort(int array[], int low, int high) {
	if (low < high) {
		int pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

/** Print the Array
 */
void printArray(int array[], int size) {
	for (int i = 0;i < size;i++)
		printf("%d", array[i]);
	printf("\n");
}

/**
 * The function takes an array, the starting index and the ending index as parameters. 
 * 
 * It then takes the last element as the pivot and places it at its correct position in the array. 
 * 
 * All the elements smaller than the pivot are placed to the left of the pivot and all the elements
 * greater than the pivot are placed to the right of the pivot. 
 * 
 * The function then recursively calls itself to sort the left and right halves of the array
 * 
 * @return The sorted array in ascending order.
 */
int main() {
	int size;
	system("cls");
	printf("Enter size of data: ");
	scanf("%d", &size);
	int data[size];
	printf("Enter %d number of data:\n", size);
	for (int i = 0;i < size;i++)
		scanf("%d", &data[i]);
	printf("Unsorted Array\n");
	printArray(data, size);
	quickSort(data, 0, size - 1);
	printf("Sorted Array in ascending array: \n");
	printArray(data, size);
	// system("python -u exe.py");
	return 0;
}