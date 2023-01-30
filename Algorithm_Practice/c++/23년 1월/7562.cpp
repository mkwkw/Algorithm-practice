#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//����Ʈ�� �� �� �ִ� 8���� ����
int dx[8]={-2,-1,1,2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

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

int main(){
    int t, n, startX, startY, endX, endY, cnt;
    vector<vector<bool>> visited;

    cin>>t;

    for(int i=0; i<t; i++){
        queue<pair<int,pair<int, int>>> knight; //{�̵��� Ƚ��, {x��ǥ, y��ǥ}}
        cin>>n>>startX>>startY>>endX>>endY;

        if(startX==endX && startY==endY){
            cout<<"0\n";
            continue;
        }

        visited.assign(n, vector<bool>(n,false)); //�湮 �迭 �ʱ�ȭ

        knight.push({0,{startX, startY}});
        visited[startX][startY]=true;

        bool flag = false;
        while(!knight.empty()){
        
            //ť���� �ϳ��� ���� 8���� �������� �̵����� �� ��ǥ ���ϰ� ���� üũ ��, ť�� �ֱ�
            for(int j=0; j<8; j++){
                
                int nextX = knight.front().second.first + dx[j];
                int nextY = knight.front().second.second + dy[j];
                cnt = knight.front().first+1;

                if(nextX==endX && nextY==endY){
                    flag = true;
                    break;
                } 
                
                if(verify(nextX, nextY, n) && !visited[nextX][nextY]){
                    //cout<<"x: "<<knight.front().second.first<<" y: "<<knight.front().second.second<<" nextX: "<<nextX<<" nextY: "<<nextY<<" cnt: "<<cnt<<'\n';
                    visited[nextX][nextY]=true;
                    knight.push({cnt,{nextX, nextY}});
                }

            }

            knight.pop();

            if(flag){
                break;
            }

        }

        cout<<cnt<<'\n';

    }
}