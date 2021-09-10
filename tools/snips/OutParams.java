class LongMod {
    long value;
    LongMod() { value = -1; }
    public String toString() { return String.valueOf(value); }
}

class main {
    public static void test(Long outParam) {
	outParam = 42L;
	System.out.println("test: " + outParam);
	outParam = new Long(3);
	System.out.println("test: " + outParam);
    }

    public static void test2(LongMod outParam) {
	outParam.value = 42L;
	System.out.println("test2: " + outParam);
	outParam = new LongMod();
	System.out.println("test2: " + outParam);
    }

    public static void main(String[] args) {
	Long foo = new Long(1);
	test(foo);
	System.out.println("main: " + foo);  // still 1
	LongMod moo = new LongMod();
	test2(moo);
	System.out.println("main: " + moo);  // now 42
	
    }
}

// javac OutParams.java && java main

