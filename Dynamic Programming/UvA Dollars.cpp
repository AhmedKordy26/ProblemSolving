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
ll dp[300005][11];
int Coins[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
ll solve(int rem,int st)
{
    if(rem==0)return 1;
    ll &rf=dp[rem][st];
    if(~rf)return rf;
    rf=0;
    forr(c,st,11)
    {
        rf+=(rem-Coins[c]>=0)?solve(rem-Coins[c],c):0;
    }
    return rf;
}
ll ans[300005];
int main()
{
    //Kordy
    //freopen("asd.txt","w",stdout);
    memset(dp,-1,sizeof dp);
    memset(ans,-1,sizeof ans);
    fo(c,300002,1)
    {
        ans[c]=solve(c,0);
    }
    int n;
    double inp,tmpin;
    while(cin>>inp)
    {
        if(inp==0.00)break;
        tmpin=inp;
        inp*=10;
        inp*=10;
        n=(int)inp;
        if(ans[n]==-1)ans[n]=solve(n,0);
        cout<<setw(6)<<fixed<<setprecision(2)<<(float)tmpin<<setw(17)<<(ll)ans[n]<<endl;
    }
    return 0;
}
