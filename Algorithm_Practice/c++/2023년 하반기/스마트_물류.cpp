#include<iostream>
#include<vector>
#include<map>

using namespace std;

//가장 멀리 떨어진 부품을 잡아야함.
int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, k;
  string line;
  int answer = 0;
  cin>>n>>k>>line;

  for(int i=0; i<n; i++){
    if(line[i]=='P'){
      for(int j = i-k; j<=i+k; j++){
        if(0<=j && j<n && line[j]=='H'){
          line[j]='-';
          break;
        }
      }    
    }
  }

  for(int i=0; i<n; i++){
    if(line[i]=='-'){
      answer++;
    }
  }
  cout<<answer;
  return 0;
}