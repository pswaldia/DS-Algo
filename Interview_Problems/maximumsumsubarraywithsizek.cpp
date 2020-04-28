//
//  maximumsumsubarraywithsizek.cpp
//  SlidingWindow
//
//  Created by Pradeep Singh on 27/04/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

// Input: [2, 1, 5, 1, 3, 2], k=3
// Output: 9
// Explanation: Subarray with maximum sum is [5, 1, 3].

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,k;cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++)    cin>>vec[i];
    int sum=0;
    for(int i=0;i<k;i++)    sum+=vec[i];
    int MaxSum=sum;
    for(int i=k;i<n;i++){
        sum=sum+vec[i]-vec[i-k];
        MaxSum=max(sum,MaxSum);
    }
    cout<<MaxSum<<endl;
}
