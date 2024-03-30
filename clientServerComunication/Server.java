import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private int portNumber;
    private ServerSocket serverSocket;

    Server(int portNumber) {
        this.portNumber = portNumber;
        initializeServerSocket();
    }

    public void initializeServerSocket() {
        try {
            this.serverSocket = new ServerSocket(portNumber);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleConnectionClient(Socket clientSocket) {
        ClientHandler clientHandler = new ClientHandler(clientSocket); 
        Thread thread = new Thread(clientHandler);
        thread.start();
    }


    public void startListening() {
        try {
            System.out.println("Server started. Listening on port " + portNumber + "...");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected: " + clientSocket.getInetAddress().getHostAddress());
                handleConnectionClient(clientSocket);
            }
        } catch (IOException e) {
            System.err.println("Error occurred while listening for connections on port " + portNumber);
            e.printStackTrace();
        }
    }
}
