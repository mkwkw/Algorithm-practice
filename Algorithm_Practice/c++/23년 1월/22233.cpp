#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    set<string> keywordSet;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        string keyword;
        cin>>keyword;
        keywordSet.insert(keyword);
    }

    for(int i=0; i<m; i++){
        string words;
        cin>>words;

        stringstream ss(words);
        string temp;

        while(getline(ss, temp, ',')){
            if(keywordSet.find(temp)!=keywordSet.end()){
                keywordSet.erase(temp);
            }
        }

        cout<<keywordSet.size()<<'\n';
        
    }
}

//중복없이 저장, find()이용 삭제, size()출력