 import java.util.*;
public class max_occur 
{
    static final int ASCII_SIZE = 256;
    int max = -1;
    static char getMaxOccuringChar(String str)
    {
        int count[] = new int[ASCII_SIZE];
     
        int len = str.length();
        
        for (int i=0; i<len; i++)
            count[str.charAt(i)]++;
      
        int max = -1;  
        char result = ' ';  

        for(int i=0;i<len;i++)
        {
        	if(count[str.charAt(i)] >max)
        		max = count[str.charAt(i)];
        } 
        for(int i=0;i<len;i++)
        {
        	if(count[str.charAt(i)] == max){
        		result = str.charAt(i);
        		break;
        	}

        }
        return result;
    }
     
    // Driver Method
    public static void main(String[] args)
    {
    	Scanner in = new Scanner(System.in);
    	String str = in.next();
        System.out.println("Max occurring character is " +
                            getMaxOccuringChar(str));
    }
}