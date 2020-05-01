//
//  isprime.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 27/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.



#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

// checks if n is a prime number or not in O(N)
bool isPrime_(ll n){
    if(n==1)
        return false;
    if(n==2)
        return true;
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
// checks if n is a prime or not in sqrt(n)
// this works because...if a number less than sqrt(n) divides n then
// there is certainly a number greater than sqrt(n) that divides n.
// hence we need to check till sqrt(n) only.
bool isPrime(ll n){
    if(n==1)
        return false;
    if(n==2)
        return true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

// checks if n is a prime or not in O(n/2)
bool isPrime__(ll n){
    if(n==1)
        return false;
    if(n==2)
        return true;
    for(int i=2;i<=n/2;i++){
        if(n%i==0)
            return false;
    }
    return true;
}


int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(isPrime(n))
            cout<<"Prime"<<endl;
        else
            cout<<"Not Prime"<<endl;
    }

}
