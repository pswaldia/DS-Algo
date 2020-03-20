//
//  main.cpp
//  BitManipulation
//
//  Created by Pradeep Singh on 19/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

// O(n) and O(1) space

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,num;
    cin>>n;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>num;
        res^=num;
    }
    cout<<res<<endl;
}
