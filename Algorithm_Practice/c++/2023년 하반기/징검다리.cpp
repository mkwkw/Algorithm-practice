#include<iostream>
#include<vector>

using namespace std;

//dp - 앞의 돌 정보 이용
//길이, 높이 배열을 따로 두고 height[i]보다 앞에 있고 높이가 낮은 돌인 경우
//length[i] = max(length[i], length[j]+1)로 최대 길이 갱신
//9
//3 2 1 2 3 4 5 4 6 -> 정답: 6
int main(int argc, char** argv)
{
  vector<int> length, height;
  int n, answer = 0;
  cin>>n;

  length.assign(n, 1);
  height.assign(n, 0);
  
  for(int i=0; i<n; i++){
    cin>>height[i];
  }

  for(int i=1; i<n; i++){
    for(int j=i-1; j>=0; j--){
      if(height[i]>height[j]){
        length[i] = max(length[i], length[j]+1);
      }
    }
    answer = max(answer, length[i]);
  }

  cout<<answer;
  return 0;
}