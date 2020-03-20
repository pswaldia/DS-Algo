//
//  SwappingUsingXOR.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//
 // without using any arithmetic operator and temporary variable

#include<iostream>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    cout<<"Before Swapping :"<<a<<" "<<b<<endl;
    a=a^b;b=a^b;a=a^b;
    cout<<"After Swapping :"<<a<<" "<<b<<endl;
}
