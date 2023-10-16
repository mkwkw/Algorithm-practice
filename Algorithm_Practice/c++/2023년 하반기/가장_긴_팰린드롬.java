//Java - charAt(int index), s.length(), Math.max()
class Solution
{
    public int solution(String s)
    {
        int answer = 0;

        if(s.length()==1){
            return 1;
        }
        
        if(s.length()>=2){
            for(int i=0; i<s.length()-1; i++){
                int left = i;
                int right = i+1;
                
                if(s.charAt(left)!=s.charAt(right)){
                    continue;
                }
                
                while(s.charAt(left)==s.charAt(right)){
                    if(left == 0 || right == s.length()-1){
                        break;
                    }
                    --left;
                    ++right;
                }
                
                if(s.charAt(left)==s.charAt(right)){
                    answer = Math.max(answer, right-left+1);
                }
                else{
                    answer = Math.max(answer, right-1-(left+1)+1);
                }
            }
        }
        
        if(s.length()>=3){
            for(int i=1; i<s.length()-1; i++){
                int left = i-1;
                int right = i+1;
                
                if(s.charAt(left)!=s.charAt(right)){
                    continue;
                }
                
                while(s.charAt(left)==s.charAt(right)){
                    if(left == 0 || right == s.length()-1){
                        break;
                    }
                    --left;
                    ++right;
                }
                
                if(s.charAt(left)==s.charAt(right)){
                    answer = Math.max(answer, right-left+1);
                }
                else{
                    answer = Math.max(answer, right-1-(left+1)+1);
                }
            }
        }

        if(answer==0){
            answer = 1;
        }
        
        return answer;
    }
}