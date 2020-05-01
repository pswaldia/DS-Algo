//
//  pass_xor_fail.cpp
//  numbertheory
//
//  Created by Pradeep Singh on 01/02/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include<math.h>
#include<vector>
#define ull unsigned long long
using namespace std;
ull r;
int main(){
    cin>>r;
    vector<int> precompute(3);
    precompute[0]=0;precompute[1]=1;precompute[2]=3;
    if(r<=2){
        cout<<precompute[r]<<endl;
        return 0;
    }
    if( (r+1)%4==0 ){
        cout<<0<<endl;
        return 0;
    }
    if((r-1+1)%4==0){
        cout<<r<<endl;
        return 0;
    }
    if((r-2+1)%4==0){
        cout<<1<<endl;
        return 0;
    }
    if( (r-3+1)%4==0 ){
        cout<<r+1<<endl;
        return 0;
    }
    
}
