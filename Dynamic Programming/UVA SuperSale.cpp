#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#define ll long long
#define ld long double
#define endl "\n"
#define sysreturn {system("pause");return 0;}
#define ull unsigned long long
#define all(v) ((v).begin()), ((v).end())
#define sz(v)   ((int)((v).size()))
#define forr(c,x,n)  for(int c=x;c<n;c++)
#define fo(c,n,x)  for(int c=n;c>=x;c--)
#define NOO 999999999999999999
#define OO  0x3f3f3f3f
#define NegOO -0x3f3f3f3f
#define MAXARR   100005
#define MOD 1000000007
#define pb(x) push_back(x)
#define Kordy ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
typedef vector<long long> vi;
typedef set<long long>se;
/*
///////////////////////////////////////////////
this code is by Ahmed ....

**      *            **    *    **    *      *
**   **      *       **  *      **     **   **
**  **     *   *     ***        **       *****
** **    *       *   **         **          **
***     *         *  **         **          **
** **    *       *   **     *****           **
**  **     *   *     **    *    **   *      **
**   **      *       **    *    **   **   **
**      *            **     ****       ***

///////////////////////////////////////////////
*/
// start +(end-start)/2
// sum from 1 to n = (n*(n+1))/2
//A=65 // a=97  // num=48
//Hot Mod (a%n+n)%n
//decimal to binary :: while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
//int value = atoi(myString.c_str());
int dimx[]= {-1, 1, 0, 0};
int dimy[]= {0, 0, 1, -1};
int dp[1005][30005];
int p[1005],w[1005];
int n,g,x;
int solve(int i,int rem)
{
    if(i==n)return 0;
    int &rf=dp[i][rem];
    if(~rf)return rf;
    return rf=max((rem-w[i]>=0)?p[i]+solve(i+1,rem-w[i]):0,solve(i+1,rem));
}
int main()
{
     Kordy
    //freopen("asd.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cin>>n;
        forr(c,0,n)cin>>p[c]>>w[c];
        fo(c,31,1)
        {
            x=c;
            if(dp[0][c]==-1)dp[0][c]=solve(0,c);
        }
        ll sum=0;
        cin>>g;
        while(g--)
        {
            cin>>x;
            sum+=dp[0][x];
        }
        cout<<sum<<endl;
    }
    return 0;
}
