/**
 * @file Vector_Sorter.cpp
 * @briefThis file contains a C++ program that implements the QuickSort algorithm to sort a vector of integers.
 */
#include<iostream>
#include<vector>
using namespace std;
/**
 * @class vector_sorter
 A class that implements the QuickSort algorithm to sort a vector of integers.
 */
class vector_sorter{
    public:
    vector<int> a={};
    /**
     * @brief Prints the elements of the vector.
     */
    void printelements();
   /**
     * @brief Sorts the vector using the QuickSort algorithm.
     *
     * @param low The starting index of the vector.
     * @param high The ending index of the vector.
     */
    void quicksort(int low,int high);
     
    /**
     * @brief Partitions the vector for QuickSort.
     *
     * This function selects the last element of the vector as the pivot
     * and rearranges the elements such that elements smaller than the pivot
     * are on its left and elements greater than the pivot are on its right.
     *
     * @param low The starting index of the partition.
     * @param high The ending index of the partition.
     * @return The index of the partitioning element (pivot).
     */
    int partition(int low,int high);
};
void vector_sorter::quicksort(int low, int high){
    if (low<high){
        // piv is partitioning index, arr[p]
        // is now at right place
        int piv = partition(low, high);
 
        // Separately sort elements before
        // partition and after partition
        // divide and conquer
        quicksort(low, piv - 1);
        quicksort(piv + 1, high);
    }
}
int vector_sorter::partition(int low, int high){
    //The pivot is the last element of the array
    int piv = a[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (a[j] < piv) {
             i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}
void vector_sorter::printelements(){
    cout<<"\n The elements in the vector are";
    for(int i=0;i<a.size();i++)
    {
        cout<<" "<<a[i];
    }
}
int main(){   
    vector_sorter q;
    q.a={19,16,4,8,15,2,9,12,14,11,17};
    cout<<"Before Sorting ";
    q.printelements();
    q.quicksort(0,q.a.size()-1);
    cout<<"\n After Sorting "<<endl;
    q.printelements();
    cout<<endl;
    return 0;
}