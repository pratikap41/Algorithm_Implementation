// Searching Algorithms
#include<iostream>
#include<math.h>
using namespace std;
int jumpSearch(int * arr, int n, int x){
    int step = (int)sqrt(n);
    int prev = 0;
    while(step<=n){
        if(x <= arr[step]){
            for(int j=prev;j<=step; j++){
                if(arr[j]==x){
                    return j;
                }
            }
        }
        prev = step;
        step = (int)(step + sqrt(n));
    }
    return -1;
}

int linerSearch(int * arr, int n,int  x){
    for(int i=0;i<n; i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

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
    int n,x;
    cout<<"Enter size of array : ";
    cin>>n;
    int * arr = new int[n];
    cout<<"Enter Elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter element to search : ";
    cin>>x;
    cout<<binarySearch(arr,0,n,x);

}
