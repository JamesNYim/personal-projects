import random
import copy
def main():
    
    #Word stuff
    wordBank = ["teas", "poop", "milk", "boba", "cute", "home", "game", "rice"]
    #testBank = ["boba"]
    #wordBank = testBank
    wordLength = 4
    wordDict = {}
    for currentWord in wordBank:
        wordDict[currentWord] = {}
        currentWordDict = {}
        for letter in currentWord:
            if letter in currentWordDict:
                currentWordDict[letter] = currentWordDict[letter] + 1
            else:
                currentWordDict[letter] = 1
       
        wordDict[currentWord] = currentWordDict
        

    for word in wordDict:
       print("Word: " + word + " " +  "wordDict: " + str(wordDict[word]))        


    
    
    
   
    
    #Starting the game
    gameRunning = False
    letterFound = False
    while (not gameRunning):
        userInput = input("\n\n\n\n\nWelcome to jank wordle! Type \"Ready\" when ready to start\nOr Type \"help\" for rules and how to play\n")
        if (userInput == "Ready"):
            print("Guess the 4 letter word!\n")
            guessWord = random.choice(wordBank)
            guessWord = wordBank[3]
            gameRunning = True
        if (userInput == "help"):
            print("How to play Jank Wordle\n")
            print("\n")
            print("+------------------------------------------------------+\n")
            print("|Guessing the word                                     |\n")
            print("|                                                      |\n")
            print("|() Means that it is in the word                       |\n")
            print("|[] Means that it is in the word AND in the right place|\n")
            print("|\"\" means that the letter isnt in the word           |\n")
            print("|                                                      |\n")
            print("|Notes:                                                |\n")
            print("|      -If you input repeat letters it might give a    |\n")
            print("|       a false result. I did not feel like fixing this|\n")
            print("|       There is a reason this is Jank Wordle sorry <3 |\n")
            print("+------------------------------------------------------+\n")
    #Guessing the word
    wordsGuessed = []
    while (gameRunning):
        answerWord = ""
        wordIndex = 0
        userIndex = 0
        letterIn = False
        userInput = input("")
        currentDict = copy.deepcopy(wordDict[guessWord])
        
        #If the guessed word is correct
        if (userInput == guessWord):
            print("You are correct! The word was: " + guessWord)
            gameRunning = False
        
        #If number of letters != 4
        rightSize = True
        if (not len(userInput) == wordLength):
            print("Inputted word is not the right size. The size of the word is: "+ str(wordLength) + "\nTry again!\n")
            rightSize = False
        
        #If the guessed word is incorrect
        if (not userInput == guessWord and rightSize):
           
            print(currentDict)
            for userIndex, userLetter in enumerate(userInput):
                isIn = False
                isPos = False
                for guessIndex, guessLetter in enumerate(guessWord):            
                    #If the letter is in the word
                    if (userLetter == guessLetter and currentDict[guessLetter] > 0):
                        isIn = True
        
                        #If the letter is in the word AND in the right place
                        if (guessIndex == userIndex):
                            isPos = True
                        currentDict[guessLetter] -= 1
                        break

                #Printing the word   
                if (isIn and isPos):
                    answerWord += "[" + userLetter + "]"
                    
                elif (isIn):
                    answerWord += "(" + userLetter + ")"
                    
                else:
                    answerWord += "\"" + userLetter + "\""
            currentDict = wordDict[guessWord]
        print(answerWord)

        



    




    

if __name__ == "__main__":
     main()