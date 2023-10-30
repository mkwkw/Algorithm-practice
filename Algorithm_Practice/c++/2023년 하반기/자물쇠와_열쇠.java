class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = true;
        
        //1. 4번 90도 회전
        for(int i=0; i<4; i++){
            
            //2. 열쇠를 자물쇠에 맞춰보기
            for(int j=0; j<lock.length; j++){
                for(int k=0; k<lock.length; k++){
                    answer = true;
                    for(int a=0; a<key.length; a++){
                        int nextR = j+a;
                        if(nextR>=lock.length){
                            break;
                        }
                        for(int b=0; b<key.length; b++){
                            int nextC = k+b;
                            if(nextC>=lock.length){
                                break;
                            }
                            
                            if(key[a][b]==1 && lock[nextR][nextC]==1 || key[a][b]==0 && lock[nextR][nextC]==0){
                                continue;
                            }
                            else{
                                answer = false;
                                break;
                            }
                        }
                        
                        if(!answer){
                            break;
                        }
                    }
                    
                    if(answer){
                        return true;
                    }
                }
                
            }
            
            
            //키 90도 회전
            int[][] key1 = new int[key.length][key.length];
            for(int j=0; j<key.length; j++){
                for(int k=0; k<key.length; k++){
                    key1[k][key.length-1-j] = key[j][k];
                }
            }
            
            key = key1;
        }
        
        return answer;
    }
}