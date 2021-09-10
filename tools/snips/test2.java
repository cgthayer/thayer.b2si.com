class main {
  public static void main(String[] args) {
      String s = "FOO";
      String t = new String("FOO");
      System.out.println("s=" + s + " t=" + t);
      if (s == t) 
	  System.out.println("s == t");
      else 
	  System.out.println("s != t");
      if (s.equals(t)) 
	  System.out.println("s.equals(t)");
      if (s.equalsIgnoreCase("foo")) 
	  System.out.println("s.equalsIgnoreCase(foo)");
  }
}

// javac test.java && java main

