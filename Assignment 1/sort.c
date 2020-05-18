#include <stdio.h>      // print utility library
#include <stdlib.h>     // dynamic memory allocation
#define N 10            // default array size

void msort(int *a, int n);                              // merge sort wrapper fucntion header
void mergesort2(int *a, int left, int right);            // merge sort utility function header
void merge(int *a, int ll, int lr, int rl, int rr);     // merge sort helper function header
void qsort2(int *a, int n);                             // quick sort wrapper function header
void quicksort(int *a, int left, int right);            // quick sort utility function header
int partition(int *a, int left, int right);             // quick sort helper function header
void swap(int *a, int *b);                              // swap utility function header
void printArray(int *a, int n);                         // print array utility function header

int main()
{
    int arr1[N] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};    // array used to test merge sort
    int arr2[N] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};    // array used to test quick sort
    int *ptr1 = arr1;       // pointer to array to be passed to merge sort
    printf("%s", "original array:\t");    // print the original array text
    printArray(ptr1, N);    // print original array
    msort(ptr1, N);         // invoke merge sort API
    printf("%s", "merge sort:\t");    // print merge sort text
    printArray(ptr1, N);    // print the array resulted by merge sort
    int *ptr2 = arr2;       // pointer to array to be passed to quick sort
    qsort2(ptr2, N);        // invoke quick sort API
    printf("%s", "quick sort:\t");   // print quick sort text
    printArray(ptr2, N);    // print the array resulted by quick sort
    return 0;       // end program
}

void msort(int *a, int n)       // implementation of merge sort wrapper function
{
    mergesort2(a, 0, n - 1);     // invoke merge sort utility function
}

void mergesort2(int *a, int left, int right)     // implementation of merge sort utility function
{
    if(left < right)                            // if there are at least 2 elements
    {
        int mid = (left + right) / 2;           // divide the array into 2 sub arrays
        mergesort2(a, left, mid);                // recursively sort the left sub array
        mergesort2(a, mid + 1, right);           // recursively sort the right sub array
        merge(a, left, mid, mid + 1, right);    // merge the sub arrays
    }
}

void merge(int *a, int ll, int lr, int rl, int rr)      // merge 2 sub arrays
{
    int *temp = (int*) malloc(4);        // temporary dynamic array used to store sorted elements
    int i = ll;         // start of left sub array (left left)
    int j = rl;         // start of right sub array (right left)
    int k = 0;          // index used to iterates through the temporary array
    while(i <= lr && j <= rr)       // scan 2 sub arrays at the same time until all elements of either sub array are scanned
    {
        if(a[i] < a[j])             // if element of left sub array is smaller
            *(temp + k++) = a[i++];     // store it in the temporary array
        else                        // if element of right sub array is larger
            *(temp + k++) = a[j++];     // store it in the temporary array
    }
    while(i <= lr)              // from left sub array
        *(temp + k++) = a[i++];     // put anything left into temporary array
    while(j <= rr)              // from right sub array
        *(temp + k++) = a[j++];     // put anything left into temporary array
    k = 0;                      // reset temporary array index
    while(ll <= rr)             // at this point, 2 sub arrays are sorted and stored in temporary array 
        a[ll++] = *(temp + k++);    // copy elements of temporary array into the array
    free(temp);         // release memory
}

void qsort2(int *a, int n)      // implementation of merge sort wrapper function
{
    quicksort(a, 0, n - 1);     // invoke quick sort utility function
}

void quicksort(int *a, int left, int right)     // implementation of quick sort utility function
{
    if(left < right)                            // if there are at least 2 elements
    {
        int pivot = partition(a, left, right);  // partition the array and store the pivot index
        quicksort(a, left, pivot - 1);          // recursively sort the left sub array
        quicksort(a, pivot + 1, right);         // recursively sort the right sub array
    }
}

int partition(int *a, int left, int right)      // put values smaller than pivot on the left, and larger on the right
{
    int pivot = right--;                                // choose the last value as pivot
    while(left < right)                                 // scan the whole array until both markers cross
    {
        while(left <= right && a[left] <= a[pivot])     // increment left marker
            left++;                                     // until the value is larger than pivot
        while(left <= right && a[right] >= a[pivot])    // decrement right marker
            right--;                                    // until the value is less than pivot
        if(left < right)                                // if left marker has not crossed right marker
            swap(&a[left], &a[right]);                  // swap the elements
    }
    if(left < pivot)                    // if left marker has not reached the pivot position
        swap(&a[left], &a[pivot]);      // swap left value with pivot
    return left;                        // return pivot index
}

void swap(int *a, int *b)        // swap two values by reference
{
    int temp = *a;      // use a temporary variable to store the value of a
    *a = *b;            // let a = b
    *b = temp;          // let b = the original value of a
}

void printArray(int *a, int n)      // print array of size n
{
    for(int i = 0; i < n; i++)      // iterates through the array
        printf("%d ", a[i]);        // print the values of each element in the array
    printf("\n");                   // new line
}