/*
 * josephus problem for k=2
 * it has a direct formula
 */
#include<cstdio>
#include<cmath>
int main()
{
    int a,p;
    while(1)
    {
        scanf("%de%d",&a,&p);
        if(a==0)break;
        while(p--)a*=10;
        printf("%d\n",2*(a-int(pow(2,(int)log2(a))))+1);
    }
}
