#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> v; //단어장
map<string, int> freq; //단어와 단어의 빈도수 - map으로 저장

bool cmp(string a, string b){
    if(a.length()==b.length() && freq[a]==freq[b]){
        return a<b;
    }
    else if(freq[a]==freq[b]){
        return a.length()>b.length();
    }
    return freq[a]>freq[b];
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

        
    string str;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>str;
        if(str.length()<m){ //길이가 m미만이면 v에 넣지 않는다.
            continue;
        }
        
        if(freq.find(str)==freq.end()){ //단어가 map에 저장되어있지 않다면
            freq[str]=0; //map에 넣고
             v.push_back(str); //v에 넣고
        }
        freq[str]++; //빈도 증가
    }

    sort(v.begin(), v.end(), cmp); //기준에 맞춰 정렬

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}