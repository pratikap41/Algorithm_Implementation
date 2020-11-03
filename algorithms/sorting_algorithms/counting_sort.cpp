#include<iostream>
using namespace std;

int max(int *arr, int n){
    int max_value = arr[0];
    for(int i=0;i<n;i++){
        if(max_value < arr[i]){
            max_value = arr[i];
        }
    }
    return max_value;
}

void counting_sort(int *arr, int n){
    int max_value = max(arr,n);
    int *count = new int[max_value + 1 ];
    int output[n];
    // initialize all element of count array to 0
    for(int i=0; i<=max_value ;i++){
        count[i] = 0;
    }
    // put count of each element in count array, index of count array represent value of the element in original array
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    // cumulative sum
    for(int i=1 ; i<=max_value ; i++){
        count[i] +=  count[i-1];
    }
// unstable sort
    // for(int i=0; i<n; i++){
    //     output[count[arr[i]]-1] = arr[i];
    //     count[arr[i]]--;
    // }
// stabe sort
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    // copy output array to orignal array
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

void print_arr(int *arr, int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements : ";
    // inputing original array
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
   
    counting_sort(arr,n);
    cout<<"\nsorted Array : ";
    print_arr(arr,n);
}