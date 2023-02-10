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
    if(flag){ //촌수 관계가 있을 때
        answer = aCnt+bCnt;
    }
    else{ //촌수 관계가 없을 때
        answer = -1;
    }

    cout<<answer;

}

//dfs
//자식 1명 - 부모 1명 매칭 되므로 parent[자식 인덱스] = 부모 인덱스 이런 식으로 입력 받기 - 초기화: 각각 다른 음수로 초기화(같은 수로 초기화 하면 끝까지 올라갔을 때, 같은 부모로 취급됨)
//자식에서부터 타고타고 올라간다. 배열의 값이 음수가 될때까지 타고가고, 그 과정에서 거쳐가는 부모 인덱스를 저장한다. a를 타고 올라가면서 거치는 부모는 aParents에 b를 타고 올라가면서 거치는 부모는 bParents에 넣는다.
//aParents와 bParents에 공통된 인덱스가 있는지 앞에서부터 확인한다.(가장 가까운 공통 부모를 찾아야됨) 공통 인덱스가 없으면 촌수 관계가 없는 것이므로 -1을 출력한다.

