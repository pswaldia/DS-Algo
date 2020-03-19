//
//  a.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n,k;
    cin>>n>>k;
    int arr[n];
    int pos[n+1];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    pos[0]=-1;
    if(k<n){
        for(int i=0;i<n && k;i++){
            cout<<n-i<<endl;
            if(i==pos[n-i])
                continue;
            int temp=pos[n-i];
            pos[arr[i]]=temp;
            pos[n-i]=i;
            swap(arr[i],arr[temp]);
            k--;
        }
    }else{
        sort(arr,arr+n,greater<int>());
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
