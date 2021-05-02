import java.io.*;
public class p1003 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t =  Integer.parseInt(br.readLine());
		
		int f[] = new int[2000];
		int arr[] = new int[2000];
		int arr0[] = new int[2000];
		int arr1[] = new int[2000];
		
		for(int j=0; j<t; j++) {
			int n = Integer.parseInt(br.readLine());
			arr[j]=n;
			//int zero = 0;
			//int one = 0;
            
            f[0]=0;
            f[1]=1;
            
				for(int i=0; i<=n; i++) {
					
					
					if(i==0) {
						arr0[0]=1;
						arr1[0]=0;
						continue;
					}
					
					else if(i==1) {
						arr0[1]=0;
						arr1[1]=1;
						continue;
					}
						f[i]=f[i-1]+f[i-2];
					
					
					if(n==0) {
						arr0[0]=1;
						arr1[0]=0;
					}
					else if(n==1) {
						arr0[1]=0;
						arr1[1]=1;
					}
					else {
						arr0[i]=1;
						arr1[i]=n-1;
					}
					
				}
				
				//System.out.println(arr0[n]+" "+arr1[n]);
		
		}
		
		for(int i=0; i<t; i++) {
			System.out.println(arr0[arr[i]]+" "+arr1[arr[i]]);
		}
		
		br.close();
		
	}
}
