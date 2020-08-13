//bubble sort 
#include<iostream>
using namespace std;

void bubbleSort(int n,int* arr){
    int temp;
    for(int i=0; i<n; i++){
        bool flag = true;
        //after every iteration last i elements will be sorted
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp =arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=false;   
            }
        }
        if(flag){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int * arr = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter Element : ";
        cin>>arr[i];
    }
    bubbleSort(n,arr);
    return 1;
}
