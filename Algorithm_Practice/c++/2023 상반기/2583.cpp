#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tempSize = 0;
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};
vector<int> squareSize;
vector<vector<bool>> board, check;

bool verify(int r, int c, int m, int n){
    if(r<0 || r>=m || c<0 || c>=n){
        return false;
    }
    return true;
}

void findDistrict(int r, int c, int m, int n){
    if(!board[r][c] || check[r][c]){ //직사각형이 있는 자리이거나 이미 방문된 곳이면 패스
        return;
    }

    tempSize++;
    check[r][c] = true;

    for(int i=0; i<4; i++){
        if(verify(r+dr[i], c+dc[i], m, n) && board[r+dr[i]][c+dc[i]] && !check[r+dr[i]][c+dc[i]]){
            findDistrict(r+dr[i], c+dc[i], m, n);
        }
    }
}

int main(){
    int m, n, k;

    cin>>m>>n>>k;
    board.assign(m, vector<bool>(n,true));
    check.assign(m, vector<bool>(n,false));

    int leftDownC = 0, leftDownR = 0, rightUpC = 0, rightUpR = 0;
    for(int i=0; i<k; i++){
        cin>>leftDownC>>leftDownR>>rightUpC>>rightUpR;

        for(int k=leftDownR; k<=rightUpR-1; k++){
            for(int h=leftDownC; h<=rightUpC-1; h++){
                board[k][h]=false;
            }
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<board[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            tempSize = 0;
            findDistrict(i, j, m, n);
            if(tempSize>0){
                squareSize.push_back(tempSize);
            }
        }
    }
    
    sort(squareSize.begin(), squareSize.end());

    cout<<squareSize.size()<<"\n";
    for(int i=0; i<squareSize.size(); i++){
        cout<<squareSize[i]<<' ';
    }



}