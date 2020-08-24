from cs50 import SQL
from sys import argv
from csv import reader

# Opening the database
db = SQL("sqlite:///students.db")
# Command-Line Arguement Error Check
if len(argv) < 2:
    print("Usage: import.py characters.csv")
    exit(1)
# Open csv file
with open(argv[1]) as csv_file:
    csv_reader = reader(csv_file)
    # Copying the info
    for i in csv_reader:
        if i[0] == "name":
            continue
        # Splitting name
        name = i[0].split()
        if len(name) == 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                      name[0], name[1], name[2], i[1], i[2])
        elif len(name) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                      name[0], None, name[1], i[1], i[2])
