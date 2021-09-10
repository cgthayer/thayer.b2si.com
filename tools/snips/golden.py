#!/usr/local/bin/python

fib_prev = 1
fib = 1

while True:
    prev = fib
    fib = fib + fib_prev
    fib_prev = prev
    print prev, fib, 1.0 * fib / prev

