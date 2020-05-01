//
//  T-prime.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.

/* a positive integer t Т-prime, if t has exactly three distinct positive divisors.
You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.
 n<=10^5
 xi<=10ˆ12

 1st approach: for every n, check for t prime in O(sqrt(xi))
  10^5 * (10^6) = 10^11 .... may result in TLE.
 2nd approach : Squares of a prime numbers are T primes..... because if p is prime, p^2 is only divisible by 1, p and p^2. This
 is a property.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#define MAX 1000000
#define ll long long
using namespace std;

ll n,num;
bool t_prime(ll x){
    ll count=0;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            if(i!=x/i)
                count+=2;  // one factor i other one is x/i;
            else
                count+=1;  // only 1 incr coz 1 will be incremented
        }
        if(count==3)
            return true;
    }
    return false;
}

int main(){
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>num;
        if(t_prime(num))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
