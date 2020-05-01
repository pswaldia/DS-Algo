//
//  gcd_lcm.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*
 Euclid's algorithm : gcd(a,b)=gcd(b,a%b)   and base_case gcd(a,0)=a;
*/

#include<iostream>
#define ll long long
using namespace std;

ll t,a,b;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b, ll gcdd){
    return (a*b)/gcdd;
}
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<gcd(a, b)<<" "<<lcm(a,b,gcd(a,b))<<endl;
    }
}


