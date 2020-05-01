//
//  prime+factorisation.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

// finding the prime factors and their count and storing them as key value pair

#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
#define ll long long
#define MAX 1000000
using namespace std;

unordered_map<ll, ll> findPrimefactors(ll n){
    unordered_map<ll, ll> res;
    ll count=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            count=0;
            while(n%i==0){
                n=n/i;
                count+=1;
            }
            res[i]=count;
        }
    }
    if(n!=1)
        res[n]=1;
    return res;
}

int main(){
    ll n,t;cin>>t;
    unordered_map<ll, ll> um;
    while(t--){
        cin>>n;
        um=findPrimefactors(n);
        for(auto itr=um.begin();itr!=um.end();itr++){
            cout<<itr->first<<" : "<<itr->second<<endl;
        }
    }
    
}
