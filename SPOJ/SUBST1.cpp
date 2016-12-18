/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}
int main()
{
    in_T
    {
        char str[51000];
        int lcp[51000];
        in_S(str);
        char *suffix[51000];
        int len=strlen(str);
        for(int i=1;i<=len;i++)
        suffix[i-1]=str+(i-1);
        qsort(suffix,len,sizeof(char*),cstring_cmp);
        lcp[0]=0;
        long long unsigned ans=(str+len)-suffix[0];
        for(int i=1;i<len;i++)
        {
            int suff_len1=(str+len)-suffix[i];
            int suff_len2=(str+len)-suffix[i-1];

            int j;int lt=MIN(suff_len1,suff_len2);
            for(j=0;j<lt;j++)
            {
                if(suffix[i][j]!=suffix[i-1][j])
                break;
            }
            lcp[i]=j;
            ans+=suff_len1-lcp[i];
        }
        cout<<ans<<endl;
    }
}

