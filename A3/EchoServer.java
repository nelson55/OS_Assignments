import java.io.*;
import java.net.*;

//Server code modified to use threads for multiple clients

public class EchoServer {

 private ServerSocket server;
 private Socket client;
 private int port = 8998;


 private class ServerThread extends Thread {

   private Socket client;
   private DataOutputStream out;
   private ByteArrayOutputStream buffer;
   private InputStream in;
   private boolean connection = true;


   ServerThread(Socket client){

     try{

       // Get the input and output stream from the socket connection
       out = new DataOutputStream(client.getOutputStream());
       buffer = new ByteArrayOutputStream();
       in = client.getInputStream();

       this.start();

     } catch (SocketException e){
       System.out.print("[Server]: Connection Reset");
       System.exit(1);
     } catch (EOFException e){
       System.out.println("[Server]: Client Connection Closed.");
     } catch (IOException e) {
      e.printStackTrace();
     }

   }

   public void run(){
     try{
       while(connection) {
         //Read the input and execute the echo method
         if(echo(buffer, in, out) == true){
           connection = true;
         } else {
           connection = false;
         }
       }
     } catch(Exception e) {
       e.printStackTrace();
     }
   }

 }


 public EchoServer () {


  try {
   // Create socket server
   server = new ServerSocket(port);

   System.out.println("[Server]: Started. Waiting for connection on port " + port);

   while(true){
     // Accept lots of connections by starting a new thread

     new ServerThread(server.accept());
     System.out.println("[Server]: Client connected.");

   }

  } catch (SocketException e){
    System.out.print("[Server]: Connection Reset");
    System.exit(1);
  } catch (EOFException e){
    System.out.println("[Server]: Client Connection Closed.");
  } catch (IOException e) {
   e.printStackTrace();
  }
 }

 private boolean echo(ByteArrayOutputStream buffer, InputStream in, DataOutputStream out){

   try{
     //Get the message from the input stream
     //String msg = in.readUTF();
     int nRead;
     byte[] data = new byte[16384];

     if ((nRead = in.read(data, 0, data.length)) != -1){
         buffer.write(data,0,nRead);
     } else if ((nRead = in.read(data, 0, data.length)) == -1){
         return false;
     }

     buffer.flush();

     byte[] byteMsg = buffer.toByteArray();

     String msg = new String(byteMsg, "UTF-8");



     System.out.println("[Server]: Message received: " + msg);

     //Output the message to the output stream
     out.write(byteMsg);
     out.flush();
     buffer.reset();
     return true;
   } catch(IOException e) {
     System.out.println("[Server]: Connection Lost");
     return false;
   }


 }

 public static void main (String [] args) {
  new EchoServer();
 }



}
