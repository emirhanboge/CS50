while True:
    owed_cash = float(input("Enter: "))
    if owed_cash >= 0:
        break

cent = round(owed_cash * 100)

quarter = cent // 25
dime = (cent % 25) // 10
nickel = ((cent % 25) % 10) // 5
pennie = ((cent % 25) % 10) % 5

output = round(quarter + dime + nickel + pennie)
print(output)