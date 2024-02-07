#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
map<pair<int,int>,int> dp;

int dfs(int cur, int take, int par)
{
    if(dp.count({cur,take}))
        return dp[{cur,take}];
    int ans = take;
    for(auto child : adj[cur])
        if(child != par)
            if(take)
                ans += min(dfs(child,1,cur),dfs(child,0,cur));
            else
                ans += dfs(child,1,cur);
    return dp[{cur,take}] = ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<(n-1); i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<min(dfs(1,0,0),dfs(1,1,0));
}
