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
struct Card
{
    int time;
    int nums;
    friend bool operator<(const Card a, const Card b)
    {
        return a.time<b.time;
    }
}tmp_card;
struct node{
    //0 = enter
    // 1 = exit
    int type;
    int time;
    int nums;
    friend bool operator<(const node &a, const node &b)
    {
        if(a.time == b.time)
            return a.type<b.type;
        return a.time<b.time;
    }
}tmp_node;
long long unsigned mod = 1000002013;
int main()
{
    int c = 0;
    in_T
    {
        c++;
        int n,m;
        in_I(n);
        in_I(m);
        priority_queue<Card> foo;
        long long unsigned real = 0;
        vector<node> evt;
        int o,e,num;
        long long unsigned ans = 0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d", &o, &e, &num);
            long long y = e-o;
//            real = (real + num*((y*n%mod-(y*(y-1))/2)%mod)%mod)%mod;
            real = (real + num*(y*n%mod +mod- (((y*(y-1))/2)%mod)))%mod;
            tmp_node.time = o;
            tmp_node.type = 0;
            tmp_node.nums = num;
            evt.push_back(tmp_node);
            tmp_node.time = e;
            tmp_node.type = 1;
            tmp_node.nums = num;
            evt.push_back(tmp_node);
        }
        sort(evt.begin(), evt.end());
        for(int i=0;i<evt.size();i++)
        {
            if(evt[i].type == 0)
            {
//                cout<<"Insert: "<<evt[i].time<<endl;
                tmp_card.time = evt[i].time;
                tmp_card.nums = evt[i].nums;
                foo.push(tmp_card);
            }else
            {
//                cout<<"Rem: "<<evt[i].time<<endl;
                int x = evt[i].nums;
                while(x)
                {
                    tmp_card = foo.top();
//                    cout<<"Card: "<<tmp_card.time<<endl;
                    foo.pop();
                    if(tmp_card.nums>x)
                    {
                        tmp_card.nums -= x;
                        long long y = evt[i].time-tmp_card.time;
                        ans = (ans + x*(y*n%mod +mod- (((y*(y-1))/2)%mod)))%mod;
                        x = 0;
                        foo.push(tmp_card);
                    }else
                    {
                        long long y = evt[i].time-tmp_card.time;
                        ans = (ans + tmp_card.nums*(y*n%mod +mod- (((y*(y-1))/2)%mod)))%mod;
                        x -= tmp_card.nums;
                    }
//                    cout<<ans<<endl;
                }
//                cout<<ans<<endl;
            }
        }
//        cout<<real<<" "<<ans<<endl;
        cout<<"Case #"<<c<<": "<<(mod+real-ans)%mod<<endl;
    }
}
