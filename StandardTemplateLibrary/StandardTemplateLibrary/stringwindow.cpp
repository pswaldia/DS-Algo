//
//  stringwindow.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 18/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int map[256]={0};
    int map2[256]={0};
    for(char c:b){
        map2[c]++;
    }
    int count=0,start=0,min_length=INT_MAX,start_index=-1;
    for(int i=0;i<a.length();i++){
        map[a[i]]++;
        if(map2[a[i]]!=0 && map[a[i]]<=map2[a[i]])
            count+=1;
        if(count==b.length()){
            // try to minimise the length of the obtained string
            while( map[a[start]]>map2[a[start]] or map2[a[start]]==0 ){
                if(map[a[start]]>map2[b[start]])
                    map[a[start]]--;
                start++;
            }
            if( i-start+1 < min_length )
            {
                min_length=i-start+1;
                start_index=start;
            }
        }
    }
    if(start_index==-1)
        cout<<"No String Window"<<endl;
    else
        cout<<a.substr(start_index,min_length)<<endl;
}

