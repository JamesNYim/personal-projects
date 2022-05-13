import random
def main():
    wordBank = ["teas", "poop", "milk", "boba", "cute", "home", "game", "rice"]
    wordLength = 4
    gameRunning = False
    letterFound = False
    
    #Starting the game
    while (not gameRunning):
        userInput = input("\n\n\n\n\nWelcome to jank wordle! Type \"Ready\" when ready to start\nOr Type \"help\" for rules and how to play\n")
        if (userInput == "Ready"):
            print("Guess the 4 letter word!\n")
            guessWord = random.choice(wordBank)
            #guessWord = wordBank[3]
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
            
            for userIndex, userLetter in enumerate(userInput):
                letterFound = False
                for guessIndex, guessLetter in enumerate(guessWord):                    
                    #If the letter is in the word AND in the right place
                    if (userLetter == guessLetter and guessIndex == userIndex and not letterFound):
                        letterIn = True
                        answerWord += "[" + userLetter + "]"
                        letterFound = True
                   
                    #If the letter is in the word but NOT in the right place
                    elif (userLetter == guessLetter and not guessIndex == userIndex and not letterFound):
                        letterIn = True
                        answerWord += "(" + userLetter + ")"
                        letterFound = True
                
                #If the letter isn't in the word
                if (not letterIn):
                        answerWord += "\"" + userLetter + "\""
                
                letterIn = False
        print(answerWord)

        



    




    

if __name__ == "__main__":
     main()