#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int N, R, O, Y, G, B, V;
string answer;
int B_new, R_new, Y_new;
bool transform_problem(){
    // BOB
    if(O+1 > B && O > 0){
        if(O+B == N && O == B){
            for(int i = 0;i<O;i++){
                answer.push_back('O');
                answer.push_back('B');
            }
        }
        return false;
    }
    B = B - (O);

    // RGR
    if(G+1 > R && G > 0){
        if(G+R == N && R == G){
            for(int i = 0;i<G;i++){
                answer.push_back('G');
                answer.push_back('R');
            }
        }
        return false;
    }
    R -= G;

    // YVY
    if(V+1 > Y && V > 0){
        if(V+Y == N && V == Y){
            for(int i = 0;i<V;i++){
                answer.push_back('V');
                answer.push_back('Y');
            }
        }
        return false;
    }
    Y -= V;
    return true;
}
int main(){
    int z = 0;
    in_T{
        answer = "";
        z++;
        in_I(N);
        in_I(R);
        in_I(O);
        in_I(Y);
        in_I(G);
        in_I(B);
        in_I(V);
        bool possible = transform_problem();
        if(!possible){
            if(answer.length() > 0){
                printf("Case #%d: %s\n", z, answer.c_str());
            }else
            printf("Case #%d: IMPOSSIBLE\n", z);
            continue;
        }
        set<pair<int, char>> ll;
        ll.insert({-R, 'R'});
        ll.insert({-Y, 'Y'});
        ll.insert({-B, 'B'});
        N = R + Y + B;
        string str;
        possible = true;
        for(auto it = ll.begin(); it != ll.end(); it++){
            if(str.length() == 0){
                if(-it->first > N/2){
                    possible = false;
                }
                for(int i = 0;i<-it->first;i++)
                    str.push_back(it->second);
            }else{
                //disrupt
                int cnt = -it->first;
                for(int i = str.length()-1;i>=0 and cnt;i--){
                    if(str[i] == str[(i+1)%str.length()] && str[i] != it->second){
                        cnt--;
                        if(i+1 == str.length())
                            str.push_back(it->second);
                        else
                            str.insert(i+1, 1, it->second);
                    }
                }
                //not-disrupt
                for(int i = str.length()-1;i>=0 and cnt;i--){
                    if(str[i] != it->second and str[(i+1)%str.length()] != it->second){
                        cnt--;
                        if(i+1 == str.length())
                            str.push_back(it->second);
                        else
                            str.insert(i+1, 1, it->second);
                    }
                }
            }
        }
        if(possible){
            string final_ans = "";
            for(char ch: str){
                final_ans.push_back(ch);
                if(ch == 'R' && G){
                    while(G > 0){
                        final_ans.push_back('G');
                        final_ans.push_back('R');
                        G--;
                    }
                }
                if(ch == 'B' && O){
                    while(O > 0){
                        final_ans.push_back('O');
                        final_ans.push_back('B');
                        O--;
                    }
                }
                if(ch == 'Y' && V){
                    while(V > 0){
                        final_ans.push_back('V');
                        final_ans.push_back('Y');
                        V--;
                    }
                }
            }
            printf("Case #%d: %s\n", z, final_ans.c_str());
        }else{
            printf("Case #%d: IMPOSSIBLE\n", z);
        }
    }
}
