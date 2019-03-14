public class CountOk {
    public static void main(String[] args) {
        int i;                              // for文の前で宣言          
        for (i = 0; i < 3; i++) {           // for文の中では宣言しない  
            System.out.println(i);
        }
        System.out.println("i = " + i);
        System.out.println("end");
    }
}
