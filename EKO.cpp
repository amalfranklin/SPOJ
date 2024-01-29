#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool check(int height, int rwood, vector<int>& tree)
{
    int wood = 0;
    for(int i=0; i<tree.size(); i++)
    {
        if(tree[i] - height < 0)
            continue;
        wood += (tree[i] - height);
        if(wood >= rwood)
            return true;
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> tree(n);
    for(int i=0; i<n; i++)
        cin>>tree[i];

    int l=0, r=*max_element(tree.begin(),tree.end());
    int ans = l;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(check(mid,m,tree))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout<<ans;
}
