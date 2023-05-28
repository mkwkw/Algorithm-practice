#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//범위 조심!!
int countRoad(vector<vector<int>> &board, int n, int l){
    vector<vector<bool>> visited;
    int answer = 0;
    visited.assign(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        vector<int> pos;
        bool flag = true; //유효성
        for(int j=0; j<n-1; j++){
            if(board[i][j]>board[i][j+1]){
                if(board[i][j]-board[i][j+1]>1){
                    flag = false;
                    break;
                }
                pos.push_back(j+1);
            }
            else if(board[i][j]<board[i][j+1]){
                if(board[i][j+1]-board[i][j]>1){
                    flag = false;
                    break;
                }
                pos.push_back(j);
            }
        }

        if(!flag){
            continue;
        }

        for(int j=0; j<pos.size(); j++){
            int p = pos[j];
            //cout<<"r: "<<i<<" c: "<<p<<'\n';
            
            
            //else{
                //왼쪽이 높은 경우
                if(board[i][p-1]>board[i][p]){
                    for(int k=p; k<p+l; k++){
                        if(p+l>n || (p+l<=n && !(board[i][k]==board[i][p] && !visited[i][k]))){
                            flag = false;
                            break;
                        }
                    }

                    if(flag){
                        for(int k=p; k<p+l; k++){
                            visited[i][k]=true;
                        }
                    }

                }
                //오른쪽이 높은 경우
                else if(board[i][p]<board[i][p+1]){
                    for(int k=p; k>p-l; k--){
                        if(p-l<-1 || (p-l>=-1 && !(board[i][k]==board[i][p] && !visited[i][k]))){
                            flag = false;
                            break;
                        }
                    }

                    if(flag){
                        for(int k=p; k>p-l; k--){
                            visited[i][k]=true;
                        }
                    }
                }

                if(!flag){
                    break;
                }
            //}
        }

        if(!flag){
            continue;
        }
        else{
            //cout<<"r: "<<i<<'\n';
            answer++;
        }
    }

    return answer;
}

int main(){
    vector<vector<int>> board, board1;
    int n, l;
    
    cin>>n>>l;

    board.assign(n, vector<int>(n, 0));
    board1.assign(n, vector<int>(n, 0));
    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board1[i][j] = board[j][i];
        }
    }

    int horizontalCnt = countRoad(board, n, l);
    int verticalCnt = countRoad(board1,n,l);

    cout<<horizontalCnt+verticalCnt;
}