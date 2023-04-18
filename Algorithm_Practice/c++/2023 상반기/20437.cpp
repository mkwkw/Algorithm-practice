#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<vector<int>> alphabet; //알파벳별 출현 빈도
    int t, k;
    string w;

    cin>>t;

    for(int i=0; i<t; i++){
        int shortest = 10001, longest = 0;
        alphabet.assign(26, vector<int>());
        
        cin>>w>>k;

        for(int j=0; j<w.length(); j++){
            alphabet[w[j]-'a'].push_back(j);
        }

        bool flag = false;
        for(int j=0; j<26; j++){
            //cout<<"alphabet: "<<j<<" size: "<<alphabet[j].size()<<'\n';
            if(alphabet[j].size()>=k){
                flag  = true;

                int start, end;
                for(int h=0; h<=alphabet[j].size()-k; h++){
                    
                    start = alphabet[j][h]; //해당 알파벳 맨 앞 위치
                    end = alphabet[j][h+k-1]; //해당 알파벳 k번째 위치
                    //cout<<"alphabet: "<<j<<' '<<start<<' '<<end<<'\n';
                    longest = max(longest, end-start+1);
                    shortest = min(shortest, end-start+1);
                }
                
            }
        }

        if(!flag){
            cout<<"-1\n";
        }
        else{
            cout<<shortest<<' '<<longest<<'\n';
        }
    }
}