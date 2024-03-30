import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientActuator extends Client {
    private PrintWriter out;

    public ClientActuator(Socket clientSocket, int id) {
        super(clientSocket, id);
        initializePrintWriter();
    }

    public void initializePrintWriter() {
        try {
            this.out = new PrintWriter(clientSocket.getOutputStream(), true);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getMessageBasedOnDistance(int distance) {
        String[] messages = { "MUY CERCA,0,17,0,0,17,14,0,0", "LEJOS,0,17,0,0,31,0,0,0",
                "MUY LEJOS,0,17,0,0,31,0,0,0" };
        return messages[Math.min(distance / 14, 2)];
    }

    public String getMessageToWrite() {
        String message = "";
        if (id == 1) {
            message = Integer.toString(ClientHandler.distance / 7);
        } else if (id == 2)
            message = getMessageBasedOnDistance(ClientHandler.distance);
        return message;
    }

    @Override
    public void write() {
        out.println(getMessageToWrite());
    }
}
