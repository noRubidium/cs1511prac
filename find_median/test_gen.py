#!/usr/bin/env python
import random
import statistics
start_num = int(raw_input())
num_test = int(raw_input())

for i in xrange(num_test):
    l = [random.randint(-100000,100000) for _ in xrange(random.randint(0,1000))]
    l.sort()
    f = open('{:2}.in'.format(i+start_num), 'w')
    f.write(' '.join([str(x) for x in l]))
    f.write('\n')
    f.close()
    f = open('{:2}.out'.format(i+start_num), 'w')

    try:
        m = statistics.median(l)
    except:
        m = -1
    f.write(str(m)+"\n")
    f.close()
