num = int(input())

for i in range(num):
    W, L, S = map(int, input().split())
    R = input()
    R = int(R)
    obs = []
    for i in range(R):
        freq, loc = map(int, input().split())
        obs.append([freq, loc])
    cmd = input()

    # starting line
    for i in range(3):
        line = ''
        if i == 0:
            for i in range(W+2):
                line += '='
        if i == 1:
            line += '|'
            for i in range(S-1):
                line += ' '
            line += 'v'
            for i in range(W-S):
                line += ' '
            line += '|'
        if i == 2:
            for i in range(W+2):
                line += '-'
        print(line)

    #track
    for i in range(L+1):
        #win code
        if i == L:
            line = ''
            for i in range(W+2):
                line += '='
            print(line)
            print('Course Complete!')
            break

        linelist = ['|']
        currobs = []
        for j in range(R):
            if (i+1) % obs[j][0] == 0:
                currobs.append(obs[j][1])
        if cmd[i] == 'L' and S > 1:
            S -= 1
        if cmd[i] == 'R' and S < W:
            S += 1
        
        #crash code
        if S in currobs:
            for j in range(W):
                linelist.append(' ')
            for j in range(len(currobs)):
                linelist[currobs[j]] = 'o'
            linelist[S] = 'X'
            line = ''
            for j in range(W+1):
                line += linelist[j]
            line += '|'
            print(line)
            print('You Crashed - GAME OVER')
            break
        
        #safe code
        for j in range(W):
            linelist.append(' ')
        for j in range(len(currobs)):
            linelist[currobs[j]] = 'o'
        linelist[S] = 'v'
        line = ''
        for j in range(W+1):
            line += linelist[j]
        line += '|'
        print(line)