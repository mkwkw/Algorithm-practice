#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, firstSize, secondSize, negativeSum=0, positiveSum=0, maxSum=0;
    vector<int> negativeAndZero;
    vector<int> positive;

    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(num<=0){
            negativeAndZero.push_back(num);
        }
        else{
            positive.push_back(num);
        }
    }

    sort(negativeAndZero.begin(), negativeAndZero.end());
    sort(positive.begin(), positive.end(), greater<>());

    firstSize = negativeAndZero.size();
    secondSize = positive.size();
   
    for(int i=0; i+1<firstSize && firstSize>1; i+=2){
        if(negativeAndZero[i]*negativeAndZero[i+1]>negativeAndZero[i]+negativeAndZero[i+1]){
            negativeSum += negativeAndZero[i]*negativeAndZero[i+1];
        }
        else{
            negativeSum += negativeAndZero[i]+negativeAndZero[i+1];
        }
    }

    for(int i=0; i+1<secondSize && secondSize>1; i+=2){
        if(positive[i]*positive[i+1]>positive[i]+positive[i+1]){
            positiveSum += positive[i]*positive[i+1];
        }
        else{
            positiveSum += positive[i]+positive[i+1];
        }
    }
    

    if(firstSize%2!=0){
        negativeSum += negativeAndZero[firstSize-1];
    }

    if(secondSize%2!=0){
        positiveSum += positive[secondSize-1];
    }

    maxSum = negativeSum + positiveSum;

    cout<<maxSum;
}

//0������ ���ڰ� �� �迭�� 1�̻��� ���ڰ� �� �迭�� ���� �д�.
//0������ ���ڰ� �� �迭�� ������������ �����ϰ�
//1�̻��� ���ڰ� �� �迭�� ������������ �����Ѵ�.
//�ε��� 0���� 2���� ���´�. for�� i�� 2�� ������Ű�µ� ���ǿ� i+1<�ش� �迭�� ũ�⸦ �ξ�� �ùٸ��� ����� �ȴ�.
