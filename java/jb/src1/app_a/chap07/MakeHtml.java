import java.io.*;

public class MakeHtml {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line;
            // ルール1
            System.out.println("<!DOCTYPE html>");
            System.out.println("<html>");
            System.out.println("<head>");
            System.out.println("<title>My Page</title>");
            System.out.println("</head>");
            System.out.println("<body>");
            while ((line = reader.readLine()) != null) {
                if (line.startsWith("■")) {
                    // ルール3
                    System.out.println("<h1>" + line.substring(1) + "</h1>");
                } else if (line.startsWith("●")) {
                    // ルール4
                    System.out.println("<h2>" + line.substring(1) + "</h2>");
                } else {
                    // ルール5
                    System.out.println("<p>" + line + "</p>");
                }
            }
            // ルール2
            System.out.println("</body>");
            System.out.println("</html>");
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
