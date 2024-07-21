## NEPS 2715 - Placas de Carro (https://neps.academy/br/exercise/2715)
import re

s = input()

if re.fullmatch("[A-Z]{3}-[0-9]{4}", s):
    print(1)
elif re.fullmatch("[A-Z]{3}[0-9][A-Z][0-9]{2}", s):
    print(2)
else:
    print(0)
