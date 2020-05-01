//
//  main.cpp
//  codeforces_edu81
//
//  Created by Pradeep Singh on 29/01/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#define ll long long
using namespace std;

string s,t,x;
ll T;
int main(){
    cin>>T;
    ll count[26];
    memset(count,0,sizeof(count));
    while(T--){
        cin>>s>>t;
        for(char x:t)
            count[x-'a']++;
        for(int i=0;i<26;i++){
            if(count[i]!=0 && s.find(i+'a')==string::npos){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        
    
    }
}

