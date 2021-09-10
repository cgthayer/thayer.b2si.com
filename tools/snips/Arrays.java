
class Boo {
    public static int classNum;
    public int objNum;
    public Boo() {
	objNum = classNum++;
    }
    public String toString() { return "[" + objNum + "]"; }
}

class main {
    public static String pp(Object array[]) {
	String res = new String();
	for (int i=0; i < array.length; i++) {
	    res += i + "=" + array[i] + "\n";
	}
	return res;
    }

    public static void main(String[] args) {
	Boo a[] = new Boo[6];
	System.out.println(pp(a));
	for (int i=0; i < 6; i++) {
	    a[i] = new Boo();
	}
	System.out.println(pp(a));
    }
}

// javac Arrays.java
// java main main.class Arrays.class

