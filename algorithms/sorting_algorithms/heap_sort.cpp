#include<iostream>
using namespace std;
// in heap array 0th index stores the number of element in the heap

// function for adjusting element in upward direction
void upadjust(int *heap, int i){
    int temp;
    // if given element is at index i then its parent will be at i/2
    // i/2 < 0 then its not a valid parent 
    while(i/2 > 0){
        if(heap[i/2] < heap[i] ){
            temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i = i/2;
        }
        else{
            break;
        }
    }
}

// function for adjusting element in downward direction
void downadjust(int *heap)
{
    int n = heap[0], i=1, temp, j;
    // if parent index is i then its left child will be at index i*2 
    // and right child will be at i*2+1 index
    // if i*2 > n then it will not be a valid child index were n is number of elements in heap
    while(i*2 <= n){
        j = i*2;
        if(j+1 <= n)
        {
            if(heap[j]<heap[j+1]){
                j = j+1;
            }
        }
        if(heap[i]<heap[j])
        {
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }else{
            break;
        }
    }
}

// removes first/max element from heap
void remove(int *heap){
    int temp;
    temp = heap[1];
    heap[1]=heap[heap[0]];
    heap[heap[0]] = temp; 
    heap[0]--;
    downadjust(heap);
}

// insert element at last index of heap
void insert(int *heap, int x){
    int n = heap[0];
    heap[n+1] = x;
    heap[0]++;
    upadjust(heap, n+1);
}


void heap_sort(int *heap, int n){
    for(int i=1; i<n ;i++){
        remove(heap);
    }
}


int main(){
    int n,x;
    cout<<"Enter size : ";
    cin>>n;
    // heap array size should be n+1 as 0th index stores size of heap
    int *heap = new int[n+1];
    heap[0] = 0;
    cout<<"Enter Elements : ";
    // inputing heap
    for(int i=1;i<=n;i++){
        cin>>x;
        insert(heap,x);
    }

    heap_sort(heap,n);

    // print heap
    cout<<"Sorted Array : ";
    for(int i=1;i<=n;i++){
        cout<<heap[i]<<" ";
    }

}