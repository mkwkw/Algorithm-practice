import java.util.*;
import java.io.*;

public class p1874{

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        List<Character> ch = new ArrayList<>();
        List<Integer> num = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        boolean flag = true;

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            num.add(Integer.parseInt(st.nextToken()));
        }

        int stNum = 1;
        for(int i=0; i<n; i++){
            while(stNum<=num.get(i)){
                stack.push(stNum++);
                ch.add('+');
            }

            if(stack.peek()==num.get(i)){
                stack.pop();
                ch.add('-');                
            }
            else{
                System.out.print("NO");
                return;
            }       
        }

        for(int i=0; i<ch.size(); i++){
            System.out.println(ch.get(i));
        }
    }
}