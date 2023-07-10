#include <iostream>

using namespace std;

int main(){
    int n, totalSum=0, maxNum=0;
    double answer;

    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        totalSum += num;
        maxNum = max(maxNum, num);
    }

    answer = ((double)totalSum/(double)maxNum*100)/(double)n;
    cout<<answer;
}