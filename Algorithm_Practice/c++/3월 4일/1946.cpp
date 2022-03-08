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
        //���� �ִ� ����� ���� ���� �� ���� ���� �������� ���� ����� ���� ������ ������ ����
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