#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

void solve(vector<pair<int,int>> a)
{
    sort(a.begin(),a.end(),compare);
    int res = 1;
    int prev_end = a[0].second;
    for(int i=1; i<a.size(); i++)
    {
        if(a[i].first < prev_end)
                continue;
        res++;
        prev_end = a[i].second;
    }
    cout<<res<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        t--;
        int n;
        vector<pair<int,int>> a;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int b,c;
            cin>>b>>c;
            a.push_back({b,c});
        }
        solve(a);
    }
}
