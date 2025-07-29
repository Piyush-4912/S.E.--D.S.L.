#Sorting of an array using insertion and shell sort 
# Function to perform Insertion Sort
def insertionsort(arr):
    arr = arr.copy()  # Copy the list to avoid modifying the original
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0...i-1], that are greater than key, one position ahead
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  # Place the key at the correct position
    return arr

# Function to perform Shell Sort
def shellsort(percent, n):
    percent = percent.copy()  # Work on a copy to preserve the original list
    interval = n // 2  # Initial gap size
    while interval > 0:
        for i in range(interval, n):
            temp = percent[i]
            j = i
            # Shift elements until correct position for temp is found
            while j >= interval and percent[j - interval] > temp:
                percent[j] = percent[j - interval]
                j -= interval
            percent[j] = temp  # Place temp at its sorted position
        interval //= 2  # Reduce the gap
    return percent

# Function to display top five scores
def display(percent):
    print("Top Five Scores Are:")
    top = sorted(percent)[-5:]  # Get last 5 elements from sorted list (highest scores)
    for score in reversed(top):  # Reverse to print in descending order
        print(score)

# ---------------- MAIN PROGRAM ----------------

# Input number of students
n = int(input("Enter number of students: "))
percent = []

# Input percentages for all students
for i in range(n):
    mks = float(input(f"Enter percentage of student {i+1}: "))
    percent.append(mks)

# Menu-driven loop
while True:
    print("\n\t***** Sorting Menu *****")
    print("1. Insertion Sort")
    print("2. Top Five Scores (Current Data)")
    print("3. Shell Sort")
    print("4. Top Five Scores (Current Data)")
    print("5. Exit")
    
    ch = int(input("Enter your choice: "))  # User selects an option
    
    if ch == 1:
        sorted_list = insertionsort(percent)  # Perform insertion sort
        print("Result of Insertion Sort:")
        for mark in sorted_list:
            print(mark)
    
    elif ch == 2:
        display(percent)  # Display top 5 scores from current list
    
    elif ch == 3:
        sorted_list = shellsort(percent, n)  # Perform shell sort
        print("Result of Shell Sort:")
        for mark in sorted_list:
            print(mark)
    
    elif ch == 4:
        display(percent)  # Again display top 5
    
    elif ch == 5:
        print("Exiting program.")  # Exit condition
        break
    
    else:
        print("Invalid choice. Please try again.")  # For wrong menu input
