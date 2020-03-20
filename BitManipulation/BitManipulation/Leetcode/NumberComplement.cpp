//
//  NumberComplement.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    string BinaryRepresentation(int n){
        string binary="";
        int length=32 - __builtin_clz(n);
        cout<<length<<endl;
        for(int i=length-1;i>=0;i--){
            binary+=to_string((n>>i)&1);
        }
        string res="";
        for(char ch:binary){
            if(ch=='1') res+='0';
            else res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int findComplement(int num) {
        string s=BinaryRepresentation(num);
        cout<<s<<endl;
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans+=(pow(2,i)*(s[i]-'0'));
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.findComplement(5)<<endl;
}
