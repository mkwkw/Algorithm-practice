#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//weight-uionfind

int findParents(int a){ //부모노드 찾기 - 음수
    if(parent[a]<0){
        return a;
    }
    return parent[a] = findParents(parent[a]);
}

void unionParents(int a, int b){ //각각 부모노드 찾아서 집합의 크기가 큰 집합으로 다른 집합 연결
    int ap = findParents(a);
    int bp = findParents(b);

    if(ap==bp){
        return;
    }
    if(parent[ap]<parent[bp]){
        parent[ap] += parent[bp];
        parent[bp] = ap;
    }
    else{
        parent[bp] += parent [ap];
        parent[ap] = bp;
    }

}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n, m;
    int cmd, a, b;
    cin>>n>>m;

    parent.assign(n+1, -1);

    for(int i=0; i<m; i++){
        cin>>cmd>>a>>b;
        if(cmd==0){
            unionParents(a,b);
        }
        if(cmd==1){
            if(findParents(a)==findParents(b)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    
}