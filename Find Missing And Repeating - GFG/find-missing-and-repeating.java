// { Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a, n);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}// } Driver Code Ends


// User function Template for Java

class Solve {
       int[] findTwoElement(int arr[], int n) {
     		int xxory=0;
	        for(int i=0;i<n;i++)
	            xxory^=(i+1)^arr[i];
	        
	       int rmsb=xxory&-xxory;
	   
	       int x=0;
	       int y=0;
	       for(int i=0;i<n;i++) {
	    	   if((rmsb & arr[i])==0) x^=arr[i];
	    	   else y^=arr[i];
	       } 
	       
	       for(int i=1;i<=n;i++) {
	    	   if((rmsb&i)==0) x^=i;
	    	   else y^=i;
	       }
	       
	   int ans[]=new int[2];
	   for(int i=0;i<n;i++){
	       if(arr[i]==x){
	           ans[0]=x;
	           break;
	       }else if(arr[i]==y){
	           ans[0]=y;
	           break;
	       }
	   } 
	   
	   ans[1]=x^y^ans[0];
       return ans;
    }
}