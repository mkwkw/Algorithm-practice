#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    vector<int> tree, treeInterval;
    set<int> interval0Divisor;
    int n, answer = 0, treeEnd = 0;
    int shortestInterval;
    
    cin>>n;

    for(int i=0; i<n; i++){
        int pos;
        cin>>pos;
        tree.push_back(pos);
    }
    
    sort(tree.begin(), tree.end());
    treeEnd = tree[n-1];

    //간격
    for(int i=0; i<n-1; i++){
        int interval = tree[i+1]-tree[i];
        treeInterval.push_back(interval);
    }

    sort(treeInterval.begin(), treeInterval.end());

    //간격의 최대 공약수 구하기 - 나무 사이의 간격이 최대 공약수가 되게 심어야 최소 개수가 됨.
    for(int i=1; i<=sqrt(treeInterval[0]); i++){
        if(treeInterval[0]%i==0){
            interval0Divisor.insert(i);
            interval0Divisor.insert(treeInterval[0]/i);
        }
    }

    int gcd = 1;
    for(auto s : interval0Divisor){
        bool flag = true;
        for(int i=1; i<=treeInterval.size(); i++){
            if(treeInterval[i]%s!=0){
                flag = false;
                break;
            }
        }

        if(flag){
            gcd = s;
        }
    }

    for(int i=0; i<tree.size()-1; i++){
        if(tree[i+1]-tree[i]>gcd){
            answer += (tree[i+1]-tree[i]-1)/gcd;
        }
    }

    cout<<answer;
}