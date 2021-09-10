#!/usr/bin/python
"""

  blocksz.py <count> <size> -- Test the disk sequential write rate

     count -- do tests from 1 KB up to 1 KB * 1 ^ <count>
              eg. 3 means 1k, 2k ,4k, 8k
     size  -- max size in MB for the test file to reach

"""

import sys, os, time
FileName = ".blocktest"
MegaByte = 1024 * 1024  # bytes

def wr(bsize, bcount, count):
  """Writes <bcount> blocks of size <bsize>  averaged over count tests."""
  
  block = "x" * bsize
  totalTime = 0

  for c in range(count):
    fd = os.open(FileName, os.O_WRONLY | os.O_CREAT, 0666)
    startTime = time.time()
    for bi in range(bcount):
      os.write(fd, block)
    os.remove(FileName)
    tdiff = time.time() - startTime
    totalTime += tdiff

  avgTime = totalTime / count
  return bsize * bcount / avgTime  #  bytes per second

def suite(tcount, tsize):
  """Runs tcount tests from 1KB to tcount KB"""

  print "%3s: %6s %6s (%s)" % ("#", "bsize", "rate", "bcnt")
  for i in range(tcount):
    bsize = 1024 * (1 << i)
    bcount = tsize * MegaByte / bsize
    if bcount < 10:
      print "early exit"
      return
    rate = wr(bsize, bcount, 4) / MegaByte
    print "%3d: %6d %6.2f (%d)" % (i, bsize, rate, bcount)
  return

suite(int(sys.argv[1]), int(sys.argv[2]))
