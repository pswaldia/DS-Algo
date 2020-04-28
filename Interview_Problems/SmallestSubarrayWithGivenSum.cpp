//
//  SmallestSubarrayWithGivenSum.cpp
//  SlidingWindow
//
//  Created by Pradeep Singh on 27/04/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,k;cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++)    cin>>vec[i];
    int minsize=INT_MAX,StartOfWindow=0;
    int SumOfWindow=0;
    for(int i=0;i<n;i++){
        SumOfWindow+=vec[i];
        while(SumOfWindow>=k){
            minsize=min(minsize,i-StartOfWindow+1);
            SumOfWindow=SumOfWindow-vec[StartOfWindow];
            StartOfWindow++;
        }
    }
    if(minsize!=INT_MAX)
        cout<<minsize<<endl;
    else
        cout<<0<<endl;
    
}
