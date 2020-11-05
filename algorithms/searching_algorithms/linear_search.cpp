#include<iostream>
using namespace std;

int linerSearch(int * arr, int n,int  x){
    for(int i=0;i<n; i++){
        if(arr[i]==x){
            return i;
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
    found = linerSearch(arr, n, x);
    cout<<"\nElement Found at : "<<found<<endl;
}