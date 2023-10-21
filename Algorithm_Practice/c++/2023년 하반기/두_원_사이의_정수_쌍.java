//원의 방정식 - x를 구하면 y는 자동으로 정해짐.
class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        // 4개의 사분면 중 1개만 구한뒤 4를 곱한다.
        for( int i = 1; i <= r2 ; i++){
            double y2 = Math.sqrt(Math.pow(r2,2) - Math.pow(i,2));
            double y1 = Math.sqrt(Math.pow(r1,2) - Math.pow(i,2));
            answer += ( (long)y2 - (long)Math.ceil(y1) + 1); //y1은 올림해야함. 
        }
        answer *= 4;
        
        return answer;
    }
}