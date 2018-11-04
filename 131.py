import sys

cards = ['A', '2', '3', '4', '5', '6', '7',
         '8', '9', 'T', 'J', 'Q', 'K', 'A']
colors = ['C', 'D', 'H', 'S']

Z = [[], [0], [1], [2], [3], [4],
     [0, 1], [0, 2], [0, 3], [0, 4], [1, 2],
     [1, 3], [1, 4], [2, 3], [2, 4], [3, 4],
     [0, 1, 2], [0, 1, 3], [0, 1, 4], [0, 2, 3],
     [0, 2, 4], [0, 3, 4], [1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4],
     [0, 1, 2, 3], [0, 1, 2, 4], [0, 1, 3, 4], [0, 2, 3, 4], [1, 2, 3, 4],
     [0, 1, 2, 3, 4]]

V = ['straight-flush', 'four-of-a-kind', 'full-house', 'flush', 'straight',
     'three-of-a-kind', 'two-pairs', 'one-pair', 'highest-card']

def freq(hand):
    freq = []
    
    for card in cards:
        cnt = 0
        for i in range(5):
            cnt += hand[i][0] == card

        freq.append(cnt)
                
    return freq

def freq_col(hand):
    freq = [0] * 4

    for i in range(5):
        for j in range(len(colors)):
            freq[j] += hand[i][1] == colors[j]

    return freq

def check(hand):
    F = freq(hand)
    Fc = freq_col(hand)
    
    straight = any([all(F[i : i + 5]) for i in range(len(cards) - 4)])
    flush = any([f > 4 for f in Fc])
    
    if straight and flush:
        return 0
    if any([f > 3 for f in F]):
        return 1
    if any([f == 2 and g == 3 for f in F for g in F]):
        return 2
    if flush:
        return 3
    if straight:
        return 4
    if any([f > 2 for f in F]):
        return 5
    if any([i != j and F[i] == 2 and F[j] == 2
            for i in range(len(F)) for j in range(len(F))]):
        return 6
    if any([f == 2 for f in F]):
        return 7
    
    return 8

for line in sys.stdin:
    line = line.split()
    hand = line[:5]
    deck = line[5:]

    sol = 9
    
    for z in Z:
        res = list(hand)
        for i in range(len(z)):
            res[z[i]] = deck[i]

        sol = min(sol, check(res))

    sys.stdout.write('Hand: ' + ' '.join(hand) + ' Deck: ' + ' '.join(deck))
    sys.stdout.write(' Best hand: ' + V[sol] + '\n')
