public class MethodTest3 {
    public static void getYourName(String[] args) {
        args[0] = "結城";
        args[1] = "浩";
    }
    public static void main(String[] args) {
        String[] s = new String[2];
        getYourName(s);
        System.out.println("名字は" + s[0]);
        System.out.println("名前は" + s[1]);
    }
}
