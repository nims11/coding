/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
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

using namespace std;
int main()
{
    int z = 0;
    in_T{
        z++;
        string str;
        cin>>str;
        int secu = 0;
        bool isDig = false, hasLatin = false, hasSym = false, hasSmall = false, hasLarge = false;
        set<char> tmp;
        for(int i = 0;i<str.size();i++){
            tmp.insert(str[i]);
            isDig |= (str[i]>='0' && str[i]<='9');
            hasLatin |= isalpha(str[i]);
            hasSym |= (!isalpha(str[i]) && !(str[i]>='0' && str[i]<='9'));
            hasSmall |= (str[i]<='z' && str[i]>='a');
            hasLarge |= (str[i]<='Z' && str[i]>='A');
        }
        secu = isDig + hasLatin + hasSym + (str.size()>=6) + (str.size()>10) + (hasSmall && hasLarge) + (str.size() == tmp.size());
        cout<<"Case #"<<z<<":"<<endl;
        cout<<(secu<4?"weak":(secu>=6?"strong":"normal"))<<endl;
    }
}
