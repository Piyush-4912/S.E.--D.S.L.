#Sorting of an array using selection and bubble sort..
# SELECTION SORT
def Selection_Sort(marks, n): 
    for i in range(len(marks)): 
        min_idx = i 
        for j in range(i + 1, len(marks)): 
            if marks[min_idx] > marks[j]: 
                min_idx = j 
        marks[i], marks[min_idx] = marks[min_idx], marks[i] 
    print("\nMarks after performing Selection Sort:") 
    for mark in marks: 
        print(mark)

# BUBBLE SORT
def Bubble_Sort(marks, n): 
    for i in range(n - 1): 
        for j in range(0, n - i - 1): 
            if marks[j] > marks[j + 1]: 
                marks[j], marks[j + 1] = marks[j + 1], marks[j] 
    print("\nMarks after performing Bubble Sort:") 
    for mark in marks: 
        print(mark)

# DISPLAY TOP 5
def top_five_marks(marks, n): 
    sorted_marks = sorted(marks)  # sort in ascending
    top_five = sorted_marks[-5:]  # last 5 marks
    top_five.reverse()  # descending order
    print("\nTop 5 Students are:")
    for mark in top_five:
        print(mark)

# MAIN PROGRAM
marks = [] 
n = int(input("Enter number of students: ")) 
print("Enter marks for", n, "students:")

for i in range(n): 
    ele = int(input(f"Percentage of Student {i+1}: ")) 
    marks.append(ele) 

print("\nOriginal Marks List:")
print(marks)

# MENU
while True: 
    print("\n\n############ MENU ############") 
    print("1. Sort using Selection Sort") 
    print("2. Display Top Five (via Selection Sort)") 
    print("3. Sort using Bubble Sort") 
    print("4. Display Top Five (via Bubble Sort)") 
    print("5. Exit") 

    ch = int(input("\nEnter your choice: ")) 

    if ch == 1: 
        Selection_Sort(marks, n) 
    elif ch == 2: 
        top_five_marks(marks, n) 
    elif ch == 3: 
        Bubble_Sort(marks, n) 
    elif ch == 4: 
        top_five_marks(marks, n) 
    elif ch == 5: 
        print("!!! Program Terminated Successfully !!!") 
        break 
    else: 
        print("!!! Invalid Choice !!!")
