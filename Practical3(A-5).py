# Write program to determine saddle point of matrix.
# Saddle Point in a Matrix

row = int(input("Enter the number of rows: ")) 
column = int(input("Enter the number of columns: ")) 
matrix = [] 
f = 0 

print("Enter the elements of the matrix row-wise:")

# Taking matrix input
for i in range(row): 
    a = [] 
    for j in range(column): 
        a.append(int(input(f"Element at ({i},{j}): "))) 
    matrix.append(a) 

# Displaying the matrix
print("\nThe Matrix is:")
for i in range(row): 
    for j in range(column): 
        print(matrix[i][j], end="\t") 
    print()

# Finding Saddle Point
for i in range(row): 
    min_row = matrix[i][0] 
    col_ind = 0 

    # Find minimum element in the current row
    for j in range(1, column): 
        if min_row > matrix[i][j]: 
            min_row = matrix[i][j] 
            col_ind = j 

    # Check if the found min_row is the maximum in its column
    is_saddle = True 
    for k in range(row): 
        if matrix[k][col_ind] > min_row: 
            is_saddle = False 
            break 

    if is_saddle: 
        print("\nSaddle Point found:", min_row) 
        f = 1 

if f == 0: 
    print("\nSaddle Point is not available in your matrix.")

*************************************OUTPUT******************************** 
Enter the number of rows:2 
Enter the number of columns:2 
Enter the Elements of Matrix Row wise: 
1 
3 
4 
2 
1, 3, 
4, 2, 
Saddle Point is Not Available in Your Matrix 
Enter the number of rows:3 
Enter the number of columns:3 
Enter the Elements of Matrix Row wise: 
1 
2 
3 
4 
5 
6 
7 
8 
9 
1, 2, 3, 
4, 5, 6, 
7, 8, 9, 
Value of Saddle Point 7 


Saddle Point Theory   https://www.geeksforgeeks.org/engineering-mathematics/saddle-points/
