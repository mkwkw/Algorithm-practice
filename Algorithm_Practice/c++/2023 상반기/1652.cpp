#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, horizontal=0, vertical=0;
    vector<vector<bool>> board;

    cin>>n;

    board.assign(n, vector<bool>(n,true));

    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<n; j++){
            if(s[j]=='X'){
                board[i][j]=false;
            }
        }
    }

    //가로
    bool flag;
    for(int i=0; i<n; i++){
        flag = false;
        for(int j=0; j<n-1; j++){
            if(!board[i][j]){
                flag = false;
            }
            if(flag){
                continue;
            }
            if(board[i][j] && board[i][j+1]){
                horizontal++;
                flag = true;
            }
        }
    }

    //세로
    
    for(int i=0; i<n; i++){
        flag = false;
        for(int j=0; j<n-1; j++){
            if(!board[j][i]){
                flag = false;
            }
            if(flag){
                continue;
            }
            if(board[j][i] && board[j+1][i]){
                vertical++;
                flag = true;
            }
        }
    }

    cout<<horizontal<<' '<<vertical;
}