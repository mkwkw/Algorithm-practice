#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

//누적합, 자릿수 표시
int main(int argc, char** argv)
{
  int n, k;
  vector<int> score;

  cin>>n>>k;

  score.assign(n, 0);

  for(int i=0; i<n; i++){
    cin>>score[i];
  }

  //누적합
  for(int i=1; i<n; i++){
    score[i] += score[i-1];
  }

  for(int i=0; i<k; i++){
    int a, b, s;
    cin>>a>>b;

    if(a!=1&&b!=1){
      s = score[b-1]-score[a-2];
    }
    else{
      s = score[b-1];
    }

    cout<<fixed;
    cout.precision(2);
    cout<<(double)round((double)s/(b-a+1)*100)*0.01<<'\n';
  }
  
  return 0;
}