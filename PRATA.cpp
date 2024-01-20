
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool check(int t, int p, vector<int>& ranks)
{
    int cnt = 0;
    for(int i=0; i<ranks.size(); i++)
    {
        int c = 0;
        int time = t;
        int perprata = ranks[i];
        while(time > 0)
        {
            time = time - perprata;
            if(time >= 0)
            {
                c++;
                perprata += ranks[i];
            }
        }
        cnt += c;
        if(cnt>=p)
            return true;
    }
    return false;
}

void solve(int p, vector<int>& ranks)
{
    int ans;
    int s = 0, e = INT_MAX;

    //Finding the upper bound.
    //int min_cook = *min_element(ranks.begin(),ranks.end());
    //int e = (p/2) * ((2 * min_cook) + ((p - 1) * min_cook));

    while(s<=e)
    {
        int mid = (s + e)/2;
        if(check(mid,p,ranks))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    cout<<ans<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,n;
        cin>>p>>n;
        vector<int> ranks(n);
        for(int i=0; i<n; i++)
            cin>>ranks[i];
        solve(p,ranks);
    }
}
