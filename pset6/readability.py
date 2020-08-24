text = input("Text: ")

count_letters = 0
count_words = 1
count_sentences = 0

for i in range(0, len(text)):
    if (text[i] >= "a" and text[i] <= "z") or (text[i] >= "A" and text[i] <= "Z"):
        count_letters += 1
    elif text[i] == " ":
        count_words += 1
    elif text[i] == "." or text[i] == "?" or text[i] == "!":
        count_sentences += 1

L = (count_letters * 100) / count_words
S = (count_sentences * 100) / count_words

index = (0.0588 * L) - (0.296 * S) - 15.8
output = round(index)

if output > 16:
    print("Grade 16+")
elif output < 1:
    print("Before Grade 1")
else:
    print(f"Grade {output}")