import java.io.*;

public class WeekArray {
    public static void main(String[] args) {
        String[] week = {
            "日曜日",
            "月曜日",
            "火曜日",
            "水曜日",
            "木曜日",
            "金曜日",
            "土曜日",
        };
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.println("0〜6の数字を入力してください。対応した曜日を表示します。");
            String line = reader.readLine();
            int n = Integer.parseInt(line);
            if (0 <= n && n < 7) {
                System.out.println(week[n]);
            } else {
                System.out.println("0〜6の範囲で入力してください");
            }
        } catch (IOException e) {
            System.out.println(e);
        } catch (NumberFormatException e) {
            System.out.println("数字を入力してください");
        }
    }
}
