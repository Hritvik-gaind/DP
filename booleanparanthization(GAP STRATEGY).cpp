#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int dpt[n][n];
    int dpf[n][n];
    memset(dpt,0,sizeof(dpt));
    memset(dpf,0,sizeof(dpf));
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            if(g==0)
            {
                if(s1[i]=='T')
                {
                    dpt[i][j] = 1;
                    dpf[i][j] = 0;
                }
                else
                {
                    dpt[i][j] = 0;
                    dpf[i][j] = 1;
                }
            }
            else
            {
                for(int k=i;k<j;k++)
                {
                    int ltc  = dpt[i][k];
                    int rtc  = dpt[k+1][j];
                    int lfc  = dpf[i][k];
                    int rfc  = dpf[k+1][j];
                    if(s2[k]=='&')
                    {
                        dpt[i][j]+= rtc*ltc;
                        dpf[i][j]+= ltc*rfc + lfc*rfc + lfc*rtc;
                    }
                    else if(s2[k]=='|')
                    {
                        dpf[i][j]+= rfc*lfc;
                        dpt[i][j]+= ltc*rfc + ltc*rtc + lfc*rtc;
                    }
                    else
                    {
                        dpt[i][j] += rfc*ltc + lfc*rtc;
                        dpf[i][j] += rfc*lfc + rtc*ltc;
                    }
                }

            }
        }
    }
    cout<<dpt[0][n-1];
}
