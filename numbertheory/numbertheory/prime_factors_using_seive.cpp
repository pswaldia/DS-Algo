//
//  prime_factors_using_seive.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 28/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

// finding prime factors using prime sieve

#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long
#define MAX 1000000
using namespace std;

vector<ll> sieveoferatosthenes(bool* prime){
    for(ll i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(ll j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
    vector<ll> prime_sieve;
    for(ll i=2;i<=MAX;i++){
        if(prime[i])
            prime_sieve.push_back(i);
    }
    return prime_sieve;
}

unordered_map<ll, ll> findPrimefactors(ll n,vector<ll> prime_sieve){
    unordered_map<ll, ll> res;
    ll count=0;
    ll i=0;
    while(prime_sieve[i]*prime_sieve[i]<=n)
    {
        if(n%prime_sieve[i]==0){
            count=0;
            while(n%prime_sieve[i]==0){
                n=n/prime_sieve[i];
                count+=1;
            }
            res[prime_sieve[i]]=count;
        }
        i+=1;
    }
    if(n!=1)
        res[n]=1;
    return res;
    
}

int main(){
    ll t,n;cin>>t;
    bool prime[MAX+1];
    memset(prime, true, sizeof(prime));
    vector<ll> prime_sieve=sieveoferatosthenes(prime);
    unordered_map<ll, ll> um;
    while(t--){
        cin>>n;
        um=findPrimefactors(n,prime_sieve);
        for(auto itr=um.begin();itr!=um.end();itr++){
            cout<<itr->first<<" : "<<itr->second<<endl;
        }
    }
}
