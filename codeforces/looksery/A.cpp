/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    string str[51];
    for(int i = 0;i<n;i++)
        cin>>str[i];
    int res = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m-1;j++){
            int i2 = i+1, j2 = j+1;
            int foo[26] = {0};
            for(int x = i;x<=i2;x++)
                for(int y=j;y<=j2;y++)
                    foo[str[x][y] - 'a']++;
            if(foo['f'-'a'] == 1 && foo['a'-'a'] == 1 && foo['c'-'a'] == 1 && foo['e'-'a'] == 1)
                res++;
        }
    }
    cout<<res<<endl;
}
