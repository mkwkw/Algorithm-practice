#include <iostream>
#include <vector>

using namespace std;

//구현
int main(){
    int h, w, x, y;
    vector<vector<int>> board, original;

    cin>>h>>w>>x>>y;

    board.assign(h+x, vector<int>(w+y,0));
    original.assign(h, vector<int>(w,0));

    for(int i=0; i<h+x; i++){
        for(int j=0; j<w+y; j++){
            cin>>board[i][j];
        }
    }

    //A에서 B로 옮길 때, 그대로인 것
    for(int i=0; i<x; i++){
        for(int j=0; j<w; j++){
            original[i][j] = board[i][j];
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<y; j++){
            original[i][j] = board[i][j];
        }
    }

    //A에서 B로 옮길 때, 바뀌는 것
    for(int i=x; i<h; i++){
        for(int j=y; j<w; j++){
            original[i][j] = board[i][j] - original[i-x][j-y]; 
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout<<original[i][j]<<' ';
        }
        cout<<'\n';
    }
}