#This is the code for my most fav approach i mentioned here..
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int n=amount.size();
        vector<vector<int>>tree(n);
        vector<int>parent(n);
        vector<int>distalice(n,-1);
        for(vector<int>&edge:edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfsA(tree,0,-1,0,parent,distalice);
        int bobdist=0;
        for(int u=bob;u!=0;u=parent[u],++bobdist){
            if(bobdist<distalice[u])
                amount[u]=0;
            else if(bobdist==distalice[u])
                amount[u]/=2;
        }
        return getmoney(tree,0,-1,amount);
    }
private:
    void dfsA(vector<vector<int>>&tree,int src,int prev,int d,vector<int>&parent,vector<int>&alicedist){
        parent[src]=prev;
        alicedist[src]=d;
        for(const int v:tree[src]){
            if(alicedist[v]==-1)
                dfsA(tree,v,src,d+1,parent,alicedist);
        }
    }
    int getmoney(const vector<vector<int>>&tree,int src,int prev,const vector<int>&amount){
        if(tree[src].size()==1&&tree[src][0]==prev)
            return amount[src];
        int maxAmount=INT_MIN;
        for(const int v:tree[src]){
            if(v!=prev)
                maxAmount=max(maxAmount,getmoney(tree,v,src,amount));
        }
        return maxAmount+amount[src];

    }
};