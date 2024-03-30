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
        String[] messages = { "No me toques,28,2,7,6,0,0,0,0,0,0,0,0,14,17,31,0,7,8,28,12,0,0,0,0",
         "Alejate mas,8,4,2,31,0,0,0,0,0,0,0,0,0,10,21,0,2,4,8,31,0,0,0,0", 
         "Amo tu distancia,0,10,31,31,14,4,0,0,0,0,0,0,0,17,14,0,0,10,31,31,14,4,0,0" };
      
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
