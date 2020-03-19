//
//  lengthofallsubstringwithdistinctelements.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 18/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int size=n;
    unordered_map<int, int> map;
    int j=0;
    int ans=0;
    for(int i=0;i<size;i++){
        while(j<size && map.find(arr[j])==map.end()){
            map[arr[j]]++;
            j++;
        }
        ans+=((j-i)*(j-i+1))/2;
        map.erase(arr[i]);
    }
    cout<<ans<<endl;
}
