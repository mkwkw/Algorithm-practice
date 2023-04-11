#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<bool> visited;
    string str;
    int start = 1;
    cin>>str;

    visited.assign(str.length(), false);

    for(int i=0; i<str.length(); i++){
        if(visited[i]){
            continue;
        }

        //N범위
        //str[i]에 해당할 수 있는 숫자를 한 자리씩 비교하며 찾는다. 
        for(int j=start; j<=1000000000; j++){
            string strNum = to_string(j);

            bool flag = false;
            int idx = 0;
            for(int k=0; k<strNum.length(); k++){
                
                if(strNum[k]==str[i+idx]){
                    if(!visited[i+idx]){
                        visited[i+idx] = true;
                        start = j+1;
                        flag = true;
                        idx++;
                    }
                    else{
                        i += 1;
                        visited[i+idx] = true;
                        start = j+1;
                        flag = true;
                        idx++;
                    }
                }
            }
            if(flag){
                break;
            }
        }
    }
    
    cout<<start-1;
}