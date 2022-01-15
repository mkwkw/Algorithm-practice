#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<>> pq;
    int n, t, s, l, c;

    cin>>n>>t;

    for(int i=0; i<n; i++){
        cin>>s>>l>>c;

        pq.push(s);
        for(int j=0; j<c-1; j++){
            int sl = s+l;
            pq.push(sl);
            s = sl;
        }

    }

    while(pq.top()<t && !pq.empty()){ //!pq.empty() 조건 필수
        pq.pop();
    }

    if(pq.empty()){
        cout<<"-1";
        return 0;
    }

    int answer = pq.top()-t;
    cout<<answer;
    
}

//범위: 10^6+10^4*10^2가 최대이므로 int로 해도 됨.
//전체 버스 중에서 영식이가 버스를 타기 위한 최소 시간을 구하는 것이므로 각 버스 시간을 합쳐서
//전체 버스 시간표를 만들고 정렬해야한다. -> 우선순위 큐 구현
//1. pq.top()<t 이면 pq.pop() 반복
//2. t<=pq.top() 이면 pq.top()-t가 답이 된다.