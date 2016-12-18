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
string str;
struct node
{
    int type;
    /*
    0 - text
    1 - open
    2 - close
    3 - inde
    */
    string data;
}nodes[2000];
int idx = 0;
int node_cnt = 0;
multiset<string> open;
void build(int node_id)
{
    open.insert(nodes[node_id].data);
    idx++;
    while(idx<node_cnt)
    {
//        cout<<"Now in "<<nodes[node_id].type<<" "<<nodes[node_id].data<<" with idx "<<nodes[idx].type<<" "<<nodes[idx].data<<endl;
        if(nodes[idx].type == 0)
        {
            printf("%s", nodes[idx].data.c_str());
            idx++;
        }else if(nodes[idx].type == 1)
        {
            printf("<%s>", nodes[idx].data.c_str());
            build(idx);
        }else if(nodes[idx].type == 3)
        {
            printf("<%s/>", nodes[idx].data.c_str());
            idx++;
        }else if(nodes[idx].type == 2)
        {
            if(nodes[idx].data == nodes[node_id].data)
            {
                if(nodes[idx].data[0] != '#')
                printf("</%s>", nodes[idx].data.c_str());
                open.erase(open.find(nodes[idx].data));
                idx++;
                return;
            }else if(open.find(nodes[idx].data) != open.end())
            {
                open.erase(open.find(nodes[node_id].data));
                if(nodes[node_id].data[0] != '#')
                printf("</%s>", nodes[node_id].data.c_str());
                return;
            }else
            idx++;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    cin.ignore(100,'\n');
    while(t--)
    {
        open.clear();
        getline(cin, str);
        str = "<#>"+str+"</#>";
        node_cnt = 0;
//        cout<<str<<endl;
        for(int i=0;i<str.length();i++)
        {
//            cout<<i<<" "<<str[i]<<endl;
            if(str[i] == '<')
            {
                i++;
                int st = i;
                if(str[st] == '/')
                {
                    nodes[node_cnt].type = 2;
                    st = ++i;
                    while(str[i]!='>')
                    i++;
                    nodes[node_cnt].data = str.substr(st, i-st);
                    node_cnt++;
                    continue;
                }
                while(str[i]!='>')
                    i++;
                if(str[i-1] == '/')
                {
                    nodes[node_cnt].type = 3;
                    nodes[node_cnt].data = str.substr(st, i-1-st);
                }else
                {
                    nodes[node_cnt].type = 1;
                    nodes[node_cnt].data = str.substr(st, i-st);
                }
                node_cnt++;
            }else
            {
                int st = i;
                while(str[i]!='<')i++;
                i--;
                nodes[node_cnt].type = 0;
                nodes[node_cnt++].data = str.substr(st, i-st+1);
            }
        }
//        for(int i=0;i<node_cnt;i++)
//        {
////            cout<<nodes[i].type<<" "<<nodes[i].data<<endl;
//        }
        idx = 0;
        build(0);
        cout<<endl;
    }
}
