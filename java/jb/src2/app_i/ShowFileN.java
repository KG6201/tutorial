import java.io.*;
import java.nio.file.*;
import java.nio.charset.*;

public class ShowFileN {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("使用法：java ShowFileN ファイル");
            System.out.println("例：java ShowFileN ShowFileN.java");
            System.exit(0);
        }
        String filename = args[0];
        try (BufferedReader reader = Files.newBufferedReader(Paths.get(filename), Charset.defaultCharset())) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (NoSuchFileException e) {
            System.out.println(filename + "が見つかりません。");
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
