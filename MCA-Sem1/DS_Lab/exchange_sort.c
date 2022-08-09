#include<stdio.h>
void main() {
	system("cls");
	// Reading an arrray
	int size, array[size];
	printf("Enter number of Elements: ");
	scanf("%d", &size);
	printf("Enter %d Elements: ", size);
	for (int i = 0;i < size;i++) {
		scanf("%d", &array[i]);
	}

	// Sorting the array
	int flag = 1;
	while (flag) {
		for (int i = 0;i < size - i;i++) {
			flag = 0;
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = 1;
			}
		}
	}
}