// CPP program to find prime factors of given number
#include<iostream>
#include<vector>
using namespace std;

// sieve Algorithm
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

vector<int> get_prime_factors(int num1){
    vector<int> prime_numbers = get_prime_numbers(num1);
    vector<int> prime_factors;
    int temp = num1; //variable to keep track of reminder after dividing
    while(temp!=1){
        for(int i=2; i<prime_numbers.size(); i++){
            if(temp % prime_numbers[i] == 0){
                temp = temp/prime_numbers[i];
                prime_factors.push_back(prime_numbers[i]);
                break;
            }
        }
    }
    return prime_factors;
}

int main(){
    cout<<"Prime Factorization\n";
    int num1;
    cout<<"Enter Number To Be Factorized : ";
    cin>>num1;
    vector<int> prime_factors = get_prime_factors(num1); 
    cout<<"Prime Factors Of Number "<<num1<< " are ";
    for(int i =0 ; i < prime_factors.size(); i++){
        cout<<prime_factors[i]<<"*";
    }
    cout<<1;
}

