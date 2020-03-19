//
//  MedianOf2SortedArrays.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 18/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;cin>>n;
    vector<int> a(n),b(n),c(2*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int i=0,j=0,k=0;
    while(i!=n && j!=n){
        if(a[i]<=b[j]){
            c[k]=a[i];
            k++;i++;
        }else{
            c[k]=b[j];
            k++;j++;
        }
    }
    while(i!=n){
        c[k]=a[i];
        i++;k++;
    }
    while(j!=n){
        c[k]=b[j];
        j++;k++;
    }
    cout<<(c[n]+c[n-1])/2<<endl;
}
