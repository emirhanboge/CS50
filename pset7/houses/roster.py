from sys import argv
from cs50 import SQL

# Check for Command-Line Arguement Mistakes
if len(argv) < 2:
    print("Usage: roster.py house_name")
    exit(1)
# Open the database
db = SQL("sqlite:///students.db")
# List people in alpabetical order
people = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])
# Printing
for i in people:
    if i['middle'] != None:
        print(i["first"] + " " + i["middle"] + " "+ i["last"] + ", " + "born " + str(i["birth"]))
        
    else:
        print(i["first"] + " " +  i["last"] + ", " + "born " + str(i["birth"]))
        