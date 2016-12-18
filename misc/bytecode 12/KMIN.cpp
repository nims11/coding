/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    vector<int> left_heap;priority_queue<int> right_heap;
    int n,k,ans,tmp,foo;
    in_I(n);
    in_I(k);
    for(int i=0;i<k;i++)
    {
        in_I(tmp);
        left_heap.push_back(tmp);
    }
    make_heap(left_heap.begin(),left_heap.end());

    pop_heap(left_heap.begin(),left_heap.end());
    ans = left_heap[left_heap.size()-1];left_heap.pop_back();

    for(int i=k;i<n;i++)
    {
        in_I(tmp);
//        cout<<"*"<<tmp<<endl;
        if(tmp==-1)printf("%d\n",ans);
        else
        {
            if(tmp<=left_heap[0])
            {
                left_heap.push_back(tmp);
                push_heap(left_heap.begin(),left_heap.end());
                pop_heap(left_heap.begin(),left_heap.end());
                foo = left_heap[left_heap.size()-1];left_heap.pop_back();
                right_heap.push(-ans);
                ans = foo;
//                cout<<left_heap.size()<<" "<<ans<<endl;
            }else
            {
                right_heap.push(-ans);
                right_heap.push(-tmp);
                ans = - right_heap.top();
                right_heap.pop();
            }
        }
    }
}
