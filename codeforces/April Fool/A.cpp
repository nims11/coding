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
int main()
{
    string foo[] ={"Washington", "Adams", "Jefferson", "Madison", "Monroe", "Quincy Adams", "Jackson", "Van Buren", "Henry Harrison", "Tyler", "K. Polk", "Taylor", "Fillmore", "Pierce", "Buchanan",
    "Lincoln", "Johnson", "S. Grant", "B. Hayes", "Garfield", "A. Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Howard Taft", "Wilson",
    "Harding", "Coolidge", "Hoover", "D. Roosevelt", "S. Truman",  "D. Eisenhower", "F. Kennedy", "F. Kennedy", "Nixon", "Ford", "Carter", "Reagan"};
    int n;

    in_I(n);
    cout<<foo[n-1]<<endl;
}
