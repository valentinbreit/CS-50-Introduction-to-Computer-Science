import csv
import sys


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    filenameD = sys.argv[1]  # This will be Databases

    filenameS = sys.argv[2]  # This will be Sequences

    # I need in memory the values of databases that the user input
    
    with open(filenameD, "r") as DataFile:
        reader = csv.reader(DataFile)
        AllSequences = next(reader)[1:]
    
        # I need in memory the values of the text 
        with open(filenameS, "r") as TextFile:
            Sequences = TextFile.read() 
            Act = [GetMax(Sequences, Substring) for Substring in AllSequences]
        
        FindMatch(reader, Act)
        
        
def FindMatch(reader, Act):
    for Line in reader:
        Person = Line[0]
        # Converting all strings values into integers (besides names)
        Val = [int(V) for V in Line[1:]]  # Necesito saber como abarcar todas las keys - los nombres
        # Compare all Values with the values in the sequence
        if Val == Act:
            print(Person)
            return
    print("No match")
        
        
def GetMax(Sequences, Substring):
    # I generate a list inicializating all the spaces i need in 0
    length = len(Sequences)
    BlankList = [0] * length
    
    # I loop for every place in the string
    for i in range(length - len(Substring), -1, -1):  # I iterate from the last place in te string to the position 0, doing i-1
        
        if Sequences[i: i + len(Substring)] == Substring:
            # Assign to 1 the number in the place of the array
            if (i + len(Substring)) > (length - 1):
                BlankList[i] = 1
            else:  # Otherwise i add 1 in te next place (1 + previous value)
                BlankList[i] = 1 + BlankList[i + len(Substring)]
    return max(BlankList)
    

if __name__ == "__main__":
    main()