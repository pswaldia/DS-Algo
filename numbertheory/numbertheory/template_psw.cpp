//
//  template_psw.cpp
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

// calculating a^b % MOD
ll fastmoduloexpo(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b=b>>1;
    }
    return res;
}

