#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> sol;


bool check(int distance, int c, vector<int>& stall)
{
    int cows = 1, last_cow = stall[0];
    for(int i=1; i<stall.size(); i++)
    {
        if(stall[i] - last_cow >= distance)
        {
            cows++;
            last_cow = stall[i];
        }
        if(cows == c)
            return true;
    }
    return false;
}

void solve(int n, int c, vector<int>& stall)
{
    sort(stall.begin(),stall.end());
    int res=0, l = 0, r = stall[n-1] - stall[0];
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(mid,c,stall))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    sol.push_back(res);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int> stall(n);
        for(int i=0; i<n; i++)
            cin>>stall[i];
        solve(n,c,stall);
    }

    for(int x : sol)
        cout<<x<<endl;
}
