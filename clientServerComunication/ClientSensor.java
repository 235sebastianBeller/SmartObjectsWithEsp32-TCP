import java.net.Socket;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ClientSensor extends Client {

    public ClientSensor(Socket clientSocket, int id) {
        super(clientSocket, id);
    }

    public String getDistance(String inputLine) {
        String distanciaStr = ClientSensorConstants.DEFAULT_DISTANCE;
        Pattern pattern = Pattern.compile(ClientSensorConstants.DISTANCE_PATTERN);
        Matcher matcher = pattern.matcher(inputLine);
        if (matcher.find()) {
            distanciaStr = matcher.group(ClientSensorConstants.FIRST_GROUP);
        }
        return distanciaStr;
    }

    @Override
    public void store(String inputLine) {
        int distance = Integer.parseInt(getDistance(inputLine));
        ClientHandler.distance = distance;
    }
}
