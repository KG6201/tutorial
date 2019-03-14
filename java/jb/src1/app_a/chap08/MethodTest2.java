public class MethodTest2 {
    public static String[] getYourName() {
        String[] myoji_namae = new String[2];
        myoji_namae[0] = "結城";
        myoji_namae[1] = "浩";
        return myoji_namae;
    }
    public static void main(String[] args) {
        String[] s = getYourName();
        System.out.println("名字は" + s[0]);
        System.out.println("名前は" + s[1]);
    }
}
