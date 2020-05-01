//
//  multiplicative-modulo-inverse.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 02/02/2020.
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

ll x,y;
void extended(ll a,ll b){
    if(b==0){
        x=1;y=0;
        return;
    }
    extended(b, a%b);
    ll cx=y;
    ll cy=x-(a/b)*y;
    x=cx;
    y=cy;
    // extra cx and cy are needed because x and y are used further also.
}


void modInverse(ll a,ll b){
    extended(a,b);
}

using namespace std;
ll a,b;
int main(){
    cin>>a>>b;
    modInverse(a, b);
    cout<<(x+b)%b<<endl;   // to make ans positive if negative is encountered.
}
