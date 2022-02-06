#include <iostream>
#include <vector>

using namespace std;

vector<int> num; //��ŷ�� �� �ִ� ��ǻ�� �� ����
vector<bool> visited; //�湮 ���� ���� -> ����Ŭ�� ��� �̿��
int hack = 0; //��ŷ�� �� �ִ� ��ǻ�� ��

//�� ��ǻ�Ϳ��� ��ŷ�� �� �ִ� ��ǻ�� �� ���ϱ� 
void find_computer(vector<vector<int>> &v, int n, int i){ 
    
    visited[i] = true;

    for(int k=0; k<v[i].size(); k++){ 
        if(!visited[v[i][k]]){
            visited[v[i][k]]=true;
            find_computer(v, n, v[i][k]); //i�� ��ŷ�� �� �ִ� k���� ����
            hack++;
        }
    }  
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int max_num = -1;

    cin>>n>>m;

    vector<vector<int>> v(n+1);
    num.assign(n+1,0);
    visited.assign(n+1, false);

    //���� ����Ʈ�� ����
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        v[b].push_back(a);
    }

    for(int i=1; i<n+1; i++){
        find_computer(v, n, i);
        fill(visited.begin(), visited.end(), false); 
        num[i]=hack;
        hack=0;

        if(max_num<num[i]){
            max_num = num[i];
        }
    }
    
    for(int i=1; i<n+1; i++){
        if(num[i]== max_num){
            cout<<i<<' ';
        }
    }
}

//A�� ��ŷ�� �� �ִ� ��ǻ�� B��, B�� ��ŷ�� �� �ִ� ��ǻ�� C��
//�̷��� ����ǹǷ� dfs�� �ذ��Ѵ�, ��͸� �̿��Ѵ�.
//����Ŭ�� �� ���ѷ����� �����ϱ� ���� �湮�迭�� �̿��Ѵ�.
//num[idx]�� ���� ���������� �� ������ �߻��Ͽ�, ������ hack�� �����Ͽ����� �ذ�Ǿ���.