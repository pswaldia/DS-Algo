//
//  LongestSubstringWithDistinctCharacterK.cpp
//  SlidingWindow
//
//  Created by Pradeep Singh on 27/04/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int k;cin>>k;
    string str;
    cin>>str;
    int n=(int)str.length();
    int LongestSubarrayWithKDistinctChar=INT_MIN;
    unordered_map<char, int> track;
    int start_index=0;

    for(int i=0;i<n;i++){
        track[str[i]]++;
        if(track.size()==k){
            LongestSubarrayWithKDistinctChar=max(LongestSubarrayWithKDistinctChar,i-start_index+1);
        }
        while(track.size()>k){
            int key=str[start_index];
            track[key]--;
            if(track[key]==0)   track.erase(key);
            start_index++;
        }
    }
    cout<<LongestSubarrayWithKDistinctChar<<endl;
}
