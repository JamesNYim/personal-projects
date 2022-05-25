import random

def main():
    #Making the set of dominos
    dominoSet = [[0, 0], [0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[2,2],[2,3],[2,4],[2,5],[2,6],[3,3],[3,4],[3,5],[3,6],[4,4],[4,5],[4,6],[5,5],[5,6],[6,6]]

    #Getting the domino set for the first player
    playerOneSet = []
    while len(playerOneSet) < 7:
        randIndex = random.randint(0, len(dominoSet) - 1)
        playerOneSet.append(dominoSet[randIndex])
        dominoSet.remove(dominoSet[randIndex])
   
    #Getting the domino set for the second player
    playerTwoSet = []
    while len(playerTwoSet) < 7:
        randIndex = random.randint(0, len(dominoSet) -1)
        playerTwoSet.append(dominoSet[randIndex])
        dominoSet.remove(dominoSet[randIndex])

    print(playerOneSet)  
    print("\n")  
    print(playerTwoSet)

        




if __name__ == "__main__":
    main()