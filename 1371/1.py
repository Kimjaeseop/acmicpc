chess = [[0]*8 ]*8

#horse = [[0]*8 ]*8
#chess[8][8] 
#horse[8][8]

for i in range(0,8) :
    for j in range(0,8) :
        print(i, j)
        if i % 2 == 0 and j % 2 == 0:
            chess[i][j]=1
        elif i % 2 == 1 and j % 2 == 1:
            chess[i][j]=1
    print(chess)

for i in range(8) :
    horse[i] = input()

count = 0
print(chess)

for p in range(8) :
    for q in range(8) :
        if(horse[p][q] == 'F' and chess[p][q] == 0) :
            count = count+1

print(count)
