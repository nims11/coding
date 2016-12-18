#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    sort(x.begin(), x.end());
    for(int i = 1;i<n;i++)
        x[i] -= x[0];
    x[0] = 0;
    int cur = 0;
    int ans = 0;
    for(int i = 1;i<n;i++){
        int diff = x[i] - x[i-1];
        cout<<x[i]<<" "<<cur<<" "<<diff<<endl;
        
        if(cur + diff > k+1){
            ans++;
            cur = -k;
            cout<<"NOW"<<endl;
            while(i < n && cur <= 0){
                cur += x[i] - x[i-1];
                i++;
            }
        }else
            cur += diff;
    }
    if(cur > 0)
        ans++;
    cout<<ans<<endl;
    return 0;
}

