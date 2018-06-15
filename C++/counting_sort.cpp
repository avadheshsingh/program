//counting_sort
#include<iostream>
using namespace std;
#define char_to_int(c) ((int)c-(int)'a')
#define int_to_char(c) ((char)c+(char)'a')
#define size 26
int countarr[size];

int str_len(const char* arr) {
	int i = 0;
	while (arr[i] != '\0')
		i++;
	return i;
}

void countingSort(char* arr) {
	int length = str_len(arr);  
    char  output[size];

	for (int i = 0; i<length; i++) {
		int index = char_to_int(arr[i]);
		++countarr[index];
	}

	for (int i = 1; i<size; i++) {
		countarr[i] += countarr[i - 1];
	}

	for (int i = 0; i<length; i++) {
		int index = char_to_int(arr[i]);
		output[countarr[index]] = arr[i];
		--countarr[index];
	}

	for (int i = 1; i<=length; i++) {
		cout << output[i];
	}
}

void init() {
	for (int i = 0; i<size; i++) {
		countarr[i] = 0;
	}
}
int main() {
	char key[] = "geeksforgeek";
	countingSort(key);

	return 0;
}