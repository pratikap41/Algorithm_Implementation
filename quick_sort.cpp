//Quick Sort Algorithm
#include<iostream>
using namespace std;

void quickSort(int * arr, int low, int high){
    int temp;
    if(low<high){
        int i=-1, j=0, pivot=arr[high];
        for(int j=0; j<high; j++){
            if(arr[j]<pivot){
                i++;
                temp =arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        i++;
        temp =arr[i];
        arr[i]=pivot;
        arr[high]=temp;
        quickSort(arr,low,i-1);
        quickSort(arr,i+1, high);
    }
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int * arr = new int[n];
    cout<<"Enter Elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 1;
}