//
//  UniqueNumber-II.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 21/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include</Users/pswaldia1/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;int xored=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        xored^=arr[i];
    }
    // find the position of a set bit in this xored....as this can never be 0.
    int pos=-1;
    for(int i=0;i<32;i++){
        if((xored>>i)&1){
            pos=i;break;
        }
    }
    int XorA=0,XorB=0;
    for(int i=0;i<n;i++){
        if((1<<pos)&arr[i])
            XorA^=arr[i];
        else
            XorB^=arr[i];
    }
    cout<<XorB<<" "<<XorA<<endl;
    
    
    
}
