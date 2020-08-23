import sys
import csv

def main():
    # Command-Line Arguement Check
    while len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    
    # Opening csv file
    with open(sys.argv[1]) as csv_file:
        csv_reader = csv.reader(csv_file)
        # DNA Sequences we look for
        sequences = next(csv_reader)[1:]
    
    # Opening txt file
    with open(sys.argv[2]) as txt_file:
        txt_reader = txt_file.read()

    output = []
    # Iterate over all searched sequence
    for seq in sequences:
        count = 0
        runs = []
        for i in range(0, len(txt_reader)):
            # If current is seq 
            if seq == txt_reader[i:i + len(seq)]:
                count += 1
                # If next is not seq
                if seq != txt_reader[i + len(seq):i + (len(seq) * 2)]:
                    runs.append(count)
                    count = 0
        output.append(max(runs))

    # Printing the name
    with open(sys.argv[1], "r") as csv_file:
        csv_reader = csv.DictReader(csv_file)
        idx = 0
        for line in csv_reader:
            name_nums = []
            for value in line.items():
                name_nums.append(value[1])
            name = name_nums[0]
            name_nums.pop(0)
            for i in range(0, len(name_nums)):
                name_nums[i] = int(name_nums[i])
    
            if output == name_nums:
                print(name)
                exit(0)
            idx += 1
        print("No match")
main()
