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
#define forr(c,x,n)  for(long long c=x;c<n;c++)
#define fo(c,n,x)  for(long long c=n;c>=x;c--)
#define NOO 999999999999999999
#define OO  0x3f3f3f3f
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
int dp[205][25];
int arr[205][25];
int M,C,K[25];
bool vst[25];
int cnt=0;
bool no;
int solve(int rem,int i)
{
    if(rem>M)return -(int)1e8;
    if(i==C)return 0;
    int &rf=dp[rem][i];
    if(~rf)return rf;
    rf=-1e8;
    forr(c,0,K[i])
    {

         rf=max(rf,arr[i][c]+solve(rem+arr[i][c],i+1));
    }
    return rf;
}
int main()
{
    //freopen("asd.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cnt=0;
        no=0;
        cin>>M>>C;
        forr(i,0,C)
        {
            cin>>K[i];
            forr(j,0,K[i])
            {
                cin>>arr[i][j];
            }
        }
        int ans=solve(0,0);
        (ans>=0)?cout<<ans:cout<<"no solution";
        cout<<endl;
    }
    return 0;
}
