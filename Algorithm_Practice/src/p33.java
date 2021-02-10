//16953
//A->B
import java.io.*;
public class p33 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String brr[] = br.readLine().split(" ");
		int a = Integer.parseInt(brr[0]);
		long b = Integer.parseInt(brr[1]);
		int count = 0;
		

		
		while(true) {
			
			if(b%2==0) {
				b=b/2;
				count++;
			}
			else if(b%10==1){
				b=(b-1)/10;
				count++;
			}
			else {
				break;
			}
			
			if(b==a)
				break;
			else if(b<a)
				break;
			
		}
		if(b==a)
			System.out.println(count+1);
		else
			System.out.println(-1);
	}

}
