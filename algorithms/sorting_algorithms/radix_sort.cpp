#include<iostream>
using namespace std;


int max(int *arr, int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int numberOfDigits(int num){
    int count = 0;
    while(num > 0){
        num = num/10;
        count++;
    }
    return count;
}


int radixSort(int *arr, int n){
    int numberOfBuckets = 10,maxNumber, digits, bucketNumber, divisor=1, inBucketPosition, position;
    int count[numberOfBuckets], buckets[numberOfBuckets][n];
    maxNumber = max(arr,n);
    digits = numberOfDigits(maxNumber);
    for(int i=0;i < digits; i++){
// reset count array
        for(int i=0; i<numberOfBuckets; i++){
            count[i] = 0;
        } 
// element distribution inside buckets
        for(int j=0; j<n; j++){
            bucketNumber = (arr[j]/divisor)%10;
            inBucketPosition = count[bucketNumber];
            buckets[bucketNumber][inBucketPosition] = arr[j];
            count[bucketNumber]++;
        }
// merge buckets to reform orignal array
        position = 0;
        for(int j=0; j<numberOfBuckets; j++){
            for(int k=0; k<count[j]; k++){
                arr[position] = buckets[j][k];
                position++;
            }
        }
        divisor = divisor *10;
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
   
    radixSort(arr,n);
    cout<<"\nsorted Array : ";
    print_arr(arr,n);
}



