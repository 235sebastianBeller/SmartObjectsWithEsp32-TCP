import java.net.Socket;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ClientSensor extends Client {

    public ClientSensor(Socket clientSocket, int id) {
        super(clientSocket, id);
    }

    public String getDistance(String inputLine) {
        String distanciaStr = "0";
        Pattern pattern = Pattern.compile("distance=(\\d+)");
        Matcher matcher = pattern.matcher(inputLine);
        if (matcher.find()) {
            distanciaStr = matcher.group(1);
        }
        return distanciaStr;
    }

    @Override
    public void store(String inputLine) {
        int distance = Integer.parseInt(getDistance(inputLine));
        ClientHandler.distance = distance;
    }
}
