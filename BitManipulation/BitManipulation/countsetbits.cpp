//
//  countsetbits.cpp
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

// O(Log(n))
int FindSetBitsCount(int n){
    int count=0;
    while(n!=0){
        if(n&1) count+=1;
        n=n>>1;
    }
    return count;
}
// O(number of set bits) . In worst case O(Logn) if all bits set.
int findsetbitsfast(int n){
    int count=0;
    while(n!=0){
        n=n&(n-1);
        count+=1;
    }
    return count;
}
int main(){
    int n;cin>>n;
    cout<<BinaryRepresentation(n)<<endl;
    cout<<FindSetBitsCount(n)<<endl;
    cout<<findsetbitsfast(n)<<endl;
    // 3rd method......inbuilt functionality. actually built for gcc but backwards compatibility makes it possible for c++ also.
    cout<<__builtin_popcount(n)<<endl;

}
