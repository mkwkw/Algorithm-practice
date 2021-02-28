import java.io.*;
public class p47 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String brr[] = br.readLine().split(" ");
		int N = Integer.parseInt(brr[0]);
		long K = Integer.parseInt(brr[1]);
		long result = 0;
		StringBuilder st = new StringBuilder();
		
		//첫번째 식
		for(int n=1; n<=N%K; n++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					//result += gcd(i,j)*lcm(i,j);
					result += i*j;
				}
			}
			
		}
		result = result%K;
		st.append(result+"\n");
		//System.out.println(result);
		
		result=0;
		long result1=0;
		long result2=0;
		
		for(int n=1; n<=N%K; n++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					result1 += gcd(i,j);
					result2 += lcm(i,j);
				}
			}
		}
		
		result = (result1*result2)%K;
		
		//System.out.println(result);
		st.append(result);
		System.out.print(st);
	}
	
	public static long gcd(int i, int j) { //최대공약수
		int m = Math.max(i, j);
		long result = 0;
		for(int k=m; k>0; k--) {
			if(i%k==0 && j%k==0) {
				result = k;
				break;
			}
				
		}
		
		
		return result;
	}
	
	public static long lcm(int i, int j) { //최소공배수
		long result = i*j/gcd(i,j);
		return result;
	}

}
