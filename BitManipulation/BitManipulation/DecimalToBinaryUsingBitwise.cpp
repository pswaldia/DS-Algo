//
//  DecimalToBinaryUsingBitwise.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
using namespace std;

string BinaryRepresentation(int n){
    string binary="";
    for(int i=31;i>=0;i--){
        binary+=to_string((n>>i)&1);
    }
    return binary;
}

int main(){
    int n;
    cin>>n;
    cout<<BinaryRepresentation(n)<<endl;
    // one thing worth noticing is that -1 is represented as all 0s.
}
