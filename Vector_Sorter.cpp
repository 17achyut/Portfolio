#include<iostream>
#include<vector>
using namespace std;
class vector_sorter{
    public:
    vector<int> a={};
    void printelements();
    void quicksort(int low,int high);
    int partition(int low,int high);
};
void vector_sorter::quicksort(int low, int high){
    if (low<high){
        // pi is partitioning index, arr[p]
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