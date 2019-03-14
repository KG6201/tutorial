class MyojiNamae {
    String myoji;
    String namae;
}

public class MethodTest4 {
    public static MyojiNamae getYourName() {
        MyojiNamae obj = new MyojiNamae();
        obj.myoji = "結城";
        obj.namae = "浩";
        return obj;
    }
    public static void main(String[] args) {
        MyojiNamae mn = getYourName();
        System.out.println("名字は" + mn.myoji);
        System.out.println("名前は" + mn.namae);
    }
}
