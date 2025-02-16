#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
queue<pair<int,int>> cheese, temp; //치즈 위치

bool verify(int n, int m, int r, int c)
{
    if(r<0 || r>=n || c<0 || c>=m)
    {
        return false;
    }
    return true;
}

vector<vector<int>> makeNewOutside(int n, int m, vector<vector<int>> board) //외부 공간으로 전환
{
    while(!temp.empty())
    {
        int r = temp.front().first;
        int c = temp.front().second;
        
        board[r][c] = -1;

        for(int j=0; j<4; j++)
        {
            if(verify(n, m, r+dr[j], c+dc[j]) && board[r+dr[j]][c+dc[j]]==0)
            {
                board[r+dr[j]][c+dc[j]] = -1;
                temp.push({r+dr[j], c+dc[j]});
            }
        }

        temp.pop();
    }

    return board;
}

int main()
{
    int n, m;
    int ans = 0;

    cin>>n>>m;

    vector<vector<int>> board(n, vector<int>(m,0)); 

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
            
            if(board[i][j]==1)
            {
                cheese.push({i,j});
            }
        }
    }

    //치즈 내부 공간, 외부 공간 구분
    //내부: 0 , 외부: -1
    board[0][0] = -1;
    board[n-1][m-1] = -1;
    board[n-1][0] = -1;
    board[0][m-1] = -1;
    temp.push({0,0});
    temp.push({n-1,m-1});
    temp.push({0,m-1});
    temp.push({n-1,0});

    board = makeNewOutside(n, m, board);

    while(!cheese.empty())
    {
        int cheeseCnt = cheese.size();
        for(int i=0; i<cheeseCnt; i++)
        {
            int cnt = 0; //해당 위치의 외부와 맞닿아 있는 면의 수
            for(int j=0; j<4; j++)
            {
                int nextR = cheese.front().first+dr[j];
                int nextC = cheese.front().second+dc[j];
                if(verify(n, m, nextR, nextC) && board[nextR][nextC] == -1)
                {
                    cnt += 1;
                }
            }

            if(cnt>=2) //이제 녹을 치즈
            {
                temp.push(cheese.front());
            }
            else
            {
                cheese.push(cheese.front());
            }
            cheese.pop();
        }

        board = makeNewOutside(n, m, board);

        ans += 1;
    }

    cout<<ans;
}