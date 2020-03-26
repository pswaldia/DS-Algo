//
//  NotSoEasyMath.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 25/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define str(a) to_string(a)
#define ll long long
#define pb push_back
#define VI vector<ll>
#define mp make_pair
#define SORT(c) sort(c.begin(),c.end())

void fast_io(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}
int setbitcount(int a){ return __builtin_popcount(a); }

ll HelperFunction(vector<int> primes,ll n,int i){
    VI s;
    for(int j=0;j<primes.size();j++){
        if((i>>j)&1){
            s.pb(primes[j]);
        }
    }
    ll product=1;
    for(ll k:s){
        product*=(k);
    }
    return floor(double(n/product));
}

int main(int argc, const char * argv[]) {
    fast_io();
    ll n;cin>>n;
    vector<int> primeslessthan20={2,3,5,7,11,13,17,19};
    ll num;
    while(n--){
        cin>>num;
        ll ans=0;
        ll k=primeslessthan20.size();
        for(int i=1;i<(1LL<<(k));i++){
            if(setbitcount(i)%2==0){
                ll temp=HelperFunction(primeslessthan20,num,i);
                ans-=temp;
            }else{
                ll temp=HelperFunction(primeslessthan20,num,i);
                ans+=temp;
            }
        }
        cout<<ans<<endl;
    }
}


