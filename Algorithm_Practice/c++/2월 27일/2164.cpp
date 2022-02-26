#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n;
    cin>>n;

    //1부터 n까지 큐에 넣기
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    while(q.size()!=1){
        q.pop();
        int second = q.front();
        q.pop();
        q.push(second);
    }

    cout<<q.front();
}