//
//  XOrQueries.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//


#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        long long n=arr.size();
        int xor_prefix[n];
        memset(xor_prefix, 0, n);
        xor_prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            xor_prefix[i]=arr[i]^xor_prefix[i-1];
        }
        vector<int> res;
        for(auto q:queries){
            if(q[0]==0)
                res.push_back(xor_prefix[q[1]]);
            else
                res.push_back( xor_prefix[q[0]-1]^xor_prefix[q[1]]);
        }
        return res;
    }
};

