#include<iostream>
#include<vector>

using namespace std;

//재귀 - 모든 색에서 하나씩 골라야함.
//시간초과 방지하기 위해 (너비<answer)인 경우에만 재귀 진행
int n, k, answer = 5000001;
void recur(int c, vector<vector<pair<int,int>>> pos, int maxX, int minX, int maxY, int minY){
  
  if(c==k){
    answer = min(answer, (maxX-minX)*(maxY-minY));
    return;
  }
  for(int i=0; i<pos[c].size(); i++){
    int x = pos[c][i].first;
    int y = pos[c][i].second;
    int maxX1 = max(maxX, x);
    int minX1 = min(minX, x);
    int maxY1 = max(maxY, y);
    int minY1 = min(minY, y);

    //시간 초과 방지
    if((maxX1-minX1)*(maxY1-minY1)<answer)
      recur(c+1, pos, maxX1, minX1, maxY1, minY1);
  }
}
int main(int argc, char** argv)
{
  //색깔: {{좌표1}, ... , {좌표2}}
  //각 색깔 좌표 다 돌면서 min(x), max(x), min(y), max(y) 구하기
  
  cin>>n>>k;
  
  vector<vector<pair<int,int>>> pos(k);

  for(int i=0; i<n; i++){
    int x, y, c;
    cin>>x>>y>>c;
    pos[c-1].push_back({x,y});
  }

  recur(0, pos, -1000, 1000, -1000, 1000);

  cout<<answer;
  return 0;
}