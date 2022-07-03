from collections import deque


class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = int(1e9 + 7)
        day = 2
        know = 1
        canShare = 0
        sharing = deque()
        pending = deque()
        pending.append((1, 1))
        while day <= n:
            while len(sharing) > 0 and day - sharing[0][1] >= forget:
                know -= sharing[0][0]
                canShare -= sharing[0][0]
                sharing.popleft()

            while len(pending) > 0 and day - pending[0][1] >= delay:
                canShare += pending[0][0]
                sharing.append(pending.popleft())

            if canShare > 0:
                pending.append((canShare, day))
                know += canShare

            day += 1

        while int(know % MOD) < know:
            know = int(know % MOD)
        return know
