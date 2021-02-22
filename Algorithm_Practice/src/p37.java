//14490
//¹é´ë¿­
import java.io.*;
public class p37 {
	
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String brr[] = br.readLine().split(":");
		
		int a = Integer.parseInt(brr[0]);
		int b = Integer.parseInt(brr[1]);
		int num = 1;
		
		if(a<=b) {
			for(int i=1; i<=a; i++) {
				if(a%i==0 && b%i==0 && num<i) {
					num = i;
				}
				else
					continue;
			}	
		}
		else {
			for(int i=1; i<=b; i++) {
				if(b%i==0 && a%i==0 && num<i) {
					num = i;
				}
				else
					continue;
			}	
		}
		
		a = a/num;
		b = b/num;
		
		System.out.println(a+":"+b);
	}

}
