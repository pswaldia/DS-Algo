//
//  primes-in-range.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//
/*
 After learning sieve of Eratosthenes,
 Deepak wants to play more with the primes. This time he is trying to print primes between two integers.
 Help him in this task.
 1<=T<=10
 1<=m<=n<=1000000000,
 n-m<=100000
 Approach: Segmented Sieve.
 */


#include<iostream>
#include<math.h>
#include<cstring>
#define MAX 100000
#define ll long long
using namespace std;

ll a,b,t;

void prime_sieve(bool* prime){
    for(ll i=2;i*i<=MAX;i++){
        if(prime[i])
        {
            for(ll j=i*i;j<=MAX;j++){
                prime[j]=false;
            }
        }
    }
}

void segmented_sieve(bool* prime,ll a,ll b){
    bool range_arr[b-a+1];
    ll size=sqrt(b);
    memset(range_arr, true, sizeof(range_arr));
    for(ll i=2;i*i<=b;i++){
            for(ll j=0;j<=b-a;j++){
                if((a+j)==i)
                    continue;
                if(prime[i]){
                    if((a+j)%i==0)
                        range_arr[j]=false;
            }
        }
    }
    for(ll i=0;i<=b-a;i++){
        if(range_arr[i]){
            cout<<a+i<<endl;
        }
    }
    cout<<endl;
}

int main(){
    cin>>t;
    bool prime[MAX];
    memset(prime, true, sizeof(prime));
    while(t--){
        cin>>a>>b;
        segmented_sieve(prime,a,b);
    }
}
