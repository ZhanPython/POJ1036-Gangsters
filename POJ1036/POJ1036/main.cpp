
//
//  main.cpp
//  POJ1015
//
//  Created by Kenny Zhan on 2017/9/15.
//  Copyright © 2017年 Kenny ZhanNANJING UNIV OF SCI & TECH. All rights reserved.
//
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn=105;
int T,n,k,ans,t[maxn],v[maxn],s[maxn],p[maxn],dp[maxn];

//T: interval of time
//n: gangsters
//k: the door has k+1 states of openness
//ans: the maximal sum of prosperity
//t[maxn]: the moments when gangsters come
//v[maxn]: the prosperity
//s[maxn]: the stoutness
//p[maxn]: the pth gangster
//dp[maxn]: the state transfer function of the maximal sum of prosperity
 
int absolute(int x)
{
    return x>0?x:-x;
}
bool cmp(int a,int b)
{
    return t[a]<t[b];                                                    //Ascending
}
int main(void)
{
    scanf("%d%d%d",&n,&k,&T);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        p[i]=i;
    }
    sort(p+1,p+n+1,cmp);                                                 //Sort by arrival time in ascending order
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(dp[j]!=-1 && absolute(s[p[i]]-s[p[j]])<=t[p[i]]-t[p[j]])
            {
                dp[i]=max(dp[i],dp[j]+v[p[i]]);
                ans=max(ans,dp[i]);
            }
    printf("%d\n",ans);
    return 0;
}