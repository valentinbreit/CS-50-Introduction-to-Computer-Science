from cs50 import get_float


def main():
    # I ask the user the number of change
    Dollars = get_float("How manny change do you have to give: ")

    Change = Dollars*100

    Cents = int(Change)
    if Dollars > 0:
        GiveChange(Cents)
    else:
        main()


def GiveChange(Cents):
    # Declare variables
    TotalCoins = 0

    # While the changes isnt 0 loop
    while (25 <= Cents):
        Cents = Cents - 25
        TotalCoins += 1
    while (10 <= Cents):
        Cents = Cents - 10
        TotalCoins += 1
    while (5 <= Cents):
        Cents = Cents - 5
        TotalCoins += 1
    while (1 <= Cents):
        Cents = Cents - 1
        TotalCoins += 1
        
    # Print every coin used
    print(f'Total coins used: {TotalCoins}')


if __name__ == "__main__":
    main()