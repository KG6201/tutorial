public class StringSwitch {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("使い方: java StringSwitch 飲み物");
        } else {
            String str = args[0];
            System.out.printf("入力された文字列は %s です。%n", str);
            switch (str) {
            case "orange":
                System.out.println("オレンジですね。");
                break;

            case "coffee":
                System.out.println("コーヒーですね。");
                break;

            case "tea":
                System.out.println("お茶ですね。");
                break;

            default:
                System.out.println("飲み物には orange, coffee, tea のどれかを指定してください。");
                break;
            }
        }
    }
}
