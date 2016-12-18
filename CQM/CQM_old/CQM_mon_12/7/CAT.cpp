/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<cctype>
#define in_T int t;for(scanf("%d",&t),cin.ignore(1);t--;)
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
char foo[26];
int cool[26] = {0};
int bar[26]={0};
string str1 = "Dear Cat, I love you. But I'm tired of you taking me for granted. I even dumped my last girl friend because she was alergic to you and ran around sneezing every time you were around. Unless you start treating me with some respect, I'm not going to feed you.";
string str2 = "Kzjw Sjn, B eogz aov. Dvn B'p nbwzk or aov njlbxf pz row fwjxnzk. B zgzx kvpizk pa ejcn fbwe rwbzxk dzsjvcz cqz ujc jezwfbs no aov jxk wjx jwovxk cxzzhbxf zgzwa nbpz aov uzwz jwovxk. Vxezcc aov cnjwn nwzjnbxf pz ubnq copz wzcizsn, B'p xon fobxf no rzzk aov.";
void gen_map()
{
    for(int i =0;i<str1.length(); i++)
    {
        if(isalpha(str1[i]))
        {
            cool[tolower(str1[i]) - 'a'] = 1;
            bar[tolower(str2[i]) - 'a'] = 1;
            foo[tolower(str1[i]) - 'a'] = tolower(str2[i]);
        }
    }
}
int main()
{
    foo['q'-'a'] = 'm';
    foo['x'-'a'] = 't';
    bar['m'-'a'] = 1;
    bar['t'-'a'] = 1;
    gen_map();
    char missing;
    for(int i=0;i<26;i++)
    if(bar[i]==0)
        {
            missing = 'a'+i;
            break;
        }
    for(int i=0;i<26;i++)
        if(cool[i]==0)
        {
            foo[i] = missing;
            break;
        }

//    for(int i=0;i<26;i++)
//    cout<<foo[i]<<endl;
    in_T
    {
        string str;
        getline(cin,str);
        for(int i=0;i<str.length();i++)
        {
            if(isalpha(str[i]))
            {
                if(islower(str[i]))
                {
                    printf("%c",foo[str[i]-'a']);
                }else
                {
                    printf("%c",toupper(foo[tolower(str[i])-'a']));
                }
            }else
            printf("%c",str[i]);
        }
        newline;
    }
}
