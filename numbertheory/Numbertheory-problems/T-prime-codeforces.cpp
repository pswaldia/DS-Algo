//
//  T-prime-codeforces.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*  Squares of a prime number are T-primes: since xi<=10^12 , its not possible to create such a large sieve. make sieve for x<=10^6.
 and then square all primes and store in hashmap.... now for every query check if it is present in square of all primes hashmap.O(1)
 */
#include <iostream>
#include <vector>
#include<cstring>
#include <unordered_map>
#include <math.h>
#define MAX 1000000
#define ll long long
using namespace std;

ll n,num;

unordered_map<ll, ll> sieveoferatosthenes(bool* prime){
    for(int i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(ll j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
    unordered_map<ll, ll> t_primes;
    for(ll i=2;i<=MAX;i++){
        if(prime[i])
            t_primes[i*i]=1;
        else
            continue;
    }
    return t_primes;
}

int main(){
    cin>>n;
    bool prime[MAX];
    memset(prime, true, sizeof(prime));
    unordered_map<ll, ll> t_primes;
    t_primes=sieveoferatosthenes(prime);
    while(n--){
        cin>>num;
        if(t_primes.find(num)!=t_primes.end())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
