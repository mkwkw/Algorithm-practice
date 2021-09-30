#include <iostream>

using namespace std;

//2차원 배열로 해볼까? - 메모리 초과 - 주어진 크기는 512MB인데 이차원 배열 돌리는 것만 1TB가 사용될 것으로 보임.
//union-find 방식으로 두 점이 같은 집합에 들어가는지 아닌지 판단하는 방식을 사용하기로 결정하였음.
//두 점의 부모노드가 같은지 다른지를 이용해서 같은 집합인지 아닌지 판단.

int unionFind(int parent[], int p){ //부모노드 찾는 함수
    if(parent[p]==p) //부모 노드가 자기 자신 = 부모노드가 연결된 것이 없음
        return p;
    return parent[p]=unionFind(parent, parent[p]); //부모 노드가 있으면 연결된 부모노드 찾아서 리턴
}

void makeUnion(int parent[], int p1, int p2){ //p1과 p2의 집합이 다른 경우
    int pp1 = unionFind(parent, p1); //p1의 부모노드
    int pp2 = unionFind(parent, p2); //p2의 부모노드

    //두 집합을 합친다. 더 작은 노드를 부모노드로 설정한다.
    if(pp1<pp2)
        parent[pp2] = pp1;
    else
        parent[pp1] = pp2;
}

int main() {
    int parent[500000]; //노드의 부모노드 저장할 배열

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        parent[i]=i; //초기화
    }

    for(int i=1; i<=m; i++){ //1단계부터 m단계까지 진행
        int p1, p2; //두 개의 노드 입력받고
        cin>>p1>>p2;
        //각각의 점의 부모 노드를 찾는다.

        if(unionFind(parent, p1)==unionFind(parent, p2)){ //두 점의 부모가 같다.->사이클 형성
            cout<<i;
            return 0; //종료
        }

    //두 점의 부모 노드가 다른 경우, 다른 집합에 속해있다는 뜻이므로
        //두 점의 부모 노드를 같게 만들어서 같은 집합으로 만든다.
        makeUnion(parent, p1, p2);
    }

    //끝까지 다돌았는데도 사이클 형성 안되면(두 점의 부모노드가 같은 경우가 안 나오면) 0출력
    cout<<0;
}
