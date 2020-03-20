//
//  Leetcode1290.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x){
          val=x;next=NULL;
      }
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        ListNode* temp=head;
        while(temp!=NULL){
            s.push(temp->val);
            temp=temp->next;
        }
        int i=0,ans=0;
        while(!s.empty()){
            ans+=(pow(2,i)*s.top());
            s.pop();
            i+=1;
        }
        return ans;
    }
};

