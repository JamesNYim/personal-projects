from datetime import datetime
import random

def main():
    print("Heyyo! Got work but wanna get zooted?")
    #Getting user time frame
    minTime = int(input("What is the minimum amount of minutes you want to work?"))
    print("\n")
    maxTime = int(input("What is the maximum amount of minutes you want to work?"))
    print("\n")

    
    #Randomly picking a amount of time to work
    random.seed();
    timeToFinish = random.randint(minTime, maxTime)
    str(timeToFinish)
    print("\n")
    print("You should finish working in and get high in", timeToFinish, "minutes") #My bestie bestfriend gave me this  
  
    

    
if __name__ == "__main__":
     main()