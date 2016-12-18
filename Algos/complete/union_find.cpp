int set_parent[1000101];
void set_union(int s1, int s2){
    if(s2 < s1)
        set_union(s2, s1);
    else{
        set_parent[s2] = s1;
    }
}
int set_find(int x){
    if(set_parent[x] == x)
        return x;
    return (set_parent[x]=set_find(set_parent[x]));
}

