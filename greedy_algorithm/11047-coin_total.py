N, target = map(int, input().split())

coin_list = []
for i in range(N):
    coin_list.append(int(input()))

coin_list.reverse()

result = 0
for coin in coin_list:
    if target >= coin:
        maxCoin = target // coin
        result += maxCoin
        target -= coin * maxCoin

print(result)