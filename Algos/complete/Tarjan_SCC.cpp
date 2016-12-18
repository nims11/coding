int n;
struct vertex{
    vector<int> neigh;
    int index, component, lowlink;
}v_tmp, vertices[10000];
bool visited[10000];
stack<int> DFS;
int index;
int connected;
void strongconnect(int id){
    vertices[id].index = vertices[id].lowlink = index;
    index++;
    DFS.push(id);
    visited[id] = true;
    int w;
    for(int j=0;j<vertices[id].neigh.size(); j++){
        w = vertices[id].neigh[j];
        if(vertices[w].index == -1){
            strongconnect(w);
            vertices[id].lowlink = min(vertices[id].lowlink, vertices[w].lowlink);
        }else if(visited[w])
            vertices[id].lowlink = min(vertices[id].lowlink, vertices[w].index);
    }
    if(vertices[id].lowlink == vertices[id].index){
        do{
            w = DFS.top();
            DFS.pop();
            visited[w] = false;
            vertices[w].component = connected;
        }while(id != w);
        connected++;
    }
}
int scc(){
    index=0;
    connected = 0;
    for(int i=0;i<n;i++)
        if(vertices[i].index == -1)
            strongconnect(i);
}
