#include <iostream>
#include <vector>

using namespace std;

int dr[3]={0,1,1};
int dc[3]={1,1,0};

vector<vector<int>> board; //��ĭ: 0, ��:1
vector<vector<int>> dp; //dp[r][c]: (r,c)���� ���� ����� ��

int answer = 0;

bool verify(int r, int c, int n, int pos, int i){
    if(r<0 || r>=n || c<0 || c>=n || board[r][c]==1){
        return false;
    }

    if(i==1 && (board[r-1][c]==1 || board[r][c-1]==1)){ //�밢������ �̵� ���� - ���� �̵��� r,c ���� ��ĭ ���� �ؾ���
        return false;
    }
    
    //���� ���� ���� ��� ����
    if(pos==0 && i==2){
        return false;
    }
    else if(pos==2 && i==0){
        return false;
    }

    return true;
}

void movePipe(int r, int c, int n, int pos){ //r,c: ���� �������� ������ �� �κ� ��ġ / pos: ���� ������ ���(0: ����, 1: �밢��, 2: ����)

    for(int i=0; i<3; i++){ //���� ������ ���(i=0: ����, i=1: �밢��, i=2: ����)
        int nextR = r+dr[i]; 
        int nextC = c+dc[i];
        //cout<<"r: "<<r<<" c: "<<c<<" nextR: "<<nextR<<' '<<" nextC: "<<nextC<<" pos: "<<pos<<" i: "<<i<<'\n';

        if(verify(nextR, nextC, n, pos, i)){
            dp[nextR][nextC] += 1;
            // for(int j=0; j<n; j++){
            //     for(int k=0; k<n; k++){
            //         cout<<dp[j][k]<<' ';
            //     }
            //     cout<<'\n';
            // }
            movePipe(nextR, nextC, n, i); //��� �̿��Ͽ� ������ �̵�
        }
    }

}

int main(){

    int n;

    cin>>n;

    board.assign(n, vector<int>(n,-1));
    dp.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    movePipe(0,1,n,0);

    //dp[0][0]=0, dp[0][1]=0
    cout<<dp[n-1][n-1];

    
}