//
//  main.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 08/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
    return b>a;
}

void bubble_sort(int arr[],int n,bool(&compare)(int a,int b)){
    // we will use compare inside now.
    for(int i=0;i<n-i;i++){
        for(int j=0;j<n-i-1;j++){
            if(compare(arr[j],arr[j+1])){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr[]={100,1,34,56};
    bubble_sort(arr, 4, compare);   // passing function as parameter
    for(int x:arr)
        cout<<x<<" ";
    cout<<endl;
}
