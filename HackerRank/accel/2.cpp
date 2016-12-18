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
int N;
string P1[1001], P2[1001];
bool test(int s){
    string str1[4], str2[4];
    // cout<<s<<endl;
    for(int i = s;i<N-s;i++){
        str1[0].push_back(P1[s][i]);
        str2[0].push_back(P2[s][i]);
        str1[1].push_back(P1[i][N-s-1]);
        str2[1].push_back(P2[i][N-s-1]);
        str1[2].push_back(P1[N-s-1][N-i-1]);
        str2[2].push_back(P2[N-s-1][N-i-1]);
        str1[3].push_back(P1[N-i-1][s]);
        str2[3].push_back(P2[N-i-1][s]);
    }
    for(int i = 0;i<4;i++){
        // cout<<str1[i]<<endl;
        bool flag = true;
        for(int j = 0;j<4;j++){
            if(str1[j] != str2[(j+i)%4])
                flag = false;
        }
        if(flag == true)return true;
    }
    return false;
}
int main()
{
    cin>>N;
    cin.ignore(1);
    for(int i = 0;i<N;i++)
        getline(cin, P1[i]);
    for(int i = 0;i<N;i++)
        getline(cin, P2[i]);
    for(int i = 0;i<(N+1)/2;i++){
        if(!test(i)){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
