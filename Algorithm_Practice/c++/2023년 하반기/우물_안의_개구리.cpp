#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

//map - 친분 관계가 있다면 양방향 관계 이용 -> n번: n번과 친분있는 회원들
//n번의 value에 원소가 하나도 없다면 친분 관계가 존재하지 않는 것
int main(int argc, char** argv)
{
  int n, m, a, b, answer=0;
  vector<int> w;
  map<int,set<int>> relation;
  
  cin>>n>>m;

  w.assign(n,0);
  for(int i=0; i<n; i++){
    cin>>w[i];
    relation[i+1] = {};
  }

  for(int i=0; i<m; i++){
    cin>>a>>b;
    relation[a].insert(b);
    relation[b].insert(a);
  }

  for(auto m : relation){
    if(m.second.size()==0){
      answer++;
      continue;
    }

    bool flag = true;
    for(auto s : m.second){
      if(w[m.first-1]<=w[s-1]){
        flag = false;
        break;
      }
    }
    if(flag){
      answer++;
    }
  }

  cout<<answer;
  return 0;
}