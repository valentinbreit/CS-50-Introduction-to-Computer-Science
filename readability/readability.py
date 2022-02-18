from cs50 import get_string


def main():
    # I ask the user some string input
    Phrase = get_string("Type something here: ")
    
    # Call some procedure that  gives the grade
    Grade = Quantity(Phrase)

    PrintGradeClasification(round(Grade))
    
    
def Quantity(Phrase):
    lengt = len(Phrase)
    # I need the exact words
    Words = QuantityWords(Phrase, lengt)
    # I need the exact Letters
    Letters = QuantityLetters(Phrase, lengt)
    # I need the exact sentences
    Sentences = QuantitySentences(Phrase, lengt)
    # I return te exact Grade of the Paragraph
    G = (0.0588 * (100 * (Letters / Words)) - 0.296 * (100 * (Sentences / Words)) - 15.8)
    return G
    
    
def QuantityLetters(Phrase, lengt):
    # I delcare the local variables
    i = 0
    L = 0
    # I need iterate for every alphabetic char in the paragraph
    while i != lengt:
        # If char = alphabetic, then add 1
        if (Phrase[i].isalpha()):
            L += 1
        # Add to mover foward the string
        i += 1
    return L
            
            
def QuantityWords(Phrase, lengt):
    # I delcare the local variables
    i = 0
    W = 1
    # I need iterate for every spaces in the paragraph
    while i != lengt:
        # If there is a spaces that meas thats a new word
        if (Phrase[i] == ' '):
            W += 1
        # Add to move foward the string
        i += 1
    return W


def QuantitySentences(Phrase, lengt):
    # I declare the local variables
    i = 0
    S = 0
    while i != lengt:
        # If there is a: . ! or ? == end of the sentences
        if ((Phrase[i] == '.') or (Phrase[i] == '!') or (Phrase[i] == '?')):
            S += 1
        # Add to move foward the string
        i += 1
    return S
    
    
def PrintGradeClasification(Grade):
    
    if (Grade >= 16):
        print("Grade 16+")
    elif (Grade <= 1):
        print("Before Grade 1")
    else:
        print(f"Grade {Grade}")
    
    
if __name__ == "__main__":
    main()