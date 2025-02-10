#include <iostream>
#include <vector>

using namespace std;

//주사위의 다음 위치
pair<int,int> nextPos(int d, int x, int y)
{
    int nextX = x;
    int nextY = y;

    switch(d)
    {
        case 1:
            nextY += 1;
            break;
        case 2:
            nextY -= 1;
            break;
        case 3:
            nextX -= 1;
            break;
        case 4:
            nextX += 1;
            break;
    }

    return {nextX, nextY};
}

vector<int> rollDice(vector<int> &dice, int d, int x, int y)
{
    vector<int> newDice(6,0);
    //주사위 움직이기 - 주사위 상하동서남북 방향 바뀜
    switch(d)
    {
        case 1:
            newDice[0] = dice[2];
            newDice[1] = dice[4];
            newDice[2] = dice[1];
            newDice[3] = dice[3];
            newDice[4] = dice[0];
            newDice[5] = dice[5];
            break;
        case 2:
            newDice[0] = dice[4];
            newDice[1] = dice[2];
            newDice[2] = dice[0];
            newDice[3] = dice[3];
            newDice[4] = dice[1];
            newDice[5] = dice[5];
            break;
        case 3:
            newDice[0] = dice[3];
            newDice[1] = dice[5];
            newDice[2] = dice[2];
            newDice[3] = dice[1];
            newDice[4] = dice[4];
            newDice[5] = dice[0];
            break;
        case 4:
            newDice[0] = dice[5];
            newDice[1] = dice[3];
            newDice[2] = dice[2];
            newDice[3] = dice[0];
            newDice[4] = dice[4];
            newDice[5] = dice[1];
            break;
    }

    return newDice;
}

int main()
{
    int n, m, x, y, k;
    cin>>n>>m>>x>>y>>k;

    vector<vector<int>> board(n, vector<int>(m,0));
    vector<int> dir(k,0);
    vector<int> dice(6,0); //상,하, 서, 남, 동, 북

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
        }
    }

    for(int i=0; i<k; i++)
    {
        cin>>dir[i];
        pair<int,int> p = nextPos(dir[i], x, y);

        //cout<<"nextX: "<<p.first<<" nextY: "<<p.second<<'\n';

        if(p.first>=n || p.second>=m || p.first<0 || p.second<0)
        {
            continue;
        }

        //주사위를 굴린 위치가 유효한 경우
        x = p.first;
        y = p.second;

        dice = rollDice(dice, dir[i], x, y);
/*
        for(int k=0; k<6; k++)
        {
            cout<<dice[k]<<' ';
        }
        cout<<'\n';
*/
        if(board[x][y]==0)
        {
            board[x][y] = dice[1];
        }
        else
        {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }
/*
        for(int k=0; k<6; k++)
        {
            cout<<dice[k]<<' ';
        }
        cout<<'\n';
*/
        cout<<dice[0]<<'\n';
    }

}