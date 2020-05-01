//
//  no_of_divisors.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*
 Given n numbers whose multiplication gives a number N. find the number of divisors of N. where N can have approx. 50 digits.
 
 Approach : finding N's divisors.....not possible to store N.
 Below approach will work.
 */

#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<unordered_map>
#define ll long long
#define pb push_back
using namespace std;
ll t,n,num;


void find_no_of_divisors(vector<ll> vec,ll n,unordered_map<ll, ll>&map){
    for(ll num:vec){
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                ll count=0;
                while(num%i==0){
                    num=num/i;
                    count++;
                }
                    map[i]+=count;
            }
            
        }
        if(num!=1)
                map[num]++;
    }
}

int main(){
    cin>>t;
    vector<ll> vec;

    while(t--){
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>num;vec.pb(num);
        }
        unordered_map<ll, ll> map;
        find_no_of_divisors(vec,n,map);
        ll res=1;
        for(auto itr=map.begin();itr!=map.end();itr++){
            res=res*(itr->second+1);
        }
    }
}


