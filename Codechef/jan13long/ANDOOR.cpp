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

const long double pi = acos(-1);
class circle
{
    public:
    long long x,y,r;
    bool status;
}cirs[1000];
class intersection
{
public:
    long double theta;
    bool entry;
    int id;
    friend bool operator<(const intersection &a, const intersection &b)
    {
        return a.theta<b.theta;
    }
}tmp_int;
long long SQR(long long a)
{
    return a*a;
}
long double SQR(long double a)
{
    return a*a;
}
long long DIST2(circle &a, circle &b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int main()
{
    in_T
    {
        int N;
        long long W,H;

        int a,b,c,d,e,f;
        scanf("%lld%lld%d", &W, &H, &N);
//        scanf("%d%d%d", &H, &W, &N);
        for(int i=0;i<N;i++)
        {
//            scanf("%lf%lf%lf", &cirs[i].y, &cirs[i].x, &cirs[i].r);
            scanf("%d.%d %d.%d %d.%d", &a,&b,&c,&d,&e,&f);
            cirs[i].x = (a*100+b), cirs[i].y = (c*100+d), cirs[i].r = (e*100+f);
            cirs[i].status = true;
        }
        W*=100;
        H*=100;
        bool flag = false;
        for(int i=0;i<N;i++)
        {
            if(!cirs[i].status)continue;
            long long q,w,e,r,Q = SQR(cirs[i].r);
            q = SQR(cirs[i].x)+SQR(cirs[i].y);
            w = SQR(cirs[i].x-W)+SQR(cirs[i].y);
            e = SQR(cirs[i].x)+SQR(cirs[i].y-H);
            r = SQR(cirs[i].x-W)+SQR(cirs[i].y-H);
            if(q<=Q && w<=Q && e<=Q && r<=Q)
            {
                printf("%.7lf\n",0.00000000);
                flag = true;
                break;
            }
            if(cirs[i].x-cirs[i].r>=W || cirs[i].y-cirs[i].r>=H)
                cirs[i].status = false;

            for(int j=i+1;j<N;j++)
            {
                if(!cirs[i].status)
                    break;
                if(!cirs[j].status)continue;
                if(DIST2(cirs[i],cirs[j])<=SQR(cirs[i].r-cirs[j].r))
                    {if(cirs[i].r>cirs[j].r)
                    cirs[j].status = false;
                    else
                    cirs[i].status = false;
                    }
            }
        }
        if(flag)continue;
        long double ans = 0;
        for(int i=0;i<N;i++)
        {
            if(!cirs[i].status)continue;

            vector<intersection> inter;
            int cnt = 0;
            for(int j=0;j<N;j++)
            {
                if(i!=j && cirs[j].status && DIST2(cirs[i], cirs[j])<SQR(cirs[i].r+cirs[j].r))
                {

                    long double m ,c;
                    long double xx1,xx2,yy1,yy2;
                    if((cirs[i].y)==cirs[j].y)
                    {
                        m = (SQR(cirs[j].r)-SQR(cirs[i].r))/((long double)2.0*(-cirs[j].x+cirs[i].x));
                        c = (cirs[i].x+cirs[j].x)/2.0;
                        xx1 = xx2 = m+c;
//                        if(SQR(cirs[i].r)-SQR(xx1-cirs[i].x)<0)
//                            xx1 = xx2 = -m+c;
                        if(SQR(cirs[i].r)-SQR(xx1-cirs[i].x)<0)return -1;
                        yy1 = sqrtl(SQR(cirs[i].r)-SQR(xx1-cirs[i].x));
                        yy2 = yy1 + cirs[i].y;
                        yy1 = -yy1 + cirs[i].y;
                    }else
                    {
                        m = -(cirs[j].x-cirs[i].x)/(long double)(cirs[j].y-cirs[i].y);
                        c = (SQR(cirs[i].r)-SQR(cirs[j].r)+SQR(cirs[j].x)-SQR(cirs[i].x)+SQR(cirs[j].y)-SQR(cirs[i].y))/((long double)2*(cirs[j].y-cirs[i].y));
                        long double A,B,C;
                        A = (1+m*m);
                        B = 2*(m*c-m*cirs[i].y-cirs[i].x);
                        C = SQR(cirs[i].x) + SQR((c-cirs[i].y))-SQR(cirs[i].r);
                        if(B*B-4*A*C<0)return -1;
                        long double D = sqrtl(B*B-4*A*C);

                        xx1 = (-B+D)/(2*A);
                        xx2 = (-B-D)/(2*A);
                        yy1 = m*xx1+c;
                        yy2 = m*xx2+c;
                    }
                    long double theta1, theta2, theta_mid;
                    theta1 = atan2((yy1-cirs[i].y),(xx1-cirs[i].x));
                    theta2 = atan2((yy2-cirs[i].y),(xx2-cirs[i].x));
//                        cout<<j<<" "<<theta1<<" "<<theta2<<endl;

                    if(theta1<0)
                        theta1+=2*pi;
                    if(theta2<0)
                        theta2+=2*pi;

                    theta_mid = (theta1+theta2)/2;
                    if(theta1>theta2)
                    {
                        long double tmp = theta1;
                        theta1 = theta2;
                        theta2 = tmp;
                    }
                    xx1 = cirs[i].x+cirs[i].r*cos(theta_mid);
                    yy1 = cirs[i].y+cirs[i].r*sin(theta_mid);
                    tmp_int.id = cnt++;
                    if(SQR(xx1-cirs[j].x)+SQR(yy1-cirs[j].y)-SQR(cirs[j].r)<0)
                    {
                        tmp_int.theta = theta1;
                        tmp_int.entry = true;
                        inter.push_back(tmp_int);

                        tmp_int.theta = theta2;
                        tmp_int.entry = false;
                        inter.push_back(tmp_int);
                    }else
                    {
                        tmp_int.theta = theta1;
                        tmp_int.entry = false;
                        inter.push_back(tmp_int);

                        tmp_int.theta = theta2;
                        tmp_int.entry = true;
                        inter.push_back(tmp_int);
                    }
                }
            }

            //x=0
            if(SQR(cirs[i].r)-SQR(cirs[i].x)>0)
            {
                long double foo = sqrtl(SQR(cirs[i].r)-SQR(cirs[i].x));
                long double yy1 = foo+cirs[i].y;
                long double yy2 = -foo+cirs[i].y;
                long double theta1, theta2;
                tmp_int.id = cnt++;
                {
                    tmp_int.theta = atan2((yy1-cirs[i].y),-cirs[i].x);
                    tmp_int.entry = true;
                    if(tmp_int.theta<0)tmp_int.theta += 2*pi;
                    inter.push_back(tmp_int);

                    tmp_int.theta = atan2((yy2-cirs[i].y),-cirs[i].x);
                    tmp_int.entry = false;
                    if(tmp_int.theta<0)tmp_int.theta += 2*pi;
                    inter.push_back(tmp_int);
                }
            }

            //x=w
            if(SQR(cirs[i].r)-SQR(cirs[i].x-W)>0)
            {
                long double foo = sqrtl(SQR(cirs[i].r)-SQR(cirs[i].x-W));
                long double yy1 = foo+cirs[i].y;
                long double yy2 = -foo+cirs[i].y;
                long double theta1, theta2;
                tmp_int.id = cnt++;
                {
                    tmp_int.theta = atan2(-(cirs[i].y-yy1),-(cirs[i].x-W));
                    if(tmp_int.theta<0)
                        tmp_int.theta += 2*pi;
                    tmp_int.entry = false;
                    inter.push_back(tmp_int);

                    tmp_int.theta = atan2(-(cirs[i].y-yy2),-(cirs[i].x-W));
                    tmp_int.entry = true;
                    if(tmp_int.theta<0)
                        tmp_int.theta += 2*pi;
                    inter.push_back(tmp_int);
                }
            }
            //y=0
            if(SQR(cirs[i].r)-SQR(cirs[i].y)>0)
            {
                long double foo = sqrtl(SQR(cirs[i].r)-SQR(cirs[i].y));
                long double xx1 = foo+cirs[i].x;
                long double xx2 = -foo+cirs[i].x;
                long double theta1, theta2;
                tmp_int.id = cnt++;
                {
                    tmp_int.theta = atan2(-(cirs[i].y),-(cirs[i].x-xx1));
                    if(tmp_int.theta<0)tmp_int.theta += 2*pi;
                    tmp_int.entry = false;
                    inter.push_back(tmp_int);

                    tmp_int.theta = atan2(-(cirs[i].y),-(cirs[i].x-xx2));
                    if(tmp_int.theta<0)tmp_int.theta += 2*pi;
                    tmp_int.entry = true;
                    inter.push_back(tmp_int);
                }
            }

            //y=H
            if(SQR(cirs[i].r)-SQR(cirs[i].y-H)>0)
            {
                long double foo = sqrtl(SQR(cirs[i].r)-SQR(cirs[i].y-H));
                long double xx1 = foo+cirs[i].x;
                long double xx2 = -foo+cirs[i].x;
                long double theta1, theta2;
                tmp_int.id = cnt++;
                {
                    tmp_int.theta = atan2(-(cirs[i].y-H),-(cirs[i].x-xx1));
                    if(tmp_int.theta<0)tmp_int.theta += 2*pi;
                    tmp_int.entry = true;
                    inter.push_back(tmp_int);

                    tmp_int.theta = atan2(-(cirs[i].y-H),-(cirs[i].x-xx2));
                    if(tmp_int.theta<0)
                        tmp_int.theta += 2*pi;
                    tmp_int.entry = false;
                    inter.push_back(tmp_int);
                }
            }

            sort(inter.begin(), inter.end());

            int open = 0;
            int status[cnt+1];
            for(int j=0;j<=cnt;j++)
                status[j] = 0;
            //turn1
            for(int j=0;j<inter.size();j++)
            {

//                cout<<inter[j].id<<" "<<inter[j].theta<<" "<<inter[j].entry<<endl;
                if(inter[j].entry == true)
                {
                    open++;
                    status[inter[j].id] = 1;
                }else
                {
                    if(status[inter[j].id] == 1)
                    {
                        status[inter[j].id] = 0;
                        open--;
                    }
                }
            }

            //turn2
            for(int j=0;j<inter.size();j++)
            {
                if(inter[j].entry == true)
                {
                    open++;
//                    status[inter[j].id] = 1;
                }else
                {
//                    if(status[inter[j].id] == 1)
                    {
//                        status[inter[j].id] = 0;
                        open--;
                        if(open==0)
                        {
                            if(j==inter.size()-1)
                            {
                                ans += (cirs[i].r*(2*pi-(inter[j].theta-inter[0].theta)))/100;
                            }else
                            {
                                ans += (cirs[i].r*(inter[j+1].theta-inter[j].theta))/100;
                            }
                        }
                    }
                }
            }
            if(inter.size()==0)
            {
                ans += (2.0*pi*cirs[i].r)/100;
            }
        }
        printf("%.7llf\n",ans);
    }
}
