#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<pair<int,int>> house, chicken, temp;
vector<bool> visited;
int n,m, answer=1e9;

int countDistance(){
    int result = 0;
    for(int i=0; i<house.size(); i++){
        int tempDist = 1e9;
        for(int j=0; j<temp.size(); j++){
            tempDist = min(tempDist, abs(house[i].first - temp[j].first) + abs(house[i].second - temp[j].second));
        }
        result += tempDist;
    }

    return result;

}

void selectChicken(int idx, int cnt){
    if(cnt==m){
        answer = min(answer, countDistance());
        return;
    }

    for(int i=idx; i<chicken.size(); i++){
        
        if(visited[i] == true){
            continue;
        }
        
        visited[i] = true; //조합에서 선택
        temp.push_back(chicken[i]); //조합에서 뽑힌 치킨집 임시로 넣어두는 벡터
        selectChicken(i, cnt+1); //i부터 선택 시작한 조합 계속
        visited[i] = false; //조합에서 선택했던 것 해제
        temp.pop_back(); //조합에서 뽑힌 치킨집 없애고 다른 치킨집 받을 준비
    }
}

int main(){
    
    cin>>n>>m;

    board.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];

            if(board[i][j]==1){
                house.push_back({i,j});
            }
            else if(board[i][j]==2){
                chicken.push_back({i,j});
            }

        }
    }

    visited.assign(chicken.size(), false);

    selectChicken(0,0);

    cout<<answer;
}

//조합, 재귀