#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, a;
    priority_queue<int> pq;

    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a;

        if(a==0){ //���� ��ġ ��� - ���� ������ -1 ���
            if(!pq.empty()){
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else{
                cout<<"-1"<<'\n';
            }
        }
        else{ // a���� ���� ����
            for(int j=0; j<a; j++){
                int gift;
                cin>>gift;
                pq.push(gift);
            }
        }
    }
}