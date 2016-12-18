int n;
int aux[100002][22];
int LOG2[100002];
int RMQ(int x, int y){
    int k = LOG2[y-x+1];
    return min(aux[x][k], aux[y-(1<<k)+1][k]);
}
void init(){
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<=100001;i++){
        if(i == curr){
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }

    for(int i=1;i<=n;i++)
        in_I(aux[i][0]);
    for(int j=1; (1<<j)<=n+1; j++)
        for(int i=1;i+(1<<j)<=n+1;i++)
            aux[i][j] = min(aux[i][j-1], aux[i+(1<<(j-1))][j-1]);
}
