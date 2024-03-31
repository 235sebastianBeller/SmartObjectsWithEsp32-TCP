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
        String[] messages = {
                ClientActuatorConstants.SO_CLOSE_MESSAGE,
                ClientActuatorConstants.CLOSE_BY_MESSAGE,
                ClientActuatorConstants.SO_FAR_MESSAGE };
        int index = distance / ClientActuatorConstants.INTERVAL_MESSAGES_LCD;
        return messages[Math.min(index, messages.length - 1)];
    }

    public String getMessageToWrite() {
        String message = "";
        if (id == ClientActuatorConstants.ID_CLIENT_ONE) {
            message = Integer.toString(ClientHandler.distance / ClientActuatorConstants.INTERVAL_LEDS);
        } else if (id == ClientActuatorConstants.ID_CLIENT_TWO)
            message = getMessageBasedOnDistance(ClientHandler.distance);
        return message;
    }

    @Override
    public void write() {
        out.println(getMessageToWrite());
    }
}
