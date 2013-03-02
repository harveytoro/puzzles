import java.util.Scanner;

public class zipfsong {

    static  double[] qi;
 
    public static void main(String[] args) {
	try {
		
        Scanner l1 = new Scanner(System.in);
        Scanner ln = new Scanner(System.in);
		String[] line1 = l1.nextLine().split(" ");
		int n = Integer.parseInt(line1[0]);
		int m = Integer.parseInt(line1[1]);
		
        int asize = n * 2;
        String[] songsn;
        songsn = new String[asize];
        long[] fi;
        fi = new long[n];
        double[] zi;
        zi = new double[n];

        qi = new double[n];


        int count = 0;
        for (int i = 0; i < n; i++) {
            String[] songn = ln.nextLine().split(" ");
            songsn[count] = songn[0];
            count++;
            songsn[count] = songn[1];
            count++;
        }

        //Gets numbers from song lines
        int everyotherone = 0;
        int every = 0;
        double x = 0;
        double cast = 0;
		int div = 2;
        for (int j = 0; j < n; j++) {
            
          	fi[j] = Long.parseLong(songsn[everyotherone]);
            everyotherone += 2;

            if (j == 0) {
                x = fi[0];
            } else {
                x = fi[0] / div;
				div++;
            }
            zi[j] = x;

            qi[j] = fi[j] / zi[j];

            cast = qi[j];

            songsn[every] = Double.toString(cast);
            every += 2;

        }

        for (int p = 0; p < m; p++) {
            double ret = order();

            String sret = Double.toString(ret);
            String loop;
            for (int i = 0; i < asize; i++) {
                loop = songsn[i];
                if (loop.equals(sret)) {
                    System.out.println(songsn[i + 1]);
					songsn[i] = "used";
                    break;
                }
            }
        }
	} catch (Exception e) {
	
	}



    }//main()
    
    
    public static double order(){
        
        double temp;

        for (int i = 0; i < qi.length; i++) {

            if (qi[i] > qi[0]) {
                temp = qi[0];
                qi[0] = qi[i];
                qi[i] = temp;
            }
			
				
			

        }
        double anws = qi[0];
        qi[0] = 0;
        return anws;
  
    }//order()
    
}//class