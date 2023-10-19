import java.util.*;

//이분탐색
class Solution {
    public int solution(int n, int k, int[] enemy) {
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
    
        //이분 탐색
        int left = 0, right = enemy.length-1, mid = enemy.length-1;

        while(left<=right){
            mid = (left+right)/2;

            Integer temp[] = new Integer[mid+1];
            for(int i=0; i<mid+1; i++){
                temp[i] = (Integer) enemy[i];
            }
            Arrays.sort(temp, Collections.reverseOrder());

            //제일 큰 값 k개 빼고 난 후, 합 구하기 -> 합이 n보다 같거나 작으면 left = mid+1, 크면 right = mid-1 해서 이분탐색
            //합이 int 범위를 넘을수도 있으므로 long으로 설정해서 합 구하기
            long enemySum = 0;
            for(int i=k; i<mid+1; i++){
                enemySum += (long)temp[i];
            }
            
            if(enemySum<=(long)n){
                answer = Math.max(answer, mid+1);
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
        return answer;
    }
}