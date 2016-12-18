#include<iostream>
#include<cstdio>
using namespace std;
int R=1,L=-1,U=2,D=-2;
float getTime(int xe,int ye,int de,int xa,int ya,int da)
{
    //cout<<de<<da<<endl;
    int dx=xa-xe,dy=ya-ye;
    if(dx==0)
    {
        if(ya>ye)
        {
            if(da==D && de==U)
            return float(ya-ye)/2;
            else
            return -1;
        }else
        {
        if(da==U && de==D)
            return float(ye-ya)/2;
            else
            return -1;
        }
    }
    if(dy==0)
    {
        if(xa>xe)
        {
            if(da==L && de==R)
            return float(xa-xe)/2;
            else
            return -1;
        }else
        {
        if(da==R && de==R)
            return float(xe-xa)/2;
            else
            return -1;
        }
    }
    int quad;
    int x=dx*dy;
    if(x>0)
    {if(dx>0)
    quad=1;
    else quad=3;}
    else
    {
        if(dx<0)
        quad=2;
        else quad=4;
    }
    switch(quad)
    {
        case 1:
        if(de==R && da==D)
        {
            if(dx==dy)
            return dx;
        }else if(de==U && da==L)
        {
            if(dx==dy)
            return dx;
        }
        break;

        case 2:
        if(de==L && da==D)
        {
            if(dx==dy)
            return dx;
        }else if(de==U && da==R)
        {
            if(dx==dy)
            return dx;
        }
        break;

        case 3:
        if(de==L && da==U)
        {
            if(dx==dy)
            return dx;
        }else if(de==D && da==R)
        {
            if(dx==dy)
            return dx;
        }
        break;

        case 4:
        if(de==R && da==U)
        {
            if(dx==dy)
            return dx;
        }else if(de==D && da==R)
        {
            if(dx==dy)
            return dx;
        }
        break;

    }
    return -1;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,xe,ye,de;
        char ch;
        cin>>xe>>ye>>ch;
        switch(ch)
            {
                case 'R':de=R;break;
                case 'L':de=L;break;
                case 'U':de=U;break;
                case 'D':de=D;break;
            }
        cin>>n;
        float min=-1;
        int *xa=new int[n];
        int *ya=new int[n];
        int *da=new int[n];
        for(int i=0;i<n;i++)
        {
            char ch;
            cin>>xa[i]>>ya[i]>>ch;
            switch(ch)
            {
                case 'R':da[i]=R;break;
                case 'L':da[i]=L;break;
                case 'U':da[i]=U;break;
                case 'D':da[i]=D;break;
            }
            float x=getTime(xe,ye,de,xa[i],ya[i],da[i]);
            if((x<min || min==-1) && x!=-1)
            min=x;
        }

        if(min==-1)
        cout<<"SAFE"<<endl;
        else
        printf("%.1f\n",min);


        delete [] xa;
        delete [] ya;
        delete [] da;
    }
    return 0;
}
