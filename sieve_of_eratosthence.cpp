//sieve of Eratosthencee. Algorithm to find prime number
#include<iostream>
#include<vector>
#include<cstring>
#include<vector>

using namespace std;

// sieve algorithm
vector<int> get_prime_numbers(int n){
    bool* prime = new bool[n];
    // init all index to true
    for(int i=0; i<n; i++){
        prime[i]= true;
    }
    for(int i=2; i*i<=n ; i++){
        if(prime[i]){
            for(int j=i*i ; j<=n ; j+=i){
                prime[j] = 0;
            }
        }
    }
    vector<int> prime_numbers;
    for(int i=0; i<n ; i++){
        if(prime[i]){
            prime_numbers.push_back(i);
        }
    }
    return prime_numbers;
}

int main(){
    int n ;
    cout<<"Enter n :";
    cin>>n;
    vector<int> prime_numbers = get_prime_numbers(n);
    cout<<"Prime Numbers from 0 to "<<n<<" :\n";
    for(int i=1; i<prime_numbers.size() ; i++){
        cout<<" "<<prime_numbers[i];
    }

}
