//
//  prime_sieve.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 27/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.

//Sieve of eratosthenes and optimizations.
// find all the prime numbers between l and r (inclusive) . in most optimized way.
#include<iostream>
#include<math.h>
#define MAX 1000000
#define ll long long
using namespace std;



// generate a bool array in which value corresponding to a prime will be true
void sieveoferatosthenes(bool *prime){
    prime[1]=false; // 1 is always non prime;
    for(ll i=2;i*i<=MAX;i++){
        if(prime[i]){
            // falsify all the multiples of prime.
            for(ll j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
    cout<<endl;
}

void printPrimesinRange(ll l,ll r,bool *prime){
    for(ll i=l;i<=r;i++){
        if(prime[i])
            cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    ll l,r,t;
    bool prime[MAX+1];
    for(int i=0;i<=MAX;i++)
        prime[i]=true;
    sieveoferatosthenes(prime); // create a sieve : time complexity: O(N*log(log(N)))
    cin>>t;
    while(t--){
        cin>>l>>r;
        printPrimesinRange(l, r, prime);
    }
    
}
