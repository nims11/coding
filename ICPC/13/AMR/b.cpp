    #include<stdio.h>
    #include<iostream>
    using namespace std;

    int main()
    {
    int T, N, M, Ans;
    int left, right;
    int lim1,lim2, lim;
    int flag1, flag2, hs;
    cin>>T;

    while(T--)
    {
    Ans=0;
    cin>>N>>M;
    char S[N+1][M+1];
    //getchar();
    for(int i=0; i<N; i++)
    cin>>S[i];
    for(int i=0; i<N; i++){
    for(int j=i; j<N; j++) {
    for(int p=0; p<M; p++){
    for(int q=p; q<M; q++){// to check again
    left=j-i , right=q-p;
    if( Ans >= (left+1)*(right+1) ) continue;
    hs=0, lim=hs+left;
    while(lim < N){
    lim1=flag2=0;
    lim2 = lim1 + right;
    while(lim2 < M) {
    flag1=1;
    for(int r=i,i2=hs; r<=j; r++,i2++){
    for(int s=p,j2=lim1; s<=q; s++,j2++){
    if( S[r][s]==S[i2][j2] && !(i==hs && j==lim && p==lim1 && q==lim2)) continue;
    else { flag1=0; break; }
    }
    }
    if(flag1) { Ans = max(Ans,(left+1)*(right+1)); flag2 = 1; break; }
    lim1++, lim2++;
    }
    if(flag2) break;
    hs++, lim++;
    }}}}}
    cout<<Ans<<endl;
    }
    return 0;
    }
