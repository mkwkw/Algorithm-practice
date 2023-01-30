#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

vector<vector<int>> board;
vector<vector<bool>> visited;

//���� üũ
bool verify(int x, int y, int n){
    if(x>=n || x<0){
        return false;
    }
    else if(y>=n || y<0){
        return false;
    }

    return true;
}

//�����¿� �̵��� �� �ִ� ��ġ�� �̵� ��, �湮�迭�� true�� ǥ�� - ������ ���� ��� true�� ǥ��
void DFS(int x, int y, int n, int level){

    for(int i=0; i<4; i++){
        int nextX = x+dx[i];
        int nextY = y+dy[i];

        if(verify(nextX, nextY, n) && board[nextX][nextY]>level && !visited[nextX][nextY]){
            visited[nextX][nextY] = true;
            DFS(nextX, nextY, n, level);         
        }
    }

}

int main(){
    int n, answer=0;
     
    cin>>n;

    board.assign(n, vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<=100; i++){ //�� ����
        int cnt = 0;
        visited.assign(n, vector<bool>(n, false)); //�湮 �迭 �ʱ�ȭ
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(board[j][k]>i && !visited[j][k]){ //�� ���̺��� ���� �湮���� ���� �� ���� Ž��
                    visited[j][k]=true;

                    DFS(j, k, n, i);

                    cnt++;
                }
            }
        }

        if(answer<=cnt){
            answer = cnt;
        }
        
    }

    cout<<answer;
}