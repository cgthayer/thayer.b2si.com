#!/usr/bin/python

import sys

def kgraph(n, pre):
    for x in range(n):
        for dst in range(n):
	    if (x != dst):
		print("date\t%s%d\t%s%d" % (pre, x, pre, dst))
            
num=int(sys.argv[1])
if len(sys.argv) > 2:
    pre = sys.argv[2]
else:
    pre = "node-"
kgraph(num, pre)
