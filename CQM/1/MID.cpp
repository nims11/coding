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
#include<list>
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
char str[100];
int n = 0;
//priority_queue<int> l, r;
list<int> X;
list<int>::iterator med, it;
int main()
{
    int x;
    while(in_I(x) != EOF)
    {
        if(x == 0)
        {
//            while(l.size())
//            {
//                l.pop();
//            }
//            while(r.size())
//            {
//                r.pop();
//            }
            n = 0;
            newline;
            X.clear();
            continue;
        }
        if(x == -1)
        {
            printf("%d\n", *med);
            med = X.erase(med);
            n--;
            if(n!=0 && n%2 == 0)
                --med;
        }else
        {
            if(n == 0)
            {
                X.push_back(x);
                med = X.begin();
                n++;
            }else
            {
                X.push_back(x);
                n++;
                if(n%2 != 0)
                    med++;
            }
        }

//        if(n == -1)
//        {
//            printf("%d\n", l.top());
//            l.pop();
//        }else if(l.size() == 0)
//        {
//            l.push(n);
//        }else
//        if(l.top() < n)
//        {
//            r.push(-n);
//        }else
//            l.push(n);
//
//        while(l.size()<r.size())
//        {
//            n = -r.top();
//            r.pop();
//            l.push(n);
//        }
//        while(l.size()>r.size()+1)
//        {
//            n = -l.top();
//            l.pop();
//            r.push(n);
//        }
    }
}
