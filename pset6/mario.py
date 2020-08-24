
# Getting the input from the user
height = int(input("Height: "))

# Invalid input check
while height < 1 or height > 8:
    height = int(input("Height: "))

# Creating Blocks
for i in range(height):
    # Print first blanks
    print(" " * (height - i - 1), end="")
    # Print first blocks
    print("#" * (i + 1), end="")
    # Print mid blanks
    print(" ", end="")
    print(" ", end="")
    # Print last blocks
    print("#" * (i + 1))
