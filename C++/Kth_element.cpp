//Kth element in 2 sorted merged array;
#include<iostream>
using namespace std;
int size(int arr[]) {	return sizeof(arr) / sizeof(arr[0]);}
int min(int a, int b) { return a<b ? a : b; }

int KthElement(int arr1[], int arr2[], int end1, int end2, int k) {
	if (size(arr1)>size(arr2)) {
		return KthElement(arr1, arr2, 4, 5, k);
	}

	if (size(arr1) == 0 && size(arr2)>0) {
		return arr2[k - 1];
	}

	if (k == 1) {
		return min(arr1[0], arr2[0]);
	}

	int mid1 = min(size(arr1), k / 2);
	int mid2 = min(size(arr2), k / 2);

	if (arr1[mid1 - 1]<arr2[mid2 - 1])
		return KthElement(arr1 + mid1, arr2, end1 - mid1, mid2, k - mid1);
	else
		return KthElement(arr1, arr2 + mid2, mid1, end2 - mid2, k - mid2);
}

int main() {
	int arr1[5] = { 2,3,6,7,9 };
	int arr2[4] = { 1,4,8,10 };
	int k = 5;
	cout << KthElement(arr1, arr2, 5, 4, k);
	getchar();
	return 0;
}