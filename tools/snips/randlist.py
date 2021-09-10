#!/usr/bin/python

from random import randrange

ArraySize=20
Trials=200

def printarray(a):
    for i in range(len(a)):
        print i, a[i]
    return

def randlist1(a):
    for i in range(len(a)):
        ri = randrange(len(a))
        t = a[i]
        a[i] = a[ri]
        a[ri] = t
    return

def runtrial(trials, algo):
    matrix = []
    for i in range(ArraySize):
        matrix.append([])
        for j in range(ArraySize):
            matrix[i].append(0)
    for t in range(trials):
        r = range(ArraySize)            # array to randomize
        algo(r)
        # printarray(r)
        for i in range(len(r)):
            matrix[i][r[i]] += 1
    printarray(matrix)
    return

def main():
    runtrial(Trials, randlist1)

main()


