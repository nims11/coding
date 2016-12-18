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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
bool getans(vector<int> &arr, int st){
    int curTop = arr[st];
    int curBot = arr[st];
    int curid1, curid2;
    curid1 = 0, curid2 = arr.size()-1;
    if(curid1 == st)curid1++;
    else curid2--;
    while(curid1<=curid2){
        if(arr[curid1] == curBot+1){
            curid1++;
            curBot++;
        }else if(arr[curid1] == curTop-1){
            curid1++;
            curTop--;
        }else if(arr[curid2] == curBot+1){
            curid2--;
            curBot++;
        }else if(arr[curid2] == curTop-1){
            curid2--;
            curTop--;
        }else
            return false;
    }
    return true;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i<N;i++)
            cin>>arr[i];
        cout<<(getans(arr, 0) || getans(arr, N-1)?"yes":"no")<<endl;
    }
}
