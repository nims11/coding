#include<stdio.h>
int t,n,m,max,min,w,x,y,z,arr[1000001],i;
int main()
{
    for(scanf("%d",&t);t--;)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        arr[i]=i;
        while(m--)
        {
            scanf("%d%d%d%d",&w,&x,&y,&z);
            if(w==2)z=-z;
            for(i=x;i<=y;i++)
            arr[i]+=z;
        }
        if(n&1)max=min=arr[1],i=2;
        else{
            i=3;
            if(arr[1]>arr[2])max=arr[1],min = arr[2];
            else
            max=arr[2],min=arr[1];
        }
        for(;i<=n;i+=2)
        {
            if(arr[i]>arr[i+1])
            {
                if(arr[i]>max)max = arr[i];
                if(arr[i+1]<min)min=arr[i+1];
            }else
            {
                if(arr[i+1]>max)max = arr[i+1];
                if(arr[i]<min)min=arr[i];
            }
        }
        printf("%d\n",max-min);
    }
}
