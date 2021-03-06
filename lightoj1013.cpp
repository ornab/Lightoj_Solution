#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 40
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

i64 i,j,l,n,x=1,cnt,sm,fg,l1,l2,dp[si][si],res[si][si][2*si];
char ch1[si],ch2[si];

/*
i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}*/

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

/*
i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}
*/

int rec(i64 i,i64 j)
{
	if(i<0||j<0)
		return 0;
	i64 &ret=dp[i][j];
	if(ret!=-1)
		return ret;
	if(ch1[i]==ch2[j])
		ret=1+rec(i-1,j-1);
	else
	{
		ret=rec(i-1,j);
		ret=max(ret,rec(i,j-1));
	}
	return ret;
}

i64 f(i64 i,i64 j,i64 chk)
{
	if(i==0&&j==0&&chk==0)
		return 1;
	if(i<0||j<0||chk<0)
		return 0;
	i64 &ret=res[i][j][chk];
	if(ret!=-1)
		return ret;
	if(ch1[i-1]==ch2[j-1])
		ret=f(i-1,j-1,chk-1);
	else
		ret=f(i-1,j,chk-1)+f(i,j-1,chk-1);

	return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	i64 t;
	scanf("%lld",&t);
   	while(t--)
   	{
		scanf("%s%s",ch1,ch2);
		l1=strlen(ch1);
		l2=strlen(ch2);
		mem(dp,-1);
		i64 ans=rec(l1-1,l2-1);
		ans=l1+l2-ans;
		mem(res,-1);
		i64 way=f(l1,l2,ans);
		printf("Case %lld: %lld %lld\n",x++,ans,way);
    }
   	return 0;
}
