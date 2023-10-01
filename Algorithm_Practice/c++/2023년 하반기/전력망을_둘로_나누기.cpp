#include <string>
#include <vector>
#include <iostream>

using namespace std;

//완전탐색, 재귀
//1. 인접 행렬 만들기 (n이 100 이하이므로 충분히 작음)
//2. wires를 순차적으로 돌면서, [a,b]일 때, a와 b 사이에 전선을 끊는 것으로 가정 - 트리 구조이기 때문에 가능(사이클 X)
//  a가 포함되는 네트워크의 송전탑 수, b가 포함되는 네트워크의 송전탑 수를 재귀로 계산 - visited 배열 이용
vector<vector<bool>> connected;
vector<bool> visited;
int cnt;
void findTowerCnt(int n, int startNode, int parentNode, int cutNode){
    cout<<n<<' '<<startNode<<' '<<parentNode<<' '<<cutNode<<" cnt "<<cnt<<'\n';
    bool flag = true;
    for(int i=0; i<n; i++){
        if(connected[parentNode][i] && i!=startNode && i!=cutNode && i!=parentNode && !visited[i]){
            flag = false;
            ++cnt;
            visited[i] = true;
            cout<<"pass "<<n<<" parent "<<parentNode<<' '<<i<<' '<<'\n';
            findTowerCnt(n, startNode, i, cutNode);
        }
    }
    
    if(flag){
        cout<<"end\n";
        return;
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    vector<int> towerCnt;
    
    connected.assign(n, vector<bool>(n, false));
    towerCnt.assign(n, 0);
    
    for(int i=0; i<wires.size(); i++){
        connected[wires[i][0]-1][wires[i][1]-1] = true;
        connected[wires[i][1]-1][wires[i][0]-1] = true;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<connected[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    
    for(int i=0; i<wires.size(); i++){
        int a = wires[i][0]-1;
        int b = wires[i][1]-1;
        
        visited.assign(n, false);
        visited[a] = true;
        cnt = 1;
        findTowerCnt(n, a, a, b); //네트워크 a
        int aCnt = cnt;
        cout<<"aCnt "<<aCnt<<'\n';

        visited.assign(n, false);
        visited[b] = true;
        cnt = 1;
        findTowerCnt(n, b, b, a); //네트워크 b
        int bCnt = cnt;
        cout<<"bCnt "<<bCnt<<'\n';
        
        if(abs(aCnt-bCnt)<answer){
            answer = abs(aCnt-bCnt);
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> wires = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
    int result = solution(9, wires);
    cout<<result;
}