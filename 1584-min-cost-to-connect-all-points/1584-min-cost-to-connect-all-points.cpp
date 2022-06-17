class Solution {
public:
    int find(int u,vector<int> & parent){
        if(parent[u]!=u) return parent[u]=find(parent[u],parent);
        return u;
    }
    
    bool unite(int u,int v,vector<int> & parent,vector<int> & rank){
        int s1=find(u,parent),s2=find(v,parent);
        
        if(s1==s2) return false;
        if(rank[s1]>rank[s2]) parent[s2]=s1;
        else if(rank[s1]<rank[s2]) parent[s1]=s2;
        else{
            rank[s1]++;
            parent[s2]=s1;            
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edges;
        int n=points.size();
        for(int curr=0;curr<n;curr++){
            for(int next=curr+1;next<n;next++){
                int valX=abs(points[curr][0]-points[next][0]);
                int valY=abs(points[curr][1]-points[next][1]);
                
                int dist=valX+valY;
                
                edges.push_back({dist,{curr,next}});
            }
        }
        
        // now sort the edges according to the distance
        sort(begin(edges),end(edges));
        
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<int> rank(n,0);
        
        
        int cost=0;
        int used=0;
        
        for(int i=0;i<edges.size() && used<n-1;++i){
            int node1=edges[i].second.first;
            int node2=edges[i].second.second;
            int w=edges[i].first;
            
            if(unite(node1,node2,parent,rank)){
                cost+=w;
                used++;
            }
        }
        return cost;
    }
};