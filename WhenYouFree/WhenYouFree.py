
def main():
    print("What dates are you free this month?")
    userInput = input("")
    userInput = userInput.split()
    datesFree = [0] * 31

    for date in userInput:
        intD = int(date)
        datesFree[intD] += 1
    
    currentDay = 1
    for numOfFreePpl in datesFree:
        print("Date: " + str(currentDay) + " | " + "# of free ppl: " + str(numOfFreePpl))
        currentDay += 1


if __name__ == "__main__":
     main()

     #need to fix 0-30 problem instead of 1-31