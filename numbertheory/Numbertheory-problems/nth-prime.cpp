//
//  nth-prime.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include <vector>
#include<cstring>
#include <unordered_map>
#include <math.h>
#define ll long long
#define pb push_back
using namespace std;

ll n;

vector<ll> sieveoferatosthenes(bool* prime){
    for(int i=2;i*i<=INT_MAX;i++){
        if(prime[i]){
            for(ll j=i*i;j<=INT_MAX;j+=i){
                prime[j]=false;
            }
        }
    }
    vector<ll> primes;
    for(ll i=2;i<=INT_MAX;i++){
        if(prime[i])
            primes.pb(i);
    }
    return primes;
}

int main(){
    cin>>n;
    bool prime[INT_MAX];
    memset(prime, true, sizeof(prime));
    vector<ll> primes;
    primes=sieveoferatosthenes(prime);
    cout<<primes[n-1]<<endl;
}


