//
//  Leetcode1342.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/
#include<iostream>
using namespace std;

int main(){
    int num;cin>>num;
    int ans=num?__builtin_popcount(num)+31-__builtin_clz(num):0;
    cout<<ans<<endl;
}
