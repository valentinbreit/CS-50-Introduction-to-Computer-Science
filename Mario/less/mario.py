from cs50 import get_int


def main():
    # I ask the user for a number
    Heigth = get_int("Give a number between 1 and 8 for the heigth of the pyramid: ")
    
    # I recursivly call the main function to be sure the user promp the needed information
    if (Heigth > 0) and (Heigth < 9):
        PrintPyramid(Heigth)
    else:
        main()
        

def PrintPyramid(Heigth):
    # I declared variables
    Blank = (Heigth - 1)
    
    # While loop
    for L in range(0, Heigth, 1):
        # The blank spaces nedeed in every loop
        for b in range(Blank):
            print(" ", end="")
        # The blocks spaces nedeed in every loop
        for i in range(0, (L+1), 1):
            print("#", end="")
        print("")
        Blank -= 1

        
if __name__ == "__main__":
    main()