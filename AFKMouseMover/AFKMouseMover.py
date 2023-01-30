import pyautogui as pygui
import time
import random

def main():
	mouseCoords = pygui.position()
	timeAFK = 0;
	afkTimer = 5
	xScreen = 3024
	yScreen = 1964

	while True:
		print("mouseCoords: " + str(mouseCoords))
		print("pos: " + str(pygui.position()))
		#If the mouse cursor hasnt moved
		if pygui.position() == mouseCoords:
			
			timeAFK += 1
		
		#If the mouse has moved
		else:
			timeAFK = 0
			mouseCoords = pygui.position()

		#Checking if AFK
		if timeAFK > afkTimer:
			xCoord = random.randint(0, xScreen)
			yCoord = random.randint(0, yScreen)
			pygui.moveTo(xCoord, yCoord)
			mouseCoords = pygui.position
		
		print("timeAFK: " + str(timeAFK))
		time.sleep(3)



if __name__ == "__main__":
     main()