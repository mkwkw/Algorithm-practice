#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<bool> visited;
    int n, k, answer = 0;
    string hp;

    cin>>n>>k>>hp;

    visited.assign(n, false);

    for(int i=0; i<hp.length(); i++){
        if(hp[i]=='P'){
            for(int j=i-k; j<=i+k; j++){
                if(j>=0 && hp[j]=='H' && !visited[j]){ //j>=0 조건 주의!
                    answer++;
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    cout<<answer;
}