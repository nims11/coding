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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
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

int d[202][202];
int cost[2003][2003];
int back[2003][2003];
int let[2][2003][2003];

int A[2002];
int B[2002];

map<char, int> m;
map<int, char> rm;
map<int, int> leastRow;
map<int, int> leastCol;


void calc(int i, int j){

    if(i==0 && j==0){        
        cost[i][j] = 0;
        return;
    }

    if(cost[i][j]!=-1)return;
   
    //consider i j compared
    int c1;
    if(i>0 && j>0){
        calc(i-1,j-1);
        c1 = cost[i-1][j-1] + d[ A[i] ][B[ j ]];
    }
    else{
        c1 = 1e9;
    }

    int c2;
    if( i <= 0 )
        c2 = 1e9;
    else  {
        calc(i-1, j);
        c2= (cost[i-1][j] + d[A[i]][leastRow[A[i]]]);
    }

    int c3;
    if( j<=0 ){
        c3 = 1e9;
        
    }
    else{
        calc(i, j-1);
         c3 = cost[i][j-1] + d[leastCol[B[j]]][B[j]];
    }



    int ans = c1;
    back[i][j] = 0;
   
    if( c2 < ans ){
        back[i][j] = 1;
        ans = c2;
    }
    if( c3 < ans ){
        back[i][j] = 2;
        ans = c3;
    }
    cost[i][j] = ans;
    if(back[i][j] == 0){
        let[0][i][j] = A[i];
        let[1][i][j] = B[j];

    }
    else if(back[i][j] == 1){
        let[0][i][j] = A[i];
        let[1][i][j] = leastRow[ A[i] ];
    }
    else if(back[i][j] == 2){
        let[0][i][j] = leastCol[ B[j]  ];
        let[1][i][j] = B[j];
    }
//    cout<<i<<" "<<j<<" "<<cost[i][j]<<" "<<back[i][j]<<endl;
    

}
FILE *fin = fopen("dissim.in", "r");
FILE *fout = fopen("dissim.out", "w");
char tmpp[2003], tmp[2003];
int main()
{
    fscanf(fin, "%s", tmpp);
    string sigma(tmpp);
    int n = sigma.size();
    int cnt = 0;
    for(int i=0; i<2003; i++){
        for(int j=0; j<2003; j++){
            cost[i][j] = -1;
        }
    }
    
    for(int i=0; i<n; i++){
        if(m.find(sigma[i])==m.end()){
                    m[ sigma[i] ] = cnt;
                    rm[cnt] = sigma[i];
                    cnt++;
                }
    }
    fscanf(fin, "%s%s", tmp, tmpp);
    string a(tmp),b(tmpp);
    
    for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        fscanf(fin, "%d", &d[i][j]);
    }
    }

    for(int i=0; i<n; i++){
        leastRow[i] = 0;       
        leastCol[i] = 0;  
        for(int j=0; j<n; j++){
            if( d[i][j] < d[i][leastRow[i]] ){
                 leastRow[i] = j;
            }
            if( d[j][i] < d[leastCol[i]][i] ){
                leastCol[i] = j;
            }


        }    
    }
    int len = a.size();
    for(int i=1; i<=len; i++){
        A[i] = m[ a[i-1] ];
    }
    len = b.size();
    for(int i=1; i<=len; i++){
        B[i] = m[ b[i-1] ];
    }
    calc(a.size(), b.size());
    string ans1 = "";
    string ans2 = "";
    int i = a.size();
    int j = b.size();

    while(i!=0 || j!=0){
        ans1.push_back( rm[let[0][i][j]] );
        ans2.push_back( rm[let[1][i][j]] );
        if( back[i][j] == 0 ){
            i--; j--;
        }
        else if( back[i][j] == 1 ){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    fprintf(fout, "%d\n", cost[a.size()][b.size()]);
    fprintf(fout, "%s\n", ans1.c_str());
    fprintf(fout, "%s\n", ans2.c_str());
}
