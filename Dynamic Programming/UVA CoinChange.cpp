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
#define NegOO -1*0x3f3f3f3f
#define MAXARR   100005
#define mod 1073741824
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
//decimal to binary :: while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
//int value = atoi(myString.c_str());
int dimx[]= {-1, 1, 0, 0};
int dimy[]= {0, 0, 1, -1};
int Coins[]={50,25,10,5,1};
ll dp[MAXARR][5];
ll solve(int rem,int st)
{
    if(rem==0)return 1;
    ll &rf=dp[rem][st];
    if(~rf)return rf;
    rf=0;
    forr(c,st,5)
    {
        rf+=(rem-Coins[c]>=0)?solve(rem-Coins[c],c):0;
    }
    return rf;
}
ll ans[7900];
int main()
{
    //freopen("asd.txt","w",stdout);
    memset(dp,-1,sizeof dp);
    fo(c,7490,1)
    {
        ans[c]=solve(c,0);
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",ans[n]);
    }
    return 0;
}
