
class main {
    public static void p(String s) {
	System.out.println(s);
    }

    static class BadSync {
	public static Integer counter = 0;
	public static Integer genId() {
	    synchronized(counter) {
		Integer result = counter;
		p(String.format("obj = %d", System.identityHashCode(counter)));
		counter++;
		return result;
	    }
	}
    }
    
    static class BT implements Runnable {
	private int myid;
	public BT(int i) { myid = i; } 
	public void run() {
	    for (int i=0; i < 1000; i++) {
		p(String.format("BT %d: %d", myid, BadSync.genId()));
	    }
	}
    }

    static void sleep(int ms) {
	try { Thread.sleep(ms); } catch(Exception e) { }
    }

    public static void main(String[] args) {
	p("Starting");
	//p(BadSync.genId().toString());
	//p(BadSync.genId().toString());
	BT[] bt = new BT[100];
	Thread[] threads = new Thread[100];
	for (int b=0; b < bt.length; b++) {
	    bt[b] = new BT(b);
	    threads[b] = new Thread(bt[b]);
	}
	for (int b=0; b < bt.length; b++) {
	    threads[b].start();
	    p(String.format("launched %d", b));
	}
	for (int b=0; b < bt.length; b++) {
	    try {
		threads[b].join();
	    } catch(Exception e) {
		p("Exception in join");
	    }
	    p(String.format("joined %d", b));
	}
	p(BadSync.genId().toString());
	p("Done");
    }
}

// javac BadSync.java; java main

