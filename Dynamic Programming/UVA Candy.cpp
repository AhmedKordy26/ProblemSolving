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
int n,m;
ll dp[MAXARR];
ll arr[MAXARR];
ll solve(int i,int cnt)
{
   // cout<<i<<" "<<cnt<<endl;
    if(i>=cnt)return 0;
    ll &rf=dp[i];
    if(~rf)return rf;
    return rf=max(solve(i+1,cnt),arr[i]+solve(i+2,cnt));
}
int main()
{
    Kordy
    while(cin>>n>>m)
    {
        memset(dp,-1,sizeof dp);
        if(!n&&!m)break;
        forr(c,0,n*m)cin>>arr[c];
        int cnt=0;
        for(int c=0;c<n*m;c+=m)
        {
            cnt++;
            arr[c]=solve(c,c+m);
        }
        cnt=0;
        forr(c,0,n)
        {
            arr[c]=arr[cnt*m];
            cnt++;
        }
        memset(dp,-1,sizeof dp);
        cout<<solve(0,n)<<endl;

    }
    return 0;
}
