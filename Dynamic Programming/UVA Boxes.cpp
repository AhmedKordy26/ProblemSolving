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
#define pb(x) push_back(x)
#define Kordy ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ReadFile freopen("input.txt","r",stdin)
#define WriteFile freopen("output.txt","w",stdout)
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
const int OO = 0x3f3f3f3f,NegOO= -1*OO,N = 1005,mod = 1e9+7 ;
int dp[1005][6005] ;
int n;
int w[N],l[N];
int solve(int i,int weight)
{
    if(weight<0)return NegOO;
    if(i==n)return 0;
    int &rf=dp[i][weight];
    if(~rf)return rf;
    return rf=max(solve(i+1,weight),1+solve(i+1,min(weight-w[i],l[i])));
}
int main()
{
    Kordy
    while(cin>>n)
    {
        if(!n)break;
        memset(dp,-1,sizeof dp);
        forr(c,0,n)cin>>w[c]>>l[c];
        cout<<solve(0,6002)<<endl;
    }
    return 0;
}