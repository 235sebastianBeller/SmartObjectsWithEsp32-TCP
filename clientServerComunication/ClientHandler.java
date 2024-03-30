import java.io.*;
import java.net.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ClientHandler extends Thread {
    private Socket clientSocket;
    private BufferedReader in;
    private Client[] clients;
    public static int distance = 0;

    public ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
        initializeInBuffer();
        initilizeClients();
    }

    public void initilizeClients() {
        clients = new Client[] {
                new ClientSensor(clientSocket, 0),
                new ClientActuator(clientSocket, 1),
                new ClientActuator(clientSocket, 2)
        };
    }

    public void initializeInBuffer() {
        try {
            this.in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int extractIdFromInput(String inputLine) {
        int id = 0;
        Pattern pattern = Pattern.compile("id=(\\d+)");
        Matcher matcher = pattern.matcher(inputLine);
        if (matcher.find()) {
            id = Integer.parseInt(matcher.group(1));
        }
        return id;
    }

    @Override
    public void run() {
        try {
            int id = 0;
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println(inputLine);
                id = extractIdFromInput(inputLine);
                clients[id].write();
                clients[id].store(inputLine);
            }
            clients[id].disconnectFromServer();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
