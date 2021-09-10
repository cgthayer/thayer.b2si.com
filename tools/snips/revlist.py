#!/usr/bin/python

Debug=1
def d(*a):
    global Debug
    if Debug > 0:
        print a

class SlistNode:
    def __init__(self, v):
        self.value = v
        self.next = None
    def __repr__(self):
        result = "<" + `self.value` + " -> " 
        if self.next:
            result += `self.next.value`
        else: 
            result += "None"
        result += ">"
        return result

class Slist:
    def __init__(self):
        self.head = None

    def append(self, n):
        t = self.tail()
        if t == None:
            self.head = n
            return
        t.next = n

    def insert(self, n):
        n.next = self.head
        self.head = n

    def tail(self):
        ptr = self.head
        while ptr != None and ptr.next != None:
            ptr = ptr.next
        return ptr
    
    def rev(self):
        p = self.head
        if not p:
            return
        prev = None
        while p.next:
            n = p.next
            p.next = prev
            prev = p
            p = n
        p.next = prev
        self.head = p
        
    def pp(self):
        p = self.head
        while p:
            print p
            p = p.next

        
def main():
    print "main"
    sl = Slist()
    sl.append(SlistNode(0))
    sl.append(SlistNode(1))
    sl.append(SlistNode(2))
    sl.append(SlistNode(3))
    sl.pp()
    print "REV"
    sl.rev()
    sl.pp()


main()


