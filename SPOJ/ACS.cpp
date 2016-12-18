//GQ
/*
 * a given 2-D marix with given generating function ( parameter: row and column).
 * to implement following operations:
 *  swap any two row
 *  swap any two col
 *  write out M(x,y)
 *  write out x,y where z=M(x,y)
 *
 *  Instead of creating the whole matrix, Just keep track of the rows and columns. Bimap.
 *  all operations would take place in O(1) time.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

const int r=1234,c=5678;
int main()
{
    char ch;int row[1235],col[5679],row_p[1235],col_p[5679],a,b;
    for(int i=1;i<=r;i++)row[i]=row_p[i]=i;
    for(int i=1;i<=c;i++)col[i]=col_p[i]=i;
    int tmp;
    while(scanf("%c",&ch)!=EOF)
    {
        switch(ch)
        {
            case 'R':
            in_I(a);in_I(b);
            row_p[row[a]]=b;
            row_p[row[b]]=a;
            SWAP(row[a],row[b]);
            break;
            case 'C':
            in_I(a);in_I(b);
            col_p[col[a]]=b;
            col_p[col[b]]=a;
            SWAP(col[a],col[b]);
            break;
            case 'Q':
            in_I(a);in_I(b);
            printf("%d\n",(row[a]-1)*c+col[b]);
            break;
            case 'W':
            in_I(a);
            printf("%d %d\n",row_p[(a-1)/c+1],col_p[(a-1)%c+1]);
            break;
        }
    }
}
