//
//  extended_euclid.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 31/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long
using namespace std;
ll a,b,x,y;

void solve(ll a, ll b){
    if(b==0){
        x=1;y=0;
        return;
    }
    solve(b, a%b);
    ll cx=y;
    ll cy=x-(a/b)*y;
    x=cx;
    y=cy;
}

int main(){
    // solving an eqxn of type ax+by=gcd(a,b).
    cin>>a>>b;
    solve(a,b);
    cout<<x<<" "<<y<<endl;
}
