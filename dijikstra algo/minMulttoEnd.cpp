#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int getMinSteps(int start,int end,vector<int>&arr){
 queue<pair<int,int>>q;
 // node and steps
 q.push({start,0});
 
 vector<int>dist(100000,1e9);
 int mod=100000;
 dist[start]=0;


 while(!q.empty()){
    int node=q.front().first;
    int steps=q.front().second;
    q.pop();
    for(auto it:arr){
        int num=(it*node)%mod;
        if(steps+1<dist[num]){
            dist[num]=steps+1;
        }
        if(num==end) return steps+1;
        q.push({num,steps+1});
    }
 }
 return -1;
}

int main(){
   int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    int ans=getMinSteps(start,end,arr);
    cout<<"Minimu steps taken to reach the end from start is"<<" "<<ans;



}