// Implementing Quicksort

#include<iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    //The pivot is the last element of the array
    int piv = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < piv) {
             i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
// The function that implements quicksort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quicksort(int arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int piv = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        // divide and conquer
        quicksort(arr, low, piv - 1);
        quicksort(arr, piv + 1, high);
    }
}

int main()
{
    int arr[]={13,17,8,9,4,19,1};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input array is ";
    for(int i=0;i<N;i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<"\n The sorted array is ";
    quicksort(arr,0,N-1);
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}