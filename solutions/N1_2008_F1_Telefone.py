# NEPS 235 - Telefone (P1) (https://neps.academy/br/exercise/235)

keyboard = "22233344455566677778889999";
ans = list(map(lambda x: keyboard[ord(x) - ord('A')] if x.isalpha() else x, input()))

print(''.join(ans))
