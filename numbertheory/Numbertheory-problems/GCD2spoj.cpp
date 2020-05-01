//
//  GCD2spoj.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 07/02/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
#include<cstring>
#include<string.h>
#include<queue>
#include<stack>
#include<list>

#define MOD 1000000007
#define MAX 1000000
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;
ull a,t;
string b;

ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}


int main(){
    cin>>t;
    while(t--){
    cin>>a>>b;
    // finding gcd(b,a) == gcd(a,b%a)
        if(a==0){
        cout<<b<<endl;
            continue;
        }
        ull res=0;
    for (int i = 0; i < b.length(); i++)
        res = (res*10 + (int)b[i] - '0') %a;
    cout<<gcd(a,res)<<endl;
}
    
}

