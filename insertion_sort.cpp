// Inserion Sort Algorithm
#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &arr, int n){
    for(int i=0 ; i<n; i++){
        int current = arr[i];
        int j = i-1;
        for(j; j>=0; j--){
            if(arr[j]>current){
                arr[j+1]= arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]= current;
    }
    
}

int main(){
    int n;
    cout<<"Enter Number of Element in Array : ";
    cin>>n;
    vector<int> arr ;
    cout<<"Enter Elements : ";
    for(int i=0 ; i<n; i++){
        int temp ;
        cin>>temp;
        arr.push_back(temp);
    }
    insertion_sort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}