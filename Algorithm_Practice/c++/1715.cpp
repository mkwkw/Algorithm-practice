#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<>> pq;
    int n, num;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>num;
        pq.push(num);
    }
    int n1,n2,n3=0,n4=0;
    //작은 것부터 순서대로 더한다
    //ex. pq: 30 40 50 100
    //n1: 30
    //n2: 40
    //n3: 30+40=70
    //n4: 70
    //pq: 50 70 100
    //n1: 50
    //n2: 70
    //n3: 50+70=120
    //n4: 70+120=190
    //pq: 100 120
    //n1: 100
    //n2: 120
    //n3: 100+120=220
    //n4: 190+220=410
    //답: 410

    while(!pq.empty()){
        if(pq.size()==1){
            break;
        }
       
        n1 = pq.top();
        //cout<<"n1: "<<n1<<'\n';
        pq.pop();
        
        n2 = pq.top();
        //cout<<"n2: "<<n2<<'\n';
        pq.pop();
        n3 = n1+n2;
        //cout<<"n3: "<<n3<<'\n';
        pq.push(n3);
        n4 += n3;
       
    }

    cout<<n4;

}