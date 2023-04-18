#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<vector<int>> alphabet; //���ĺ��� ���� ��
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
                    
                    start = alphabet[j][h]; //�ش� ���ĺ� �� �� ��ġ
                    end = alphabet[j][h+k-1]; //�ش� ���ĺ� k��° ��ġ
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