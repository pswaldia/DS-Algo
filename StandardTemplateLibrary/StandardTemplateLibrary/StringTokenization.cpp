//
//  StringTokenization.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 17/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    char c[100]="pradeep is a good boy";
    cout<<c<<endl;
    char* ptr=strtok(c, " ");
    cout<<ptr<<endl;
    while(ptr!=NULL){
        ptr=strtok(NULL, " ");
        cout<<ptr<<endl;
    }
    
}
