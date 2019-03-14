import java.io.*;
import java.nio.file.*;
import java.nio.charset.*;

public class WriteFileN {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("使用法：java WriteFileN 作成ファイル");
            System.out.println("例：java WriteFileN output.txt < input.txt");
            System.exit(0);
        }
        String filename = args[0];
        try (
            BufferedReader reader
                = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter writer
                = new PrintWriter(
                    Files.newBufferedWriter(Paths.get(filename),
                    Charset.defaultCharset(),
                    StandardOpenOption.CREATE_NEW))) {
            String line;
            while ((line = reader.readLine()) != null) {
                writer.println(line);
            }
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
