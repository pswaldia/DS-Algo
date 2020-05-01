//
//  findit.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*
 You are given N numbers.
 Now you have Q queries.
 For each query you will be given an integer K.
 You have to find out the number of multiples of K among the given N numbers.
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<unordered_map>
#define ll long long
#define pb push_back
using namespace std;
ll n,q,num,k;

int main(){
    vector<ll> vec;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>num;
        vec.push_back(num);
    }
    ll MAX = *max_element(vec.begin(), vec.end());
    ll count[MAX + 1];
    ll* ans = new ll[MAX + 1];
   
   // Initialize both arrays as 0.
   memset(count, 0, sizeof(count));
   memset(ans, 0, (MAX + 1) * sizeof(ll));
    
    for (int i = 0; i < n; ++i)
        ++count[vec[i]];
    
    unordered_map<ll, ll> x;
    for(ll num:vec)
        x[num]++;
    vector<ll> visited;
    for(auto itr=x.begin();itr!=x.end();itr++){
        visited.push_back(itr->first);
    }
    for(ll i=2;i<=MAX;i++){
        for(ll j=i;j<=MAX;j+=i){
                ans[i]+=count[j];
    }
    }
    cin>>q;
    while(q--){
        cin>>k;
        if(k==1)
            cout<<n<<endl;
        else
            cout<<ans[k]<<endl;
    }
}
