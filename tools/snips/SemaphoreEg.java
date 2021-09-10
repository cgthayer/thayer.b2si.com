//

import java.util.*;
import java.util.concurrent.*;

class SemaphoreEg {
    private final int size;
    private int[] buffer;
    private Semaphore freeSlots;
    private Semaphore filledSlots;
    private boolean finish = false;
    private Producer p;
    private Consumer c;

    public SemaphoreEg(int size) {
	this.size = size;
	this.buffer = new int[size];
    }

    public void run() {
	freeSlots = new Semaphore(size);
	filledSlots = new Semaphore(0);
	p = new Producer();
	c = new Consumer();
	p.start();
	c.start();
	System.err.println("Running");
    }

    public void stop() {
	finish = true;
	try { p.join(); } catch (Exception e) { } 
	try { c.join(); } catch (Exception e) { } 
	System.err.println("Stopped");
    }

    class Producer extends Thread {
	public void run() {
	    System.err.println("Producer running");
	    int i = 0;
	    Random rgen = new Random();
	    while (true) {
		int no = rgen.nextInt(1000);
		// System.err.println("producer acquiring freeSlot");
		try {
		    freeSlots.acquire();
		} catch (Exception e) {
		    System.err.println(e);
		}
		buffer[i] = no;
		i++;
		if (i >= size) i=0;
		filledSlots.release();
		System.err.println(i + ": produced " + no);
		try {
		    Thread.sleep(no);
		} catch(Exception e) {
		}
		if (finish) 
		    return;
	    }
	}
    }

    class Consumer extends Thread {
	public void run() {
	    System.err.println("Consumer running");
	    int i = 0;
	    Random rgen = new Random();
	    while (true) {
		// System.err.println("\t\tconsumer acquiring filledSlot");
		try {
		    filledSlots.acquire();
		} catch (Exception e) {
		    System.err.println(e);
		}
		int no = buffer[i];
		i++;
		if (i >= size) i=0;
		freeSlots.release();
		int sleepfor = rgen.nextInt(1000);
		System.err.println("\t\t" + i + ": consumed " + no 
				   + ", sleeping " + sleepfor);
		try {
		    Thread.sleep(sleepfor);
		} catch (Exception e) {
		}
		if (finish) 
		    return;
	    }
	}
    }

}

class main {
  public static void main(String[] args) {
      System.err.println("Starting");
      SemaphoreEg eg = new SemaphoreEg(10);
      eg.run();
      try { Thread.sleep(10000); } catch (Exception e) { } 
      eg.stop();
      System.err.println("Done");
  }
}

// javac SemaphoreEg.java && java main SemaphoreEg.class

