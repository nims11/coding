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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int main()
{
    in_T{
        int a, b;
        in_I(a);in_I(b);
        int ret = 0;
        set<int> s;
        s.insert(a);
        s.insert(b);
        while(true){
            bool flag = false;
            for(int a:s){
                for(int b: s){
                    if(a != b && s.count(abs(a-b)) == 0){
                        s.insert(abs(a-b)), flag = true;
                        ret++;
                        break;
                    }
                }
                if(flag)break;
            }
            if(!flag)break;
        }
        cout<<ret<<endl;
    }
}
