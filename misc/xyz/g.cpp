#include<bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
using namespace std;
struct State{
    int val;
    State(){}
    State(int inp){
        val = inp;
    }
    State left(int row);
    State right(int row);
    State up(int col);
    State down(int col);
};
State State::left(int row){
    State st(val);
    for(int i = 0;i<4;i++){
        int val1 = 
        st.val &= (1<<);
        st.val[row*4+i] &= ~(3<<((row*4+1)*2));
        st.val[row*4+i] = val[row*4 + ((i+1)%4)];
    }
    return st;
}
State State::right(int row){
    State st(val);
    for(int i = 0;i<4;i++){
        st.val[row*4 + ((i+1)%4)] = val[row*4+i];
    }
    return st;
}
State State::up(int col){
    State st(val);
    for(int i = 0;i<4;i++){
        st.val[i*4 + col] = val[((i+1)%4)*4 + col];
    }
    return st;
}
State State::down(int col){
    State st(val);
    for(int i = 0;i<4;i++){
        st.val[((i+1)%4)*4 + col] = val[i*4+col];
    }
    return st;
}
int main(){

}
