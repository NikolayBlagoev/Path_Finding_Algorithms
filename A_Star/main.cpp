
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <cmath> 
#include "astar.h"
using namespace std;

int heuristic(int y1, int x1, int y2, int x2){
    return abs(y1 - y2)+abs(x1-x2);
}

bool runAStar(Map &mp,  int yStart, int xStart, int yGoal, int xGoal){
    priority_queue<Node,vector<Node>, CompareFunc > pq;
    bool visited[mp.y][mp.x];
    for(int i =0; i<mp.y; i++) {
        for(int j = 0; j < mp.x; j++){
            visited[i][j]=false;
        }
        
    }
    Node* nd = new Node(NULL, yStart, xStart,0,heuristic(yStart, xStart, yGoal, xGoal));
    pq.push(*nd);

    while(!pq.empty()){
        Node curr = pq.top();
        
        
        pq.pop();
        visited[curr.y][curr.x] = true;
        if(curr.y == yGoal && curr.x == xGoal){
            while(curr.prev!=NULL){
                mp.map[curr.y][curr.x]=2;
                curr = *(curr.prev);
                
            }
            mp.map[curr.y][curr.x]=2;
            return true;
        }
        
        if(curr.y-1 >=0  && !visited[curr.y-1][curr.x] && mp.map[curr.y-1][curr.x]!=1){
            Node* temp = new Node(curr.self,curr.y-1, curr.x,curr.gn+1,curr.gn+1+heuristic(curr.y-1, curr.x, yGoal, xGoal));
            
            pq.push(*temp);
        }
        if(curr.y+1 < mp.y && !visited[curr.y+1][curr.x] && mp.map[curr.y+1][curr.x]!=1){
            Node* temp = new Node(curr.self,curr.y+1, curr.x,curr.gn+1,curr.gn+1+heuristic(curr.y+1, curr.x, yGoal, xGoal));
            pq.push(*temp);
        }
        if( curr.x-1 >= 0 && !visited[curr.y][curr.x-1] && mp.map[curr.y][curr.x-1]!=1){
            Node* temp = new Node(curr.self,curr.y, curr.x-1,curr.gn+1,curr.gn+1+heuristic(curr.y, curr.x-1, yGoal, xGoal));
            pq.push(*temp);
        }
        if(curr.x+1 < mp.x && !visited[curr.y][curr.x+1] && mp.map[curr.y][curr.x+1]!=1){
            Node* temp = new Node(curr.self,curr.y, curr.x+1,curr.gn+1,curr.gn+1+heuristic(curr.y, curr.x+1, yGoal, xGoal));
            pq.push(*temp);
        }
    }
    return false;
}

int threshold = 65;
int main() {
    Map mp(15, 15);
    mt19937 rng(time(0));
    
    for(int i = 0; i<mp.y; i++) {
        for(int j = 0; j < mp.x; j++){
            if(rng()%100 > threshold) mp.map[i][j] = 1;
        }
    }
    mp.map[mp.y-1][mp.x-1]=0;
    mp.map[0][0]=0;
    mp.map[0][1]=0;
    mp.map[1][0]=0;
    mp.map[1][1]=0;
    if(!runAStar(mp, 0, 0, mp.y-1, mp.x-1)){
        cout<<"NO SOLUTION"<<endl;
    }
    for(int i =0; i<mp.y; i++) {
        for(int j = 0; j < mp.x; j++){
            cout<<mp.map[i][j]<<" ";
        }
        cout<<endl;
    }

}