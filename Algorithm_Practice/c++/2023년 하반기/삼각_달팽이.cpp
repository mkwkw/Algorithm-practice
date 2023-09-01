#include <string>
#include <vector>
#include <iostream>

using namespace std;

//구현
//down->right->up
//각 단계에서의 r과 c의 변화 - 경우의 수 나누기
vector<int> solution(int n) {
    vector<vector<int>> board(n);
    vector<int> answer;
    int num = 1, r = 0, c = 0;
    
    for(int i=0; i<n; i++){
        board[i].assign(i+1,0);
    }
    
    while(num<=n*(n+1)/2){ //마지막 수 = n*(n+1)/2
        //cout<<"r "<<r<<" c "<<c<<" num "<<num<<'\n';
        //down
        for(int i=r; i<n; i++){
            //cout<<"down r "<<i<<" c "<<c<<" num "<<num<<'\n';
            if(board[i][c]==0){
                board[i][c] = num++;
            }
            else if(board[i][c]!=0){
                r = i-1;
                break;
            }
            
            if(i==n-1){
                r = i;
                break;
            }
            
            
        }
        
        //right
        for(int i=c+1; i<board[r].size(); i++){
            //cout<<"right r "<<r<<" c "<<i<<" num "<<num<<'\n';
            if(board[r][i]==0){
                board[r][i] = num++;
            }
            else if(board[r][i]!=0){
                c = i-2;
                break;
            }
            if(i==board[r].size()-1){
                c = i-1;
                break;
            }
        }
        
        //up
        for(int i=r-1; i>=0; i--){
            //cout<<"up r "<<i<<" c "<<c<<" num "<<num<<'\n';
            //cout<<"c "<<board[i].size()-(board[r].size()-c)<<'\n';
            if(board[i][c]==0){
                board[i][c--] = num++;
            }
            else if(board[i][c]!=0){
                //cout<<"i: "<<i<<' '<<c<<'\n';
                c = c+1;
                r = i+2;
                //cout<<"ir "<<r<<" c "<<c<<'\n';
                break;
            }
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<board[i].size(); j++){
    //         cout<<board[i][j]<<' ';
    //         answer.push_back(board[i][j]);    
    //     }
    //     cout<<'\n';
    // }
    
    return answer;
}

int main(){
    solution(5);
}