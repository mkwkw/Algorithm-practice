#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, a;
    priority_queue<int> pq;

    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a;

        if(a==0){ //선물 가치 출력 - 선물 없으면 -1 출력
            if(!pq.empty()){
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else{
                cout<<"-1"<<'\n';
            }
        }
        else{ // a개의 선물 충전
            for(int j=0; j<a; j++){
                int gift;
                cin>>gift;
                pq.push(gift);
            }
        }
    }
}