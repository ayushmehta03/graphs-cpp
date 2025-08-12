#include<iostream>
#include<queue>
using namespace std;

int minimumEffortPath(vector<vector<int>>&heights,vector<vector<int>>&distance){
    priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>> >,
        greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    distance[0][0]=0;
    int n=heights.size();
    int m=heights[0].size();
    while(!pq.empty()){
        auto it=pq.top();
        int diff=it.first;
        int row=it.second.first;
        int col=it.second.second;
        pq.pop();
        if(row==n-1 &&col==m-1) return diff;
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m){
            int newEffort=max(abs(heights[row][col]-heights[nRow][nCol]),diff);
            if(distance[nRow][nCol]>newEffort){
            distance[nRow][nCol]=newEffort;
                pq.push({newEffort,{nRow,nCol}});



            }
            }
        }

    }
        return 0;


}
int main(){
   vector<vector<int>>heights={

   { 1,2,2},{3,8,2},{5,3,5}
   };
   int n=heights.size();
   int m=heights[0].size();
   vector<vector<int>>distance(n,vector<int>(m,1e9));
   int result=minimumEffortPath(heights,distance);
    cout << result << endl; 
    return 0;

}


