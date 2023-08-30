#include <iostream>
#include <deque>
#include <queue>

using namespace std;

//deque
//큐에서만 x 값이 바뀐다.
//4
//0 1 1 0
//1 2 3 4
//3
//2 4 7
//초기 상태: num에는 1,4(큐에 들어있는 값)
//2 들어오면 2,1,4 되었다가 4가 pop
//4 들어오면 4,2,1 되었다가 1이 pop
//7 들어오면 7,4,2 되었다가 2가 pop
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    queue<int> q; //큐에서만 x가 바뀌므로 큐인 큐스택의 인덱스만 저장
    deque<int> num; //어차피 큐스택에 한 개씩 밖에 안들어가있으므로 굳이 2차원 벡터 생성할 필요 없음. - x가 큐에 들어오면 x를 앞에 넣고 뒤에서 원소를 빼야함.
    
    cin>>n;

    for(int i=0; i<n; i++){
        int qors;
        cin>>qors;

        if(qors==0){
            q.push(i); //큐인 인덱스만 저장
        }
    }
    
    for(int i=0; i<n; i++){
        cin>>x;
        
        if(!q.empty() && q.front()==i){
            num.push_back(x);
            q.pop();
        }
    }

    cin>>m;

    for(int i=0; i<m; i++){
        cin>>x;

        num.push_front(x);
        x = num.back();
        num.pop_back();

        cout<<x<<' ';
    }
    
}