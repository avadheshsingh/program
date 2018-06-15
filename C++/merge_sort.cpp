/* C program for Merge Sort */
#include<iostream>
using namespace std;

int compare(int arr[],int arr1[],int arr2[],int i, int j){
	if(arr[i]<=arr[j])
		return 1;
}


void merge(int arr[],int arr1[],int arr2[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr2[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr2[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (compare(arr,arr1,arr2, L[i], R[j]))
        {
            arr2[k] = L[i];
            i++;
        }
        else
        {
            arr2[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr2[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr2[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[],int arr1[],int arr2[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr,arr1,arr2, l, m);
        mergeSort(arr,arr1,arr2, m+1, r);
 
        merge(arr,arr1,arr2,l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int arr[],int arr1[],int arr2[],  int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
	for (i=0; i < size; i++)
        cout<<arr1[i]<<" ";
    cout<<"\n";
	for (i=0; i < size; i++)
        cout<<arr2[i]<<" ";
    cout<<"\n";
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 15, 13, 16, 6, 7};
	int arr1[] = {12, 11, 13, 5, 6, 7};
	int arr2[] = {0, 1, 2, 3, 4, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
     cout<<"Given array is \n";
    printArray(arr,arr1,arr2, arr_size);
 
    mergeSort(arr,arr1,arr2, 0, arr_size - 1);
 
    cout<<"\nSorted array is \n";
    printArray(arr,arr1,arr2, arr_size);
    return 0;
}
