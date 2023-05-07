#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> words;
    map<string, queue<pair<string,int>>> prefixMap;
    int n, longestPrefix = 0, sIdx = 20000;
    string s, t;

    cin>>n;

    words.assign(n, " ");
    
    for(int i=0; i<n; i++){
        cin>>words[i];
        string prefix = "";
        for(int j=0; j<words[i].length(); j++){
            prefix += words[i][j];

            if(prefixMap.find(prefix)==prefixMap.end()){
                prefixMap[prefix] = queue<pair<string, int>>();
            }
            prefixMap[prefix].push({words[i], i});
        }
    }

    for(auto pre : prefixMap){
        //cout<<pre.first<<' '<<pre.second.size()<<'\n';
        if(pre.first.length()>=longestPrefix && pre.second.size()>=2){
            //bcaf, bcdf, abcd, abdh �̷��� �Է��� �־����� ���, bcaf�� bcdf�� ���� ���;���. 
            //map�� �ڵ� �����ϴ� Ư���� �ֱ� ������ for�� ��ȸ ��, ������ �ٲ� �� �����Ƿ� üũ���־����!
            if(prefixMap[pre.first].front().second<sIdx){ 
                longestPrefix = pre.first.length();
                s = prefixMap[pre.first].front().first;
                prefixMap[pre.first].pop();
                t = prefixMap[pre.first].front().first;
            }
        }
    } 

    if(longestPrefix>0){
        cout<<s<<'\n'<<t;
    }
    else{
        cout<<words[0]<<'\n'<<words[1];
    }
}