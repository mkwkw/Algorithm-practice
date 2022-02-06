#include <iostream>
#include <vector>

using namespace std;

vector<int> num; //해킹할 수 있는 컴퓨터 수 저장
vector<bool> visited; //방문 여부 저장 -> 사이클인 경우 이용됨
int hack = 0; //해킹할 수 있는 컴퓨터 수

//각 컴퓨터에서 해킹할 수 있는 컴퓨터 수 구하기 
void find_computer(vector<vector<int>> &v, int n, int i){ 
    
    visited[i] = true;

    for(int k=0; k<v[i].size(); k++){ 
        if(!visited[v[i][k]]){
            visited[v[i][k]]=true;
            find_computer(v, n, v[i][k]); //i로 해킹할 수 있는 k에서 조사
            hack++;
        }
    }  
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int max_num = -1;

    cin>>n>>m;

    vector<vector<int>> v(n+1);
    num.assign(n+1,0);
    visited.assign(n+1, false);

    //인접 리스트로 구현
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        v[b].push_back(a);
    }

    for(int i=1; i<n+1; i++){
        find_computer(v, n, i);
        fill(visited.begin(), visited.end(), false); 
        num[i]=hack;
        hack=0;

        if(max_num<num[i]){
            max_num = num[i];
        }
    }
    
    for(int i=1; i<n+1; i++){
        if(num[i]== max_num){
            cout<<i<<' ';
        }
    }
}

//A로 해킹할 수 있는 컴퓨터 B로, B로 해킹할 수 있는 컴퓨터 C로
//이렇게 진행되므로 dfs로 해결한다, 재귀를 이용한다.
//사이클일 때 무한루프를 방지하기 위해 방문배열을 이용한다.
//num[idx]를 직접 증가시켰을 때 오류가 발생하여, 변수로 hack를 생성하였더니 해결되었다.