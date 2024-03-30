import java.io.IOException;
import java.net.Socket;

public class Client {
    protected Socket clientSocket;
    protected int id;

    Client(Socket clientSocket, int id) {
        this.clientSocket = clientSocket;
        this.id = id;
    }

    public void write() {
    }

    public void store(String inputLine) {
    }

    public void disconnectFromServer() {
        try {
            clientSocket.close();
            System.out.println("Client disconnected: " + clientSocket.getInetAddress().getHostAddress());
        } catch (IOException e) {
            System.err.println("Error occurred while closing client socket");
            e.printStackTrace();
        }

    }
}
