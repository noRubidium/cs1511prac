#!/usr/bin/env python
import random
start_num = int(raw_input())
num_test = int(raw_input())

for i in xrange(num_test):
    a_len = random.randint(0,1000)
    l = [random.randint(-500,1000) for _ in xrange(a_len)]
    f = open('{:2}.in'.format(i+start_num), 'w')
    f.write(' '.join([str(x) for x in l]))
    f.write('\n')
    l2 = [random.randint(-1000,500) for _ in xrange(a_len)]
    f.write(' '.join([str(x) for x in l2]))
    f.write('\n')
    f.close()
    f = open('{:2}.out'.format(i+start_num), 'w')

    m = sum(i[0] * i[1] for i in zip(l, l2))
    f.write(str(m)+"\n")
    f.close()
