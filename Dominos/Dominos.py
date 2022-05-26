import random
def drawDomino(dominoSet, playerSet):
        randIndex = random.randint(0, len(dominoSet) - 1)
        playerSet.append(dominoSet[randIndex])
        dominoSet.remove(dominoSet[randIndex])

def playingDomino(playerSet, dominoBoard):
    dominoPlayed = False
    for playDomino in playerSet:
            if len(dominoBoard) == 0:
                dominoBoard.append(playDomino)
                playerSet.remove(playDomino)
            else:
                if dominoBoard[0][0] == playDomino[1]:
                    dominoBoard.insert(0, [playDomino[0], playDomino[1]])
                    playerSet.remove(playDomino)
                    dominoPlayed = True
                    break
                elif dominoBoard[0][0] == playDomino[0]:
                    dominoBoard.insert(0, [playDomino[1], playDomino[0]])
                    playerSet.remove(playDomino)
                    dominoPlayed = True
                    break
                elif dominoBoard[len(dominoBoard) - 1][1] == playDomino[0]:
                    dominoBoard.append([playDomino[0], playDomino[1]])
                    playerSet.remove(playDomino)
                    dominoPlayed = True
                    break
                elif dominoBoard[len(dominoBoard) - 1][1] == playDomino[1]:
                    dominoBoard.append([playDomino[1], playDomino[0]])
                    playerSet.remove(playDomino)
                    dominoPlayed = True
                    break
    return dominoPlayed
    


def main():
    #Making the set of dominos
    dominoSet = [[0, 0], [0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[2,2],[2,3],[2,4],[2,5],[2,6],[3,3],[3,4],[3,5],[3,6],[4,4],[4,5],[4,6],[5,5],[5,6],[6,6]]

    #Getting the domino set for the first player
    playerOneSet = []
    while len(playerOneSet) < 7:
        drawDomino(dominoSet, playerOneSet)
   
    #Getting the domino set for the second player
    playerTwoSet = []
    while len(playerTwoSet) < 7:
        drawDomino(dominoSet, playerTwoSet)

    #The Game of dominos
    playerOnePoints = 0
    playerTwoPoints = 0
    playerOneWin = False
    playerTwoWin = False
    dominoPlayBoard = []
    while (not playerOneWin or not playerTwoWin):

        #Player One Turn
        dominoPlayed = playingDomino(playerOneSet, dominoPlayBoard)
        if not dominoPlayed:
            drawDomino(dominoSet, playerOneSet)
            playingDomino(playerOneSet, dominoPlayBoard)

        #Player Two Turn
        dominoPlayed = playingDomino(playerTwoSet, dominoPlayBoard)
        if not dominoPlayed:
            drawDomino(dominoSet, playerTwoSet)
            playingDomino(playerTwoSet, dominoPlayBoard)
        
        #Checking for a winner
        if (len(playerOneSet) == 0):
            playerOneWin = True
            break

        if (len(playerTwoSet) == 0):
            playerTwoWin = True
            break

    #Printing out win results
    if playerOneWin:
        print("PlayerOne has won")
    if playerTwoWin:
        print("Player Two has won")
    
    print(dominoPlayBoard)
        


        



        




if __name__ == "__main__":
    main()