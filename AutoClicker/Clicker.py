import keyboard
import mouse
#import pyautogui

#
# import pyscreenshot as ImageGrab

def main():
    print("poop")
    isRunning = False
    while True:
        if (keyboard.is_pressed("s")):
            isRunning = True
        while isRunning:
            if (keyboard.is_pressed("a")):
                isRunning = False
            mouse.click("left") 

if __name__ == "__main__":
     main()

