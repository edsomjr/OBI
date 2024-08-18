A, B = input().split()
TA, TB = map(float, input().split())

if A == 'F':
    TA = (TA - 32)*5/9

if B == 'F':
    TB = (TB - 32)*5/9

if TA < TB:
    print("A")
else:
    print("B")
