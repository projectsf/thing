import java.io.*;

public class Cat  {
	public static void main (String args[]) {
		String thisLine;
		for (int i=0; i < args.length; i++) {
			try {
				System.out.println("===========================");
				System.out.println("filename: "+args[i]+", length: "+new File(args[i]).length()+" bytes");
				System.out.println("===========================");
				FileInputStream fin =  new FileInputStream(args[i]);

				// JDK1.1+
				BufferedReader myInput = new BufferedReader(new InputStreamReader(fin));
				while ((thisLine = myInput.readLine()) != null) {
					System.out.println(thisLine);
				}
				System.out.println("===========================");         
			}
			catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
}
