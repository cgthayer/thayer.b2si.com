#!/usr/bin/python

import sys

Debug=0

def debug(*args):
    global Debug
    if Debug > 0:
        print args


def maxsubseq(nums):
    if len(nums) <= 0:
        return
    max = nums[0]
    t = max  # running total
    s = 0
    e = 0
    for n in range(len(nums)):
        debug("n", n)
        cut = False
        if nums[n] >= 0:
            e = n
            if e > s:
                t += nums[n]
            debug("+", s, e, t)
        else:
            cut = True
        atend = n == len(nums)-1
        if cut or atend:
            debug("cut", s, e, t)
            if t > max:
                max = t
                debug("best", s, e, t)
            if atend:
                break
            s = n+1
            e = s
            t = nums[s]
        # if
    # for
    print "max", max

def main():
    debug("args", sys.argv)
    if (len(sys.argv) < 2):
        f = sys.stdin
    else:
        f = open(sys.argv[1], "r")
    nums = []
    for n in f:
        nums.append(int(n))
    f.close()
    debug("nums", nums)
    maxsubseq(nums)

main()
