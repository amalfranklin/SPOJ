#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> nums;
vector<int> part_1;
vector<int> part_2;
int n, a, b;
long long int res;

vector<int> subsets(vector<int>& num){
        vector<int> res;
        for(int i=0; i<(1<<num.size()); i++)
        {
            int sum = 0;
            int temp = i;
            int pos = -1;
            while(temp > 0)
            {
                pos++;
                if(temp & 1)
                    sum += num[pos];
                temp = temp>>1;
            }
            res.push_back(sum);
        }
        return res;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    vector<int> temp;
    temp.assign(nums.begin(),nums.begin() + (n/2));
    part_1 = subsets(temp);
    temp.clear();
    temp.assign(nums.begin() + (n/2), nums.end());
    part_2 = subsets(temp);
    sort(part_2.begin(),part_2.end());

    for(int val : part_1)
    {
        int low_index = lower_bound(part_2.begin(),part_2.end(),a - val) - part_2.begin();
        int upper_index = lower_bound(part_2.begin(),part_2.end(),b - val + 1) - part_2.begin();
        res += upper_index - low_index;
    }

    cout<<res;
}
