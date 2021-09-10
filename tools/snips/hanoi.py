#!/usr/bin/python

import sys

class Hanoi:
    def __init__(self, sz):
        self.sz = sz
        self.s = [ [], [], [] ]     # poles 0, 1, 2
        for x in range(sz, 0, -1):  # stack the disks on pole 0
            self.s[0].append(x)

    def solve(self):
        self.move(self.sz, 0, 1, 2)

    # x is the recursion level
    # s, f, d are the pole numbers for the source, free, destination poles
    def move(self, x, s, f, d):
        if x < 1: 
            print "Done"
            return
        print x, `self.s`
        self.move(x-1, s, d, f)
        self.s[d].append(self.s[s].pop())
        print x, `self.s`
        self.move(x-1, f, s, d)
        return
# end class

try:
    N = int(sys.argv[1])
except:
    N = 3

h = Hanoi(N)
print `h`, `h.s`
h.solve()

