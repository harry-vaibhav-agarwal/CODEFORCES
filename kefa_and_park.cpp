#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug3(a,b,c) cout<<#a<<" :: "<<a<<"\t"<<#b<<" :: "<<b<<"\t"<<#c<<" :: "<<c<<"\n";
#define debug2(a,b) cout<<#a<<" :: "<<a<<"\t"<<#b<<" :: "<<b<<"\n"
#define debug(a) cout<<#a<<" :: "<<a<<"\n"
vector<vector<int>>tree;
vector<int>cat;
int m;


int dfs(int u,int par,int cnt){
    
    
    
    if(cat[u])   //if there is a cat in this vertex
        cnt--;
    
    if(cnt<0)   //it means we encouter m+1 consecutive cats so we cant visit restaurant
        return 0;
        
    if(par!=-1 && tree[u].size()==1 &&  cnt>=0)   //root size is also 1 apart from root all other leaf nodes have size 1 and if cnt is positie we return 1
        return 1;
        
    if(par!=-1 && tree[u].size()==1)
        return 0;
        
    
    
    int ans=0;
    for(auto v:tree[u]){
        
        if(v==par)
            continue;
            
        if(!cat[u])
            ans+=dfs(v,u,m);   //if there is no cat consecutivity breaks restarting with m
            
        else
            ans+=dfs(v,u,cnt);  //for consecutive
    }
    
    
    
    return ans;
    
}

int main(){
    
    IOS;
    int n;
    cin>>n>>m;
    tree.resize(n+1);
    
    cat.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>cat[i];
        
    for(int i=0,a,b;i<n-1;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    cout<<dfs(1,-1,m)<<"\n";
    return 0;
}
