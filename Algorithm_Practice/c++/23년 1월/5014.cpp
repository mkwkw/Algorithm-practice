#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int>path(1000001, 0), dx(2);
vector<bool>visited(1000001, false);
queue<int> q;

//�� ��ġ �������� +u, -d �ϴ� �� ���� ��츦 ��� �������ϰ�, �ּ����� ��� Ƚ���� ���ؾ��ϹǷ�
//�湮 �迭�� ť�� �̿��� BFS�� �̿��Ѵ�.
void BFS(int f, int s, int g, int u, int d){
    visited[s] = true; //���� ��ġ �湮 ǥ��
    q.push(s); //���� ��ġ ť�� ����

    while(!q.empty()){
        s = q.front(); //ť�� �Ǿ� ����: ���� ��ġ
        q.pop();
        for(int i=0; i<2; i++){
            int nextS = s+dx[i]; //+u, -1

            if(0<nextS && nextS<=f){ //���� üũ
                if(!visited[nextS]){ //�湮�߾����� Ȯ��
                    visited[nextS] = true; //�湮 üũ
                    q.push(nextS); //�̹湮�̾��� ���� ť�� �ֱ�
                    path[nextS] = path[s]+1; //��� Ƚ�� +1
                }
            }
        }
    }
}



int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    dx[0]=u;
    dx[1]=d*(-1);

    BFS(f,s,g,u,d);

    if(visited[g]){
        cout<<path[g];
    }
    else{
        cout<<"use the stairs";
    }
}