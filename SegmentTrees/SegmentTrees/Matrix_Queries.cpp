//
//  Matrix_Queries.cpp
//  SegmentTrees
//
//  Created by Pradeep Singh on 28/03/2020.
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

struct matrices{
    vector<vector<ll>> matrix;
};

struct trees{
    vector<vector<ll>> matrix;
};


vector<vector<ll>> matrix_multiplication(vector<vector<ll>>&m,vector<vector<ll>>&n,ll r){
    vector<vector<ll>> result={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                result[i][j]+=m[i][k]*n[k][j];
            }
            result[i][j]%=r;
        }
    }
    return result;
}

void build_tree(matrices *M,trees Tree[],ll start_index,ll end_index,ll index,ll r){
    if(start_index==end_index){
        Tree[index].matrix=M[start_index].matrix;
        return;
    }
    ll mid=(start_index+end_index)/2;
    build_tree(M, Tree, start_index, mid, 2*index,r);
    build_tree(M, Tree, mid+1,end_index, 2*index+1,r);
    Tree[index].matrix = matrix_multiplication(Tree[2*index].matrix,Tree[2*index+1].matrix,r);
    return;
}

vector<vector<ll>> queries(trees Tree[],ll start_index,ll end_index,ll qs,ll qe,ll index,ll r){
    // complete overalap
    if(qs<=start_index && qe>=end_index){
        return Tree[index].matrix;  // simply return the ans.
    }
    // no overalap
    if( qs>end_index || qe<start_index ){
        return {{1,0},{0,1}};  // when no overlap just return identity matrix;
    }
    // partial overlap condition
    ll mid=(start_index+end_index)/2;
    vector<vector<ll>> leftMatrix=queries(Tree, start_index, mid, qs, qe, 2*index,r);
    vector<vector<ll>> rightMatrix=queries(Tree, mid+1, end_index, qs, qe, 2*index+1,r);
    return matrix_multiplication(leftMatrix, rightMatrix, r);
}

int main(int argc, const char * argv[]) {
    fast_io();
    ll r,n,q;
    cin>>r>>n>>q;
    matrices M[n];
    trees Tree[4*n+1];
    for(int i=0;i<4*n+1;i++){
        Tree[i].matrix.assign({{1,1},{1,1}});
    }

    for(int i=0;i<n;i++){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        M[i].matrix={{a%r,b%r},{c%r,d%r}};
    }
    
    build_tree(M, Tree, 0, n-1, 1,int(r));
    ll L,R;
    while(q--){
        cin>>L>>R;
       vector<vector<ll>>  result = queries(Tree, 0, n-1, L-1, R-1, 1,r);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}


