#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

int main(){
    int z, t;
    cin>>t;
    for(z=1;z<=t;z++){
        int n;
        cin>>n;
        vector<int> cnt(n);
        for(int  i = 0;i<n;i++)
            cin>>cnt[i];
        cout<<"Case #"<<z<<": ";
        int rem = n;
        while(rem > 0){
            int maxi = 0;
            for(int i = 0;i<n;i++){
                if(cnt[i] > cnt[maxi])
                    maxi = i;
            }

            if(rem == 2){
                for(int i = 0;i<n;i++){
                    if(i != maxi && cnt[i] != 0){
                        if(cnt[i] == cnt[maxi]){
                            cnt[i]--;
                            cnt[maxi]--;
                            if(cnt[i] == 0)
                                rem = 0;
                            cout<<char('A'+maxi)<<char('A'+i)<<" ";
                            break;
                        }
                    }
                }
            }else{
                cnt[maxi]--;
                cout<<char('A'+maxi)<<" ";
                if(cnt[maxi] == 0)rem--;
            }
        }
        cout<<endl;
    }
}
