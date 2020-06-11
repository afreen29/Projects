/**********     Server Part     **********/


import java.io.*;
import java.net.*;
import java.util.*;


// Server has to process ping requests from client over UDP
public class server
{
      private static final double LOSS_RATE = 0.3;
      private static final int AVERAGE_DELAY = 100;  // milliseconds
      private static int packet_lost = 0;
      private static int packet_received = 0;

      public static void main(String[] args) throws Exception
      {
            // If argument not entered print message
            if (args.length != 1)
            {
                  System.out.println("Required arguments: port");
                  return;
            }
      	    // Port number
	          int port = Integer.parseInt(args[0]);

            // Random number generator to use in simulating packet loss and network delay
            Random random = new Random();

            // A datagram socket created for receiving and sending UDP packets through the specified port
            DatagramSocket socket = new DatagramSocket(port);

            // Loop to receive data packet, read it and replt to it
            System.out.print("Total No. of packets to be received are 10 ");
            System.out.print("\n" + "------------------------------------------------------------------------------------------------------------------------ " + "\n");

            while (true)
	          {

                  // A datagram packet created to hold incoming UDP packet
                  DatagramPacket request = new DatagramPacket(new byte[1024], 1024);

                  // Block new requests until the host receives a UDP packet
                  socket.receive(request);

                  // Print the received data
                  printData(request);

                  // To decide whether to reply or to simulate packet loss
                  if (random.nextDouble() < LOSS_RATE)
                  {
                          System.out.println("   Reply not sent");
                          packet_lost+=1;
                          System.out.println("No. of packets lost= " + packet_lost + "\n" + "No. of packets received= " + packet_received + "\n");
                          System.out.print("\n" + "------------------------------------------------------------------------------------------------------------------------ " + "\n");
                          continue;
                  }

                  // To simulate network delay
                  Thread.sleep((int) (random.nextDouble() * 2 * AVERAGE_DELAY));

                  // Sending reply
                  InetAddress clientHost = request.getAddress();
                  int clientPort = request.getPort();
                  byte[] buf = request.getData();
                  DatagramPacket reply = new DatagramPacket(buf, buf.length, clientHost, clientPort);
                  socket.send(reply);
                  System.out.println("   Reply sent");
                  packet_received+=1;
                  System.out.println("No. of packets lost= " + packet_lost + "\n" + "No. of packets received= " + packet_received + "\n");
                  System.out.print("\n" + "------------------------------------------------------------------------------------------------------------------------ " + "\n");

	          }

	    }

      // Print ping data to the standard output stream
      private static void printData(DatagramPacket request) throws Exception
      {
            // References to the array of bytes
            byte[] buf = request.getData();
            int buff = buf.length;

            // Wrap the bytes in a byte array input stream
            // To be able to read the data as a stream of bytes
            ByteArrayInputStream bais = new ByteArrayInputStream(buf);

            // Wrap the byte array output stream in an input stream reader
            // To be able to read the data as a stream of characters
            InputStreamReader isr = new InputStreamReader(bais);

            // Wrap the input stream reader in a bufferred reader
            // To be able to read the character data a line at a time
            BufferedReader br = new BufferedReader(isr);

            // The message data is contained in a single line, read the line.
            String line = br.readLine();

            // Print host address and data received from it
            System.out.println( "Received request from " + request.getAddress().getHostAddress() + ": " + new String(line) );
            System.out.println("Number of bytes = " + buff + "\n\n");
       }
}





/**********     Client Part     **********/


import java.io.*;
import java.net.*;
import java.time.Instant;
import java.time.LocalTime;
import java.time.ZoneOffset;
import java.time.ZonedDateTime;
import java.util.*;

// Client has to generate ping requests over UDP
// Server has to process ping requests over UDP
public class client
{

	    private static final boolean False = false;

	    public static void main(String[] args) throws Exception
	    {
             // If arguments are not entered print message
             if (args.length != 2)
             {
                    System.out.println("Required arguments: host port");
                    return;
             }

	          // Host to access
	          String ServerName = args[0];

            // Port number to access
            int port = Integer.parseInt(args[1]);

            // A datagram socket created for receiving and sending UDP packets through the specified port
            DatagramSocket socket = new DatagramSocket();
            InetAddress IPAddress = InetAddress.getByName(ServerName);
            boolean val = IPAddress.isReachable(1000);
            if (val==False)
            {
                    System.out.println("Host Unreachable");
                    return;
            }
            // Loop has to send 10 ping requests to the server
            for(int i=1;i<11;i++)
            {
                    // A datagram packet to hold the outgoing UDP packet
                    // Each message contains the word Ping, the packet sequence and a timestamp in Unix time
                    System.out.println("");
                    long SendTime = System.currentTimeMillis();
                    LocalTime CurTime = LocalTime.now();
                    String Message = "Ping "+ i + " " + CurTime + "\n";

                    DatagramPacket request = new DatagramPacket(Message.getBytes(), Message.length(),IPAddress,port );
                    socket.send(request);
                    DatagramPacket reply = new DatagramPacket(new byte[1024], 1024);

                    // If the reply is not receive in 1 second, assume packet lost then timeout
                    socket.setSoTimeout(1000);

                    try
                    {
                           socket.receive(reply);
                           Date now = new Date();
                           long ReceivedTime = System.currentTimeMillis();
                           // Time taken to receive reply after packet is sent
                           System.out.println("Reply - packet " + i + " : " + reply+ "\n");
                           long delay = (ReceivedTime - SendTime);
                           ZonedDateTime sentT = Instant.ofEpochMilli(SendTime).atZone(ZoneOffset.UTC);
                           System.out.println("Sent Packet at " + sentT );
                           ZonedDateTime receivedT = Instant.ofEpochMilli(ReceivedTime).atZone(ZoneOffset.UTC);
                           System.out.println("Received acknowledgement at " + receivedT );
                           System.out.println("Delay:  " + delay + " ms");
                           System.out.print("\n" + "------------------------------------------------------------------------------------------------------------------------ " + "\n");
                     }
                     catch(IOException E)
                     {
                           System.out.println("   Timeout for packet " + i );
                           System.out.println("   Reply not received from server");
                           System.out.print("\n" + "------------------------------------------------------------------------------------------------------------------------ " + "\n");
                     }   
	                   System.out.println("");
	                   Thread.sleep(1000);
             }
      }

}


