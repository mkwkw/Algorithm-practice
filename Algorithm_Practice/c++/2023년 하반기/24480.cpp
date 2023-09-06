#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//dfs
vector<int> visited;
int order = 1, n;
void dfs(int r, vector<vector<int>> &node){

    visited[r] = order++;

    //내림차순으로 탐색
    for(int i=node[r].size()-1; i>=0; i--){
        if(visited[node[r][i]]==0){
            dfs(node[r][i], node);
        }
    }

}
int main(){
    int m, r;

    cin>>n>>m>>r;

    vector<vector<int>> node(n+1);
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    //내림차순으로 탐색해야하므로 정렬 필요
    for(int i=1; i<=n; i++){
        sort(node[i].begin(), node[i].end());
    }

    dfs(r, node);

    for(int i=1; i<=n; i++){
        cout<<visited[i]<<'\n';
    }

}