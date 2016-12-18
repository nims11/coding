// Flow Adj 1-based
int res[201][201];
int find_path(int src, int dest, int n){
    int ret = -1, backlink[n+1];
    queue<int> BFS;BFS.push(src);
    memset(backlink, 0, sizeof(backlink));
    backlink[src] = -1;
    while(!BFS.empty()){
        int x = BFS.front();BFS.pop();
        if(x == dest){
            ret = 1000;
            while(backlink[x] != -1){
                int pre = backlink[x];
                ret = min(ret, res[pre][x]);
                x = pre;
            }
            x = dest;
            while(backlink[x] != -1){
                int pre = backlink[x];
                res[pre][x] -= ret;
                res[x][pre] += ret;
                x = pre;
            }
            return ret;
        }
        for(int i = 1;i<=n;i++)
            if(i != x && !backlink[i] && res[x][i])
                backlink[i] = x, BFS.push(i);
    }
    return ret;
}
int max_flow(int src, int sink, int n){
    int ret = 0, path_capacity;
    while((path_capacity = find_path(src, sink, n)) != -1)
        ret += path_capacity;
    return ret;
}

// Flow General Graph
struct node{
    map<node*, int> edges;
}nodes[1000000];
int cnt = 0;
node* nxtNode(){
    nodes[cnt].edges.clear();
    return &nodes[cnt++];
}
int find_path(node *src, node *dest){
    int ret = -1;
    map<node*, node*> backlink;
    queue<node*> BFS;BFS.push(src);
    backlink[src] = 0;
    while(!BFS.empty()){
        node *x = BFS.front();BFS.pop();
        if(x == dest){
            ret = 1000;
            while(backlink[x] != 0){
                node *pre = backlink[x];
                ret = min(ret, pre->edges[x]);
                x = pre;
            }
            x = dest;
            while(backlink[x] != 0){
                node *pre = backlink[x];
                pre->edges[x] -= ret;
                x->edges[pre] += ret;
                x = pre;
            }
            return ret;
        }
        for(map<node*, int>::iterator it = x->edges.begin(); it != x->edges.end(); it++)
            if(backlink.find(it->first) == backlink.end() && it->second)
                backlink[it->first] = x, BFS.push(it->first);
    }
    return ret;
}
int max_flow(node *src, node *sink){
    int ret = 0, path_capacity;
    while((path_capacity = find_path(src, sink)) != -1)
        ret += path_capacity;
    return ret;
}

// Max Matching Bipartite
vector<vector<int> > neigh;
int bw[100000]; // all -1s
int vis[100000];
int find_path(int n){
    if(vis[n])
        return 0;
    vis[n] = 1;
    for(int i = 0;i<neigh[n].size();i++)
        if(bw[neigh[n][i]] == -1 || find_path(bw[neigh[n][i]])){
            bw[neigh[n][i]] = n;
            return 1;
        }
    return 0;
}
int max_flow(){
    int res = 0;
    for(int i = 0;i<neigh.size();i++){
        if(neigh[i].size() == 0)
            continue;
        memset(vis, 0, sizeof(int)*neigh.size());
        res += find_path(i);
    }
    return res;
}

// Dinic Adjancency
int max_flow_dinic(int src, int sink, int n){
    int ret = 0;
    int prev[n+1];
    while(1){
        queue<int> BFS;
        memset(prev, 0, sizeof(prev));
        prev[src] = -1;
        BFS.push(src);
        while(!BFS.empty() && !prev[sink]){
            int curr = BFS.front();
            BFS.pop();
            for(int i = 1;i<=n;i++)
                if(!prev[i] && res[curr][i])
                    prev[i] = curr, BFS.push(i);
        }
        if(!prev[sink])
            break;
        for(int i = 1;i<=n; i++){
            if(res[i][sink] && prev[i]){
                int inc = res[i][sink];
                for(int u = prev[i], v = i; u>=0; inc = min(inc, res[u][v]), v = u, u = prev[u]);
                for(int u = i, v = sink; u>=0; res[u][v]-=inc, res[v][u]+=inc, v = u, u = prev[u]);
                ret += inc;
            }
        }
    }
    return ret;
}
