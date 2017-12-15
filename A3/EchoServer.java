import java.io.*;
import java.net.*;

//Server code modified to use threads for multiple clients

public class EchoServer {

 private ServerSocket server;
 private Socket client;
 private int port = 8998;

 //Create a class that extends Thread
 private class ServerThread extends Thread {

   private Socket client;
   private DataOutputStream out;
   private ByteArrayOutputStream buffer;
   private InputStream in;
   private boolean connection = true;

   //Thread class constructor, takes the client socket object
   ServerThread(Socket client){

     try{

       // Get the input and output stream from the socket connection
       out = new DataOutputStream(client.getOutputStream());
       buffer = new ByteArrayOutputStream(); //Buffer, same as A2
       in = client.getInputStream();

      //Start up the thread
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

   //Have to implement run for the Thread class.
   public void run(){
     try{
       while(connection) {
         //Read the input and execute the echo method
         //If the connection changes, change the connection value
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
     // Accept lots of connections by starting a new thread for each
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

//Method to output an echo, and returns a boolean value if connection status changes
 private boolean echo(ByteArrayOutputStream buffer, InputStream in, DataOutputStream out){

   try{
     //Get the message from the input stream
     //Basically the same code as A2
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
