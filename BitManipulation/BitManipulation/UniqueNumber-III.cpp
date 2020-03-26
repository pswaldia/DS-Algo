//
//  UniqueNumber-III.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 21/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include</Users/pswaldia1/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // store the number of set bits in 32 sized array (O(1) space time complexity.)
    int ThirtyTwoBitSizedArray[32]={0};
    for(int num:arr){
        for(int i=0;i<32;i++){
            ThirtyTwoBitSizedArray[i]+=(num>>i)&1;
        }
    }
    for(int i=0;i<32;i++){
        ThirtyTwoBitSizedArray[i]%=3;
    }
    long long ans=0;
    for(int i=31;i>=0;i--){
        ans+=pow(2,i)*ThirtyTwoBitSizedArray[i];
    }
    cout<<ans<<endl;

    
    
}
