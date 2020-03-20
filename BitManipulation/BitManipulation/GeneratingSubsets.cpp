//
//  GeneratingSubsets.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

vector<int> extract(int n,int arr[]){
    vector<int> res;
    for(int i=0;i<n;i++){
        int y=(n>>i)&1;
        if(y)
            res.push_back(arr[i]);
    }
    return res;
}

vector<vector<int>> FindPowerSet(int arr[],int n){
    int N=(1<<n)-1;
    cout<<"Number of subsets in powerset: "<<N+1<<endl;
    vector<vector<int>> result(N+1,vector<int>());
    int count=0;
    for(int i=0;i<=N;i++){
        count+=1;
        result.push_back(extract(i, arr));
    }
    return result;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> powerset=FindPowerSet(arr,n);
    for(auto subset:powerset){
        if(subset.size()==0){
            continue;
        }
        for(int i=0;i<subset.size();i++){
            cout<<subset[i]<<" ";
        }
        cout<<endl;
    }
}
