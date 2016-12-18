/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
double getans(int mask, long long a, long long b, long long c, long long d){
    int c_a = (mask&(1<<0))?1:-1;
    int c_b = (mask&(1<<1))?1:-1;
    int c_c = (mask&(1<<2))?1:-1;
    int c_d = (mask&(1<<3))?1:-1;

    long long A = (c_a*c_b)-(c_c*c_d);
    long long  B = a*c_b + b*c_a - c*c_d - d*c_c;
    long long  C = a*b - c*d;
    // if(mask == 3)
    // cout<<c_a<<" "<<c_b<<" "<<c_c<<" "<<c_d<<" "<<A<<" "<<B<<" "<<C<<endl;
    if(A == 0){
        if(B == 0 && C == 0)return 0;
        if(B == 0)return -10;
        return abs(-C/double(B));
    }

    double D = B*double(B) - 4*double(A)*C;
    if(D < 0-1e-6)
        return -10;
    double DD = sqrt(double(D));
    // if(mask == 3)
    //     cout<<DD<<endl;
    double x1 = (-B + DD)/double(2*A);
    double x2 = (-B - DD)/double(2*A);
    return min(abs(x1), abs(x2));
}
int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    vector<double> res;
    for(int i = 0;i<(1<<4);i++){
        double r = getans(i, a, d, b, c);
        if(r >= -1)
            res.push_back(r);
    }
    sort(BE(res));
    printf("%.10lf\n", res[0]);
}
