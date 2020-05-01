//
//  segmented_sieve.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 28/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

// Seqmented Sieve are used to find the primes between ranges [a,b] where a is very large (not fitting in memory) and same for b. But |b-a| is manageable.
// |b-a|<=10^6

#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

ll a,b;

void sieveoferatosthenes(bool* prime){
    for(ll i=2;i*i<=b;i++){
        if(prime[i]){
            for(ll j=i*i;j<=b;j+=i){
                prime[j]=false;
            }
        }
    }
}
void segmentedSieve(bool* prime,bool* segmented_sieve){
    
    for(ll i=2;i*i<=b;i++){
        for(ll j=0;j<b-a+1;j++){
            if((a+j)==i)
                continue;
            if(prime[i]){
                if((a+j)%i==0)
                    segmented_sieve[j]=false;
            }
        }
}
}


int main(){
    cin>>a>>b;
    ll size=sqrt(b);
    bool prime[size];
    bool segmented_sieve[b-a+1];
    memset(segmented_sieve, true, sizeof(segmented_sieve));
    memset(prime, true, sizeof(prime));
    sieveoferatosthenes(prime);
    segmentedSieve(prime,segmented_sieve);
    for(ll j=0;j<b-a+1;j++){
        if(segmented_sieve[j])
            cout<<a+j<<" ";
    }
    cout<<endl;
}
