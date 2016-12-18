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
int main()
{
    int n;
    cin>>n;
    int L[n], R[n];
    for(int i = 0;i<n;i++)
        cin>>L[i]>>R[i];
    long double res = 0.0f;
    for(int i = 0;i<n;i++){
        for(int j =1;j<=10000;j++){
            long double prob = j*(long double)max(0, R[i]-max(j, L[i]-1))/(long double)(R[i]-L[i]+1), px = 1, px_1 = 1;
            long double pp = 0;
            // if(j<=10 && i == 1)
            //     cout<<j<<" "<<prob<<" "<<px<<" "<<px_1<<endl;
            for(int mask = 1;mask<(1<<n);mask++){
                if(mask & (1<<i))continue;
                long double p = 1;
                for(int k = 0;k<n;k++){
                    if(k == i)continue;
                    if(mask & (1<<k)){
                        if(j >= L[k] && j <=R[k])
                            p *= 1/(long double)(R[k]-L[k]+1);
                        else
                            p = 0;
                    }else {
                        if(j > L[k])
                            p *= (min(j-1, R[k])-L[k]+1)/(long double)(R[k]-L[k]+1);
                        else
                            p *= 0;
                    }
                }
                pp+=p;
            }

            prob *= pp;

            // for(int k = 0;k<n;k++){
            //     if(k!=i){
            //         px *= max(0, min(j, R[k])-L[k]+1)/(long double)(R[k]-L[k]+1);
            //         px_1 *= max(0, min(j, R[k])-L[k]+1-1)/(long double)(R[k]-L[k]+1);
            //     }
            // }
            // prob *= (px-px_1);
            // if(j<=10 && i == 1)
            //     cout<<j<<" "<<prob<<" "<<px<<" "<<px_1<<endl;
            res += prob;
        }
    }
    // cout<<res<<endl;
    for(int j = 1;j<=10000;j++){
        for(int mask = 1;mask<(1<<n);mask++){
            if(__builtin_popcount(mask) < 2)
                continue;
            long double prob = j, px = 1,  px_1 = 1;
            for(int i = 0;i<n;i++){
                if(mask & (1<<i)){
                    prob *= 1/(long double)(R[i]-L[i]+1);
                    if(j<L[i] || j>R[i])
                        prob = 0;
                }else{
                    if(j > L[i])
                        px *= (min(j-1, R[i])-L[i]+1)/(long double)(R[i]-L[i]+1);
                    else
                        px *= 0;
                }
            }
            prob *= (px);
            res += prob;
        }
    }
    cout<<std::fixed;
    cout<<std::setprecision(10)<<res<<endl;
}
