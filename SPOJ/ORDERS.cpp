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
class binary_tree
{
    public:
    int val, size;
    bool valid;
    binary_tree *left, *right;
    binary_tree(int start, int end);
    int delMax(int k);
};
binary_tree::binary_tree(int start, int end)
{
    valid = true;
    left = right = 0;
    size = end-start+1;
    val = (start+end)/2;
    if(val>start)
    {
        left = new binary_tree(start, val-1);
    }
    if(val<end)
    {
        right = new binary_tree(val+1, end);
    }
}
int binary_tree::delMax(int k)
{
    size--;
    if(right)
    {
        if(k<=right->size)return right->delMax(k);
        if(k==right->size+1 && valid)
        {
            valid = false;
            return val;
        }else
        {
            return left->delMax(k-valid-right->size);
        }
    }else if(k==1 && valid)
    {
        valid = false;
        return val;
    }else return left->delMax(k-valid);
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        int arr[n], ans[n];
        binary_tree foo(1, n);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        for(int i=n-1;i>=0;i--)
        {
            ans[i] = foo.delMax(arr[i]+1);
        }
        for(int i=0;i<n;i++)
        {
            printf("%d ", ans[i]);
        }
        newline;
    }
}
