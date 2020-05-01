//
//  code_forces1.cpp
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
#define MAX 1000000
#define ll long long
using namespace std;

ll a,m,x,t;

ll gcd(ll a, ll m){
    return m==0?a:gcd(m,a%m);
}

int main(){
    cin>>t;
    while(t--){
        cin>>a>>m;
        ll lhs=gcd(a,m);
        ll res=0;
        for(ll i=0;i<m;i++){
            if(lhs==gcd(a+i,m))
            res+=1;
        }
        cout<<res<<endl;
    }
}
