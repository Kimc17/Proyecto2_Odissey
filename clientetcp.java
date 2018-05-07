import java.net.*; //Se importa la libreria java.net
import java.io.*; //Se importa la libreria java.io
 
//Se declara la clase clientetcp
public class clientetcp {
 
	//Se declara el método principal main que recibe un parámetro
   public static void main(String argv[]) {
 
	       
	   String ip = "192.168.100.3";
	   int port = 8888;
	   java.net.Socket socket;
	try {
		socket = new java.net.Socket(ip,port);
		OutputStreamWriter out = new OutputStreamWriter(socket.getOutputStream());
		   InputStreamReader in = new InputStreamReader(socket.getInputStream());

		   String msg = "Hello, world!";

		   //send
		   PrintWriter pw = new PrintWriter(out, true);
		   pw.print(msg);
		   pw.flush();
		   // I also tried: out.write(msg); out.flush(); nothing changed

		   //receive the reply
		   BufferedReader br = new BufferedReader(in);
		   char[] buffer = new char[300];
		   int count = br.read(buffer, 0, 300);
		   String reply = new String(buffer, 0, count);
		   System.out.println(reply);
		   out.write(msg);
		   socket.shutdownOutput();

		   try {
			socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	   

}
}