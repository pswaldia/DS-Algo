//
//  HostelVisit.cpp
//  StandardTemplateLibrary
//
//  Created by Pradeep Singh on 18/03/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.
//

/*Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels. Hostels are situated in 2D plane. You are given the coordinates of hostels and you have to answer the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .
                                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                            Input Format
                                                                                                                                                                                                                                                                                  First line of input contains Q Total no. of queries and K There are two types of queries:
 
                                                                                                                                                                                                                                                                                  first type : 1 x y For query of 1st type, you came to know about the co-ordinates ( x , y ) of newly constructed hostel. second type : 2 For query of 2nd type, you have to output the Rocket distance of Kth nearest hostel till now.
 
                                                                                                                                                                                                                                                                                  The Dean will always stay at his place ( origin ). It is gauranted that there will be atleast k queries of type 1 before first query of type 2.
 
                                                                                                                                                                                                                                                                                  Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2
 */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    long long q,k,task,x,y;
    cin>>q>>k;
    priority_queue<long long> pq;  // we require a min heap
    while(q--){
        cin>>task;
        if(task==1){
            cin>>x>>y;
            long long distance=x*x+y*y;
            if(pq.size()<k)
                pq.push(distance);
            else{
                if(pq.top()>distance){ //if the distance is smaller than the current top. remove the
                    pq.pop();
                    pq.push(distance);
                }
            }
        }else{
            cout<<pq.top()<<endl;
        }
    }
}
