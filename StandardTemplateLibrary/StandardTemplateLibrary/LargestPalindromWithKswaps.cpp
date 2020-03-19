//
//  LargestPalindromWithKswaps.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 18/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    long long arr[n];
    long long pos[n+1];pos[0]=-1;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    if(k>=n){
        sort(arr,arr+n,greater<>());
    }else{
    for(long long i=0;i<n &&k;i++){
        if(arr[i]==n-i)
            continue;
        long long temp = pos[n-i];

        pos[arr[i]] = pos[n-i];
        pos[n-i] = i;

        swap(arr[temp], arr[i]);
        k--;
    }
    }
    for(long long i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
