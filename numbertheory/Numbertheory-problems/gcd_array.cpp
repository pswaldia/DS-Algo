//
//  gcd_array.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 01/02/2020.
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

ll n,num;

// O(log2(max(a,b)))
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

// O(n*log2(max(a,b)))
ll gcd_array(vector<ll> vec){
    ll res=vec[0];
    for(ll i=1;i<vec.size();i++){
        res=gcd(res,vec[i]);
        if(res==1)
            return res;
    }
    return res;
}

int main(){
    cin>>n;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++)
        cin>>vec[i];
    cout<<gcd_array(vec)<<endl;
}
