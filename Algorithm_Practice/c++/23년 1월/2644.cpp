#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> parent, aParents, bParents;
    int n, a, b, m, answer;

    cin>>n>>a>>b>>m;

    parent.assign(n+1,0);

    for(int i=1; i<n+1; i++){
        parent[i] = i*(-1);
    }

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;

        parent[y] = x;
    }

    int aParent = parent[a];
    int bParent = parent[b];

    aParents.push_back(aParent);
    bParents.push_back(bParent);

    while(aParent>0){
        aParent = parent[aParent];
        aParents.push_back(aParent);
    }

    while(bParent>0){
        bParent = parent[bParent];
        bParents.push_back(bParent);
    }

    int aCnt=-1, bCnt=-1;
    bool flag = false;
    for(int i=0; i<aParents.size(); i++){
        for(int j=0; j<bParents.size(); j++){
            if(aParents[i]==bParents[j]){
                if(aParents[i]>0){
                    aCnt = i+1;
                    bCnt = j+1;
                }
                else{
                    aCnt = i;
                    bCnt = j;
                }

                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){ //�̼� ���谡 ���� ��
        answer = aCnt+bCnt;
    }
    else{ //�̼� ���谡 ���� ��
        answer = -1;
    }

    cout<<answer;

}

//dfs
//�ڽ� 1�� - �θ� 1�� ��Ī �ǹǷ� parent[�ڽ� �ε���] = �θ� �ε��� �̷� ������ �Է� �ޱ� - �ʱ�ȭ: ���� �ٸ� ������ �ʱ�ȭ(���� ���� �ʱ�ȭ �ϸ� ������ �ö��� ��, ���� �θ�� ��޵�)
//�ڽĿ������� Ÿ��Ÿ�� �ö󰣴�. �迭�� ���� ������ �ɶ����� Ÿ����, �� �������� ���İ��� �θ� �ε����� �����Ѵ�. a�� Ÿ�� �ö󰡸鼭 ��ġ�� �θ�� aParents�� b�� Ÿ�� �ö󰡸鼭 ��ġ�� �θ�� bParents�� �ִ´�.
//aParents�� bParents�� ����� �ε����� �ִ��� �տ������� Ȯ���Ѵ�.(���� ����� ���� �θ� ã�ƾߵ�) ���� �ε����� ������ �̼� ���谡 ���� ���̹Ƿ� -1�� ����Ѵ�.

