//
//  oddEven.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
using namespace std;

string OddEven(int n){
    if(n&1)
        return "ODD";
    else
        return "EVEN";
}

bool ithbitsetornot(int n,int i){
    int mask=1<<i;
    if( (n&mask) > 0 )
        return true;
    else
        return false;
}

int Setithbit(int n,int i){
    int mask=1<<i;
    n=n|mask;
    return n;
}

int Clearithbit(int n,int i){
    int mask=~(1<<i);
    return n&mask;
}
int updateithbit(int n,int i,int v){
    return Clearithbit(n, i) | (v<<i);
}
int main(){
    int n,i;
    cin>>n>>i;
    cout<<OddEven(n)<<endl;
    string s=(ithbitsetornot(n, i))?"Yes":"No";
    cout<<"ith bit set? "<<s<<endl;
    cout<<"N after setting ith bit: "<<Setithbit(n, i)<<endl;
    cout<<"N after clearing ith bit: "<<Clearithbit(n, i)<<endl;
    int v=1;
    cout<<"N after updating ith bit with v(0 or 1) : "<<updateithbit(n, i,v)<<endl;

}
