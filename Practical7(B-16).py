#Write a python code to perform Quick Sort.
# Function for accepting the percentage of the students
def input_percentage():
    perc = []
    students = int(input("Enter the number of students: "))
    for i in range(students):
        perc.append(int(input(f"Enter the percentage of student {i + 1}: ")))
    return perc

# Function to display the percentage of students
def print_percentage(perc):
    print("Percentages of students:")
    for i in range(len(perc)):
        print(perc[i])

# Partition function used in Quick Sort
def percentage_partition(perc, start, end):
    pivot = perc[start]  # Choosing the first element as pivot
    lower_bound = start + 1
    upper_bound = end

    while True:
        # Move lower_bound right while elements are <= pivot
        while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
            lower_bound += 1
        # Move upper_bound left while elements are >= pivot
        while lower_bound <= upper_bound and perc[upper_bound] >= pivot:
            upper_bound -= 1
        # If bounds crossed, break the loop
        if lower_bound <= upper_bound:
            # Swap elements at lower_bound and upper_bound
            perc[lower_bound], perc[upper_bound] = perc[upper_bound], perc[lower_bound]
        else:
            break

    # Swap pivot with element at upper_bound to place pivot correctly
    perc[start], perc[upper_bound] = perc[upper_bound], perc[start]
    return upper_bound  # Return final pivot index

# Recursive Quick Sort function
def Quick_Sort(perc, start, end):
    if start < end:
        partition = percentage_partition(perc, start, end)
        Quick_Sort(perc, start, partition - 1)
        Quick_Sort(perc, partition + 1, end)
    return perc

# Function to display top five percentages
def display_top_five(perc):
    print("Top Five Percentages are:")
    if len(perc) == 0:
        print("No data available.")
        return
    # Ensure we get only available top scores if < 5
    start = len(perc) - 1
    stop = max(len(perc) - 6, -1)
    for i in range(start, stop, -1):
        print(perc[i])

# ---------------- MAIN MENU ----------------

unsorted_percentage = []
sorted_percentage = []

while True:
    print("\n\n############### M E N U ###############")
    print("1. Accept the Percentages of Students")
    print("2. Display the Percentages of Students")
    print("3. Perform Quick Sort on the Data")
    print("4. Display Top Five Scores")
    print("5. Exit")

    ch = int(input("\n\tEnter your choice: "))

    if ch == 1:
        unsorted_percentage = input_percentage()

    elif ch == 2:
        if len(unsorted_percentage) == 0:
            print("No data to display. Please enter student percentages first.")
        else:
            print_percentage(unsorted_percentage)

    elif ch == 3:
        if len(unsorted_percentage) == 0:
            print("Please enter student percentages first.")
        else:
            print("\nPercentages after performing Quick Sort:")
            sorted_percentage = Quick_Sort(unsorted_percentage.copy(), 0, len(unsorted_percentage) - 1)
            print_percentage(sorted_percentage)

    elif ch == 4:
        if len(sorted_percentage) == 0:
            print("Please sort the data first using Quick Sort.")
        else:
            display_top_five(sorted_percentage)

    elif ch == 5:
        print("!!!!! YOUR PROGRAM TERMINATED SUCCESSFULLY !!!!!")
        break

    else:
        print("!!! YOU ENTERED WRONG CHOICE !!!")
