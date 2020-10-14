#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int min_index = i;
        for(int j=i+1; j<n ;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i]= arr[min_index];
        arr[min_index] = temp;
    }
   
}
int main(){
    vector<int> arr;
    int n;
    cout<<"Enter Number of Elements : ";
    cin>>n;
    cout<<"Enter element : "; 
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    selection_sort(arr);
     for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 1;

}