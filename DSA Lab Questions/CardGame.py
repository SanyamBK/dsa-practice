from heapq import heappush, heappop

def calculate_scores(N, cards):
    scores = []
    heap = []
    total_score = sum(cards)
    scores.append(total_score)

    for card in cards:
        heappush(heap, card)

    while len(heap) > 1:
        min_card = heappop(heap)
        max_card = heap[-1]
        diff = abs(max_card - min_card)
        total_score -= (min_card + max_card)
        scores.append(total_score)
        heappush(heap, diff)

    return scores

# Read input
N = int(input())
cards = list(map(int, input().split()))

# Calculate scores
scores = calculate_scores(N, cards)

# Print output
for score in scores:
    print(score)
