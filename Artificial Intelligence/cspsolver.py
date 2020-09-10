from itertools import combinations, permutations

a, b, c = 'NINA', 'SING', 'AGAIN'

for comb in combinations(range(10), 5):
    for perm in permutations(comb):
        d = dict(zip('NIASG', perm))
        def f(x): return sum(d[e] * 10**i for i, e in enumerate(x[::-1]))
        if f(a) + f(b) == f(c):
            print("{} + {} = {}".format(f(a), f(b), f(c)))