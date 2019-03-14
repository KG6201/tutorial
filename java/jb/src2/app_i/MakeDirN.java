import java.io.*;
import java.nio.file.*;

public class MakeDirN {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("使用法：java MakeDirN ディレクトリ名");
            System.out.println("例：java MakeDirN doc");
            System.exit(0);
        }
        String dirname = args[0];
        try {
            Path path = Files.createDirectory(Paths.get(dirname));
            System.out.println(dirname + "を作成しました。");
            System.out.println("絶対パスは" + path.toAbsolutePath() + "です。");
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
