#include<iostream>
#include<queue>

using namespace std;

//우선순위 큐
//끝나는 시간 순서대로 정렬
int main(int argc, char** argv)
{
  int answer = 0;
  //끝나는 시간 순서대로 정렬
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  int n, s, f;
  cin>>n;

  for(int i=0; i<n; i++){
    cin>>s>>f;
    pq.push({f,s});
  }

  answer = 1;
  s = pq.top().second;
  f = pq.top().first;
  pq.pop();
  
  while(!pq.empty()){
    if(f<=pq.top().second){
      answer++;
      s = pq.top().second;
      f = pq.top().first;
    }
    pq.pop();
  }

  cout<<answer;
  return 0;
}