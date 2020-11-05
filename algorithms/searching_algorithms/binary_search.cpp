#include<iostream>
using namespace std;

int binarySearch(int * arr,int low,int high, int key){
    if(low<high){
        int mid = (low+(high-1))/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            return binarySearch(arr,low,mid,key);
        }
        else if(arr[mid]<key){
            return binarySearch(arr,mid+1,high,key);
        }
    }
    return -1;
}

int main(){
    int n, element, x, found;
    cout<<"Enter Size of an array : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter Elememts : ";
    for(int i=0 ; i<n ; i++){
        cin>>element;
    }
    cout<<"Enter Key to be searched : ";
    cin>>x;
    found = binarySearch(arr, 0, n, x);
    cout<<"\nElement Found at : "<<found<<endl;
}