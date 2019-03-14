public class Student {
    String name;    // 氏名
    int[] tens;     // 試験の点数
    public Student(String name, int[] tens) {
        this.name = name;
        this.tens = tens;
    }
    public Student(String name, int x, int y, int z) {
        ???
    }
    @Override
    public String toString() {
        String s = "[" + name;
        for (int i = 0; ???; i++) {
            s += ???;
        }
        s += "]";
        return s;
    }
    public int total() {
        int sum = 0;
        for (int i = 0; ???; i++) {
            ???
        }
        return sum;
    }
}
