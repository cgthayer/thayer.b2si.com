
class Test {
    static class Inner {
    }

    public static void test() {
	Class IA = int[].class;
	System.out.println("IA=" + IA);
	Class InnerArray = Inner[].class;
	System.out.println("InnerArray=" + InnerArray);
	//	InnerArray innerarray = new InnerArray();
	//	IA intarray = new IA();
	//	Class IAA = IA[].class;
	//	System.out.println("IAA=" + IAA);
    }
}

class main {
  public static void main(String[] args) {
      Test t = new Test();
      t.test();
  }
}

// javac test.java
// java main main.class Test.class

