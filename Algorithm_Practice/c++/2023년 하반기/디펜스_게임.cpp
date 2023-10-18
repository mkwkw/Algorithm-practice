#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

//최소 힙 (O(nlogn))
//주의! 끝까지 탐색했는데 enemySum<=n인 경우
//(+ 이분 탐색 (O(nlogn) => mid로 적당한 범위 찾기 - 0~mid(찾고자하는 범위)만큼 끊어서 내림차순 정렬 후, 상위 k개 제외한 적들의 합 구하기 -> n보다 적거나 같으면 start = mid+1, n보다 크면 end = mid-1)
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
        
    //무적권의 개수>=라운드 수 -> 모든 라운드 통과
    if(k>=enemy.size()){
        return enemy.size();
    }
    
    //n의 수 >= enemy 총합 -> 모든 라운드 통과
    long long totalEnemy = 0;
    for(int i=0; i<enemy.size(); i++){
        totalEnemy += (long long)enemy[i];
    }
    if((long long)n >= totalEnemy){
        return enemy.size();
    }
    
    //무적권의 개수<라운드 수
    //최댓값인 라운드 k개를 보관하기 위해 최소 힙 사용 - 오름차순 우선순위 큐!
    //pq에는 k개만 있도록!
    priority_queue<int, vector<int>, greater<>> pq;
    int enemySum = 0;
    for(int i=0; i<enemy.size(); i++){
        
        if(pq.size()<k){
            pq.push(enemy[i]);
        }
        else{
            pq.push(enemy[i]);
            enemySum += pq.top();
            pq.pop();
            if(enemySum>n){
                answer = i;
                break;
            }
        }
    }
    
    //끝까지 탐색했는데 enemySum<=n인 경우
    if(answer==0){
        answer = enemy.size();
    }
    
    return answer;
}