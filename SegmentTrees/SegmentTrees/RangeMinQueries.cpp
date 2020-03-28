//
//  main.cpp
//  SegmentTrees
//
//  Created by Pradeep Singh on 27/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define str(a) to_string(a)
#define ll long long
#define pb push_back
#define mp make_pair
#define SORT(c) sort(c.begin(),c.end())

void fast_io(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}
int setbitcount(int a){ return __builtin_popcount(a); }

void BuildTree(int* a, int start_index,int end_index,vector<int>&tree,int index){
    // start_index:start and end_index:end index of range......
    if(start_index==end_index){
        tree[index]=a[start_index];
        return;
    }
    // recursive case
    int mid=(start_index+end_index)/2;
    BuildTree(a, start_index, mid, tree, 2*index);  // for left subtree
    BuildTree(a, mid+1, end_index, tree, 2*index+1); // for right subtree
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
    
}

// Queries.....complete overlap cases are easy to handle
int queries(vector<int>&tree,int start_index,int end_index,int qstart,int qend,int index){
    // complete overlap
    if( start_index>=qstart && end_index<=qend ){
        return tree[index];
    }
    // No overlap
    if( ( start_index>qend ) || (qstart>end_index) ){
        return INT_MAX;
    }
    // partial overlap
    int mid=(start_index+end_index)/2;
    int leftAns=queries(tree, start_index, mid, qstart, qend, 2*index);
    int rightAns=queries(tree, mid+1, end_index, qstart, qend, 2*index+1);
    return min(leftAns,rightAns);
}

void updateNode(vector<int>&tree,int update_index,int increment,int start_index,int end_index,int index){
     // outofbound
    if(update_index<start_index || update_index>end_index){
        return;
    }
    // leaf node
    if(start_index==end_index){
        tree[index]+=increment;
        return;
    }
    int mid=(start_index+end_index)/2;
    updateNode(tree, update_index, increment, start_index, mid, 2*index);
    updateNode(tree, update_index, increment, mid+1, end_index, 2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void updateRange(vector<int>& tree,int range_start,int range_end,int increment,int start_index,int end_index,int index){
    
    if(range_start>end_index || range_end<start_index){
        return;
    }
    if(start_index==end_index){
        tree[index]+=increment;
        return;
    }
    int mid=(start_index+end_index)/2;
    updateRange(tree, range_start, range_end, increment, start_index, mid, 2*index);
    updateRange(tree, range_start, range_end, increment, mid+1, end_index, 2*index+1);
    tree[index]=min(tree[2*index+1],tree[2*index]);
    return;
}

int main(int argc, const char * argv[]) {
    fast_io();
    int a[]={1,3,2,-5,6,4};
    int N=sizeof(a)/sizeof(int);
    vector<int> tree(4*N+1,0);
    BuildTree(a, 0, N-1, tree, 1);
    for(int i=1;i<4*N+1;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<queries(tree, 0, N-1, 0, 5, 1)<<endl;
    updateNode(tree, 3, 7, 0, N-1, 1);
    updateNode(tree, 2, 10, 0, N-1, 1);
    for(int i=1;i<4*N+1;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<queries(tree, 0, N-1, 0, 2, 1)<<endl;
    cout<<queries(tree, 0, N-1, 0, 3, 1)<<endl;
    cout<<queries(tree, 0, N-1, 3, 5, 1)<<endl;
    return 0;
}


