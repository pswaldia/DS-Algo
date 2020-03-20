//
//  Lengthofbinaryrepresentation.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

string BinaryRepresentation(int n){
    string binary="";
    for(int i=31;i>=0;i--){
        binary+=to_string((n>>i)&1);
    }
    return binary;
}

// not O(1)
int length(int num){
    return log2(num)+1;
}


int main(){
    int num;
    cin>>num;
    //O(1) time complexity. better than log2(n) which is complex computationally
    
    int ans = 32-__builtin_clz(num);   // make sure num is not 0, __bultin_clz is not defined in that case.
    
    cout<<BinaryRepresentation(num)<<endl;
    
    cout<<length(num)<<endl;
    cout<<ans<<endl;
    int i=3;int j=1;
    while(j!=num){
        cout<<BinaryRepresentation(i)<<endl;
        i*=3;
        j++;
    }
    cout<<endl;
    
}
