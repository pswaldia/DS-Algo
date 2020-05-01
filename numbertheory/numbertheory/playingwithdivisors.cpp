//
//  playingwithdivisors.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 31/01/2020.
//  Copyright © 2020 Pradeep Singh. Aull rights reserved.
//

#include<iostream>
#include<vector>
#include<cstring>
#define MOD 1000000007
#include<math.h>
#include<unordered_map>
#define ull unsigned long long
#define MAX 1000000
using namespace std;
ull x,num;



unordered_map<ull, ull> find_prime_factorisation(ull n){
    unordered_map<ull, ull> res;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ull count=0;
                while(n%i==0){
                    n=n/i;
                    count++;
                }
                res[i]+=count;
            }
        }
        if(n!=1)
            res[n]++;
        return res;
    }

ull fast_exponentiation(ull a , ull n){
    if(n==0)
        return 1;
    else{
        ull smallresult=fast_exponentiation(a, n/2);
        smallresult=(smallresult*smallresult)%MOD;
        if(n&1)
            smallresult=(a*smallresult)%MOD;
        return smallresult;
    }
}

int main() {
    cin>>x;
    vector<ull> vec;
    vector<ull> X;
    ull num_divisor=1;
    for(ull i=0;i<x;i++){
        cin>>num;
        num_divisor=(num_divisor*(num+1))%MOD;
        vec.push_back(num);
    }
    ull final_ans=1;
    ull bi=1;
    for(int i=0;i<x;i++){
        bi=(vec[i]*(num_divisor/2))%MOD;
        final_ans=(final_ans*(bi+1))%MOD;
    }
    cout<<final_ans<<endl;
}

