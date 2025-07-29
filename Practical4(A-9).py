# Function to take matrix input
def take_matrix(row, column): 
    matrix = [] 
    for i in range(row): 
        a = [] 
        for j in range(column): 
            element = int(input(f"Enter element row-wise [{i}][{j}]: ")) 
            a.append(element) 
        matrix.append(a) 
    return matrix 

# Transpose of a matrix
def mat_trans(): 
    row = int(input("Enter number of rows in matrix: ")) 
    column = int(input("Enter number of columns in matrix: ")) 
    print("\n\tMATRIX A") 
    A = take_matrix(row, column) 
    result = [] 
    for i in range(column):   # Transpose flips row and column
        a = [] 
        for j in range(row): 
            a.append(A[j][i]) 
        result.append(a) 
    return result 

# Addition of matrices
def mat_add(): 
    row = int(input("Enter number of rows in matrices: ")) 
    column = int(input("Enter number of columns in matrices: ")) 
    print("\n\tMATRIX A") 
    A = take_matrix(row, column) 
    print("\n\tMATRIX B") 
    B = take_matrix(row, column) 
    result = [] 
    for i in range(row): 
        a = [] 
        for j in range(column): 
            a.append(A[i][j] + B[i][j]) 
        result.append(a) 
    return result 

# Subtraction of matrices
def mat_sub(): 
    row = int(input("Enter number of rows in matrices: ")) 
    column = int(input("Enter number of columns in matrices: ")) 
    print("\n\tMATRIX A") 
    A = take_matrix(row, column) 
    print("\n\tMATRIX B") 
    B = take_matrix(row, column) 
    result = [] 
    for i in range(row): 
        a = [] 
        for j in range(column): 
            a.append(A[i][j] - B[i][j]) 
        result.append(a) 
    return result 

# Multiplication of matrices
def mat_multi(): 
    row = int(input("Enter number of rows in MATRIX A: ")) 
    column = int(input("Enter number of columns in MATRIX A: ")) 
    print("\n\tMATRIX A") 
    A = take_matrix(row, column) 
    
    print(f"\nSince A has {column} columns, B must have {column} rows.")
    x = int(input("Enter number of columns in MATRIX B: ")) 
    print("\n\tMATRIX B") 
    B = take_matrix(column, x) 

    result = [] 
    for i in range(row): 
        collector = [] 
        for j in range(x): 
            sum_product = 0 
            for k in range(column): 
                sum_product += A[i][k] * B[k][j] 
            collector.append(sum_product) 
        result.append(collector) 
    return result 

# Menu-driven program
while True: 
    print("\n\t*** OPERATIONS ON MATRICES ***\n") 
    print("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n") 
    ch = int(input("Enter your choice for matrix operation: ")) 
    print("") 
    
    if ch == 1: 
        W = mat_add() 
        print("\nThe addition of matrices A and B is: ") 
        for a in W: 
            print(a) 

    elif ch == 2: 
        X = mat_sub() 
        print("\nThe subtraction of matrices A and B is: ") 
        for a in X: 
            print(a) 

    elif ch == 3: 
        Y = mat_multi() 
        print("\nThe multiplication of matrices A and B is: ") 
        for a in Y: 
            print(a) 

    elif ch == 4: 
        Z = mat_trans() 
        print("\nThe transpose of matrix A is: ") 
        for a in Z: 
            print(a) 

    elif ch == 5: 
        print("Exiting... Thank you!")
        break 

    else: 
        print("### YOU ENTERED WRONG CHOICE ###\n") 
