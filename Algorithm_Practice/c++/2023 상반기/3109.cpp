#include <iostream>
#include <vector>

using namespace std;

int dr[3]={-1, 0, 1};
//�� ����: ������ ���� ��� ���������� �̵��ϹǷ� ���� �迭 �������� �ʰ� +1�� ����

vector<string> board;
vector<vector<bool>> visited;
int cnt = 0;
bool flag; //������ ���� �����ߴ��� ���θ� ���������� �����Ͽ� ��ü������ �����Ѵ�. ������ ���� �����ϸ� �ڿ� ��� ��� �ǳʶٰ� ���� �� ù��° ���� ������ ��

bool verify(int x, int y, int r, int c){
    if(x<0 || x>=r || y<0 || y>=c){
        return false;
    }
    return true;
}

void countRoad(int x, int y, int r, int c){

    visited[x][y] = true;
    
    if(y==c-1){
        cnt++;
        flag = true; //������ ���� �����ߴ� ǥ��
        return;
    }
    
    for(int i=0; i<3; i++){

        int nextX = x+dr[i];
        int nextY = y+1;

        if(verify(nextX, nextY, r, c) && !visited[nextX][nextY]){            
            countRoad(nextX, nextY, r, c);
            if(flag){
                return;
            }
        }
        
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c;
    cin>>r>>c;

    visited.assign(r, vector<bool>(c, false));

    for(int i=0; i<r; i++){
        string road;
        cin>>road;
        board.push_back(road);        
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j]=='x'){
                visited[i][j]=true;
            }
        }
    }

    for(int i=0; i<r; i++){
        if(board[i][0]!='x'){
            flag = false; //������ ���� �����ϸ� true�� �ٲ��
            countRoad(i,0,r,c);
        }
    }

    cout<<cnt;

}