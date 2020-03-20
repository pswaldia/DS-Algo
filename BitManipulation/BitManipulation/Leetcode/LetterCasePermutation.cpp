//
//  LetterCasePermutation.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 20/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*
 Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a
 list of all possible strings we could create.


 */

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<char> extract(vector<char> c,int n){
        long long length=c.size(); vector<char> res; char ch;
        for(int i=0;i<length;i++){
            if( ((n>>i)&1) == 1)
                ch=toupper(c[i]);
            else
                ch=tolower(c[i]);
            res.push_back(ch);
        }
        return res;
        
    }
    vector<string> letterCasePermutation(string S) {
        // number of strings possible is 2^(no. of letters)
        vector<char> letters;
        for(int i=0;i<S.length();i++){
            char ch=S[i];
            if(!isdigit(ch))
                letters.push_back(ch);
        }
        vector<vector<char>> result;
        long long n=letters.size();
        for(int i=0;i < (1<<n); i++){
            result.push_back(extract(letters,i));
        }
        vector<string> res;
        for(auto vec:result){
            int i=0;string r="";
            for(char ch:S){
                if(isdigit(ch)) r+=ch;
                else{
                    r+=vec[i];i+=1;
                }
            }
            res.push_back(r);
        }
        return res;
    }
};

