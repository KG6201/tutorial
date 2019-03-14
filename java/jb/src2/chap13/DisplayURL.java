import java.io.*;
import java.net.*;

public class DisplayURL {
    public static void main(String[] args) {
        for (String arg : args) {
            System.out.println("URL =  " + arg);
            try {
                URL url = new URL(arg);
                BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
                while (true) {
                    String line = reader.readLine();
                    if (line == null) {
                        break;
                    }
                    System.out.println(line);
                }
                reader.close();
            } catch (MalformedURLException e) {
                System.out.println("URLの形式が誤っています：" + e);
            } catch (IOException e) {
                System.out.println("I/Oエラーです：" + e);
            }
        }
    }
}
