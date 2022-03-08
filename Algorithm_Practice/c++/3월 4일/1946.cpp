#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int evaluate(int n){
    vector<pair<int, int>> score;
    int a,b,min_score=100001, result=0;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        score.push_back({a,b});
    }

    sort(score.begin(), score.end());

    for(int i=0; i<n; i++){
        //위에 있는 사람의 면접 순위 중 제일 낮은 순위보다 현재 사람의 면접 순위가 높으면 뽑힘
        if(score[i].second<min_score){
            min_score = score[i].second;
            result++;
        }
    }

    return result;
}

int main(){
    int t,n, answer;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n;
        answer = evaluate(n);
        cout<<answer<<'\n';
    }

}