#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

vector<vector<vector<int>>> tomatoes;

struct position{
    int x; //����
    int y; //����
    int z; //����
    int date; //����
};

bool verify(int x, int y, int z, int m, int n, int h){
    if(x>=m || x<0){
        return false;
    }
    else if(y>=n || y<0){
        return false;
    }
    else if(z>=h || z<0){
        return false;
    }
    else if(tomatoes[z][y][x]==-1 || tomatoes[z][y][x]==1){
        return false;
    }
    
    return true;
}

int main(){
    int m,n,h, cnt=0, answer=0;
    
    cin>>m>>n>>h;

    tomatoes.assign(h, vector<vector<int>>(n, vector<int>(m,0))); //[����][����][����]
    queue<position> ripe;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){

                cin>>tomatoes[i][j][k];

                if(tomatoes[i][j][k]==0){
                    cnt++;
                }
                else if(tomatoes[i][j][k]==1){
                    ripe.push(position{k,j,i,0});
                }
            }
        }
    }

    if(cnt==0){
        cout<<"0";
        return 0;
    }
    
    position pos;
    while(!ripe.empty()){
        
        pos = ripe.front();
        int date = pos.date+1;

        //ť�� �� �տ� �ִ� ���� �丶�� ���� 6���� Ž�� & ���ؿ� ���յǸ� ť�� ���� �丶�� �ֱ�
        for(int i=0; i<6; i++){
            int x,y,z;
            x = pos.x+dx[i];
            y = pos.y+dy[i];
            z = pos.z+dz[i];

            if(verify(x, y, z, m, n, h)){
                tomatoes[z][y][x]=1;
                position newPos = {x, y, z, date};
                ripe.push(newPos);
            }
        }

        //���� �丶�� pop
        ripe.pop();
    }

    answer = pos.date;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(tomatoes[i][j][k]==0){
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }

    cout<<answer<<'\n';
    
}

//3���� �迭: [����][����(��)][����(��)] ([h][n][m])
//ť �̿� - BFS
/**
 * 3���� �迭�� ����ü�� ť(���� ��¥���� �ʹ� �丶�� ���� ��) �̿�
 * 1. �� ���� �丶�䰡 �ִ°� üũ - ������ 0 ���
 * 2. ���� �丶��(1)�� ��ǥ�� (ť�� ����) ��¥ �ֱ�
 * 3. ���� �丶���� ��ǥ ���� 6�������� �̵��� �� �ִ��� ���� �� 0���� üũ & 3���� ���Ϳ��� 1�� �ٲٱ� & �̵� ������ position���� date+1�� ������ �ٲ㼭 �ֱ�
 * 4. ť�� �� ������ �ݺ�
 * 5. ť�� ����µ� 3���� ���Ϳ� 0�� �丶�䰡 ���Ҵٸ� -1 ���, ���ٸ� ������ �丶���� date ���
*/