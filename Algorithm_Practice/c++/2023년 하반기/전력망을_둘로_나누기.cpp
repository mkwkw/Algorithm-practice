#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> connected;
int cnt;
void findTowerCnt(int n, int startNode, int parentNode, int cutNode){
    cout<<n<<' '<<startNode<<' '<<parentNode<<' '<<cutNode<<" cnt "<<cnt<<'\n';
    bool flag = true;
    for(int i=0; i<n; i++){
        if(connected[startNode][i] && i!=startNode && i!=cutNode && i!=parentNode){
            flag = false;
            ++cnt;
            findTowerCnt(n, startNode, i, cutNode);
        }
    }
    
    if(flag){
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
        
        cnt = 1;
        findTowerCnt(n, a, a, b); //네트워크 a
        int aCnt = cnt;
        cout<<"aCnt "<<aCnt<<'\n';
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