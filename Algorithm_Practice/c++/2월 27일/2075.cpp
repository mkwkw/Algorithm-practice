#include <iostream>
#include <queue>

using namespace std;

int main(){

    //없으면 시간초과 발생
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<>> pq; //오름차순 정렬 - pop했을 때 가장 작은 것 나가도록
    int n, answer;
    cin>>n;

    for(int i=0; i<n*n; i++){
        int num;
        cin>>num;
        pq.push(num);

        if(pq.size()>n){
            pq.pop();
        }
    }

    answer = pq.top();

    cout<<answer;

}

//시간초과 주의!
//메모리 제한이 매우 작으므로 pq에 n개의 수만 들어가도록 한다.(pop을 반복한다)
//pq를 오름차순 정렬이 되도록 선언하여 pq의 front에 가장 작은 값이 들어가도록 한다.
//따라서 마지막에는 pq의 front에 n번째 큰 수가 위치하게 된다.