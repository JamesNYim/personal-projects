import random
import copy
def main():
    
    #Word stuff
    
    ##Change these if you want to customize the words
    wordBank = ["teas", "poop", "milk", "boba", "cute", "home", "game", "rice"]
    wordLength = 4
    
    #Creating a hashtable for each word in the word bank for the amount of times each letter appears
    #We do this so that we know when we have finished checking for that letter
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
               
    #Starting the game
    gameRunning = False
    while (not gameRunning):
        userInput = input("\n\n\n\n\nWelcome to jank wordle! Type \"Ready\" when ready to start\nOr Type \"help\" for rules and how to play\n")
        if (userInput == "Ready"):
            print("Guess the " + str(wordLength) + " letter word!\n")
            guessWord = random.choice(wordBank)
            gameRunning = True
        
        #Printing out help
        if (userInput == "help"):
            print("How to play Jank Wordle\n")
            print("\n")
            print("+-------------------= How to play =--------------------+")
            print("|                                                      |")
            print("|Guessing the Word                                     |")
            print("|                                                      |")
            print("|Type in a " + str(wordLength) + " letter word                               |")
            print("|                                                      |")
            print("|() Means that it is in the word                       |")
            print("|[] Means that it is in the word AND in the right place|")
            print("|\"\" means that the letter isnt in the word             |")
            print("|                                                      |")
            print("|Notes:                                                |")
            print("+------------------------------------------------------+")
    
    #Guessing the word
    while (gameRunning):
        answerWord = ""
        userInput = input("")
        currentDict = copy.deepcopy(wordDict[guessWord]) #copying the number of each letter for the word to guess
        
        #If the guessed word is correct
        if (userInput == guessWord):
            print("You are correct! The word was: " + guessWord)
            gameRunning = False
        
        #If number of letters != length of word to guess
        rightSize = True
        if (not len(userInput) == wordLength):
            print("Inputted word is not the right size. The size of the word is: "+ str(wordLength) + "\nTry again!\n")
            rightSize = False
        
        #If the guessed word is incorrect
        if (not userInput == guessWord and rightSize):
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
                        currentDict[guessLetter] -= 1 #We have checked that letter and do not need to check again
                        break

                #Printing the word   
                if (isIn and isPos): #If the letter is in the right position AND in word
                    answerWord += "[" + userLetter + "]"
                    
                elif (isIn): #If the letter is the word but not in the right position
                    answerWord += "(" + userLetter + ")"
                    
                else: #If the letter isn't in the word
                    answerWord += "\"" + userLetter + "\""
            currentDict = wordDict[guessWord] #Resetting the check for next attempt
        print(answerWord)

if __name__ == "__main__":
     main()