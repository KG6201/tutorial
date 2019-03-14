import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.*;

public class ListDirN {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("使用法：java ListDirN ディレクトリ名");
            System.out.println("例：java ListDirN doc");
            System.exit(0);
        }
        String dirname = args[0];
        try {
            try (DirectoryStream<Path> dirs = Files.newDirectoryStream(Paths.get(dirname))) {
                for (Path path : dirs) {
                    System.out.println(path);
                }
            } catch (DirectoryIteratorException e) {
                throw e.getCause();
            }
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
