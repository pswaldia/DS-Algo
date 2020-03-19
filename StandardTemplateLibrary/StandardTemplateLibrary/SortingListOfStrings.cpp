//
//  SortingListOfStrings.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 17/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool compare(string a,string b){
    return a.length()<b.length();
}

int main(){
    int n;cin>>n;
    cin.get();
    vector<string> vec(n);
    for(int i=0;i<n;i++){
        getline(cin,vec[i]);
    }
    sort(vec.begin(),vec.end(),compare); // sorting based on length...custom comparator
    for(string x:vec){
        cout<<x<<endl;
    }
}
