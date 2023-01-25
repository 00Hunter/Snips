/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
 vector<int> rank,parent,size;
 
    public:
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findParent(int node){
        
        if(node==parent[node]){
            return node;
        }
        //pathcompression
        return parent[node]=findParent(parent[node]);
    }
    
    void unionByRank(int u,int v){
        
        int ultp_u=findParent(u);
        int ultp_v=findParent(v);
        
        if(rank[ultp_u]<rank[ultp_v]){
            parent[ultp_u]=ultp_v;
        }
        else if(rank[ultp_v]<rank[ultp_u]){
                 parent[ultp_v]=ultp_u;
        }
        else {
             parent[ultp_u]=ultp_v;
             rank[ultp_u]++;
        }
    }
    void unionBySize(int u,int v){
        
        int ultp_u=findParent(u);
        int ultp_v=findParent(v);
        
        if(size[ultp_v]<size[ultp_u]){
            parent[ultp_v]=ultp_u;
            size[ultp_u]=size[ultp_v]+size[ultp_u];
        }
        else{
             parent[ultp_u]=ultp_v;
            size[ultp_v]=size[ultp_u]+size[ultp_v];
        }
    }
};

int main()
{
    DisjointSet ds (7);
    
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    
    if(ds.findParent(1)==ds.findParent(7)){
        cout<<"Same Parent"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }
    
    ds.unionByRank(1,4);
    
    if(ds.findParent(1)==ds.findParent(7)){
        cout<<"Same Parent"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }
    
    return 0;
}
