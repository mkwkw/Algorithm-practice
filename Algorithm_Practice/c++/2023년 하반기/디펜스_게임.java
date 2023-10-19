import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int answer = 0;
        
        //무조건 모든 라운드 도달하는 경우
        if(k>=enemy.length){
            return enemy.length;
        }
        
        long totalEnemy = 0;
        for(int i=0; i<enemy.length; i++){
            totalEnemy += (long) enemy[i];
        }
        
        if((long)n>=totalEnemy){
            return enemy.length;
        }
        
        //우선순위 큐
        int enemySum = 0;
        for(int i=0; i<enemy.length; i++){
            if(pq.size()<k){
                pq.offer(enemy[i]);
                continue;
            }
            
            pq.offer(enemy[i]);
            enemySum += pq.peek();
            pq.poll();
            
            if(enemySum>n){
                answer = Math.max(answer, i);
                break;
            }
        }
        
        if(answer==0){
            answer = enemy.length;
        }
        
        return answer;
    }
}