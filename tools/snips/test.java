
class TestTrace {
    public static void Sleep() {
      try {
	  Thread.sleep(10 * 1000);
      } catch (Exception e) {
	  System.err.println("Caught: " + e);
      }
    }
}

class main {
  public static void main(String[] args) {
      System.err.println("Starting");
      TestTrace.Sleep();
      System.err.println("Done");
  }
}

// javac test.java
// java main main.class TestTrace.class & sleep 1; kill -3 $!

