import java.io.*;
import java.net.*;

public class Main {
    public static void main(String[] args) {
        Server serverPc = new Server(YOUR_PORT_NUMBER);
        serverPc.startListening();
    }
}
