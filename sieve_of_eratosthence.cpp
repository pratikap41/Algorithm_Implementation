//sieve of Eratosthencee. Algorithm to find prime number
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    int n ;
    cout<<"Enter n :";
    cin>>n;
    bool prime[n];
    memset(prime, true, n*sizeof(bool));
    for(int i=2; i*i<=n ; i++){
        if(prime[i]){
            for(int j=i*i ; j<=n ; j+=i){
                prime[j] = 0;
            }
        }
    }
    cout<<"Prime Numbers from 0 to "<<n<<" :\n";
    for(int i=1; i<n ; i++){
        if(prime[i]){
            cout<<" "<<i;
        }
    }

}
