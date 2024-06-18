#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

void check(int x, int y, int z)
{
    if((x/z)%3==1&&(y/z)%3==1)
    {
        cout<<" ";
    }
    else
    {
        if(z/3==0)
        {
            cout<<"*";
        }
        else
        {
            check(x,y,z/3);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            check(i,j,n);
        }
        cout<<"\n";
    }
}