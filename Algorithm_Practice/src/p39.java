//20302
//민트 초코
//틀렸습니다..?
import java.io.*;
import java.util.*;
public class p39 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String brr[] = br.readLine().split(" ");
		double re = 0;
		Stack<Double> st1 = new Stack<Double>(); //숫자 저장
		Stack<String> st2 = new Stack<String>(); //연산자 저장
		
		for(int i=0; i<brr.length; i++) {
			if(brr[i].equals("*") || brr[i].equals("/")) {
				st2.push(brr[i]);
			}
			else
				st1.push(Double.parseDouble(brr[i]));
			
		}
		
		while(true) {
			if(st1.isEmpty() || st2.isEmpty()) {
				break;
			}
			else {
				double a = st1.pop();
				if(st1.isEmpty()) {
					break;
				}
				
				double b = st1.pop();
				String op = st2.pop();
				if(op.equals("*")) {
					re = b*a;
					st1.push(re);
				}
				else if(op.equals("/")) {
					re = b/a;
					st1.push(re);
				}
					
			}
		}
		if(re%(1.0) != (0.0))
			System.out.println("toothpaste");
		else
			System.out.println("mint chocolate");
		

	}

}
