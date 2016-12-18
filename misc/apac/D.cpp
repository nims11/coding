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
int S, R, C;
int dx[4] = {0,1,0,-1};
int dy[4] = {1, 0, -1, 0};
pair<int, int> nextPost(pair<int, int> pos, int dir){
    return make_pair((pos.first + dx[dir] + R)%R, (pos.second+dy[dir] +C)%C);
}
int main(){
    int z = 0;
    in_T{
        z++;
        in_I(S);in_I(R);in_I(C);
        queue<pair<int, int> > snake;
        set<pair<int, int> > pos;
        vector<pair<int, int> > commands;
        for(int i = 0;i<S;i++){
            int t;char c;
            scanf("%d %c", &t, &c);
            commands.push_back(make_pair(t, (c=='L'?-1:1)));
        }
        int curTime = 0;
        pair<int, int> head = make_pair(0, 0);
        set<pair<int, int> > food;
        int curDir = 0;
        snake.push(head);
        pos.insert(head);
        bool shit = true;
        for(int i = 0;shit && i<commands.size();i++){
            while(shit && curTime < commands[i].first){
                pair<int, int> tail = snake.front();
                pair<int, int> nxtPos = nextPost(head, curDir);
                bool takeFood = false;
                if((nxtPos.first+nxtPos.second)%2 == 1){
                    if(food.find(nxtPos) == food.end()){
                        takeFood = true;
                        food.insert(nxtPos);
                    }
                }
                if(takeFood){

                }else{
                    snake.pop();
                    pos.erase(tail);
                }
                if(pos.find(nxtPos) != pos.end()){
                    shit = false;
                    break;
                }
                head = nxtPos;
                pos.insert(head);
                snake.push(head);
                curTime++;
            }
            // cout<<head.first<<" "<<head.second<<endl;
            curDir = (commands[i].second + curDir + 4)%4;
        }
        while(shit && curTime < 10000000){
            pair<int, int> tail = snake.front();
            pair<int, int> nxtPos = nextPost(head, curDir);
            bool takeFood = false;
            if((nxtPos.first+nxtPos.second)%2 == 1){
                if(food.find(nxtPos) == food.end()){
                    takeFood = true;
                    food.insert(nxtPos);
                }
            }
            if(takeFood){

            }else{
                snake.pop();
                pos.erase(tail);
            }
            if(pos.find(nxtPos) != pos.end()){
                shit = false;
                break;
            }
            head = nxtPos;
            pos.insert(head);
            snake.push(head);
            curTime++;
        }
        cout<<"Case #"<<z<<": "<<pos.size()+int(!shit)<<endl;
    }
}
