# PRACTICAL NO : 01 
# Write a Python Program to store marks scored in subject “Fundamentals Of Data Structure” by N  students in the class. 
# Piyush Sunil Nikam 
# Main Program 
print("********************MARKSHEET*******************") 
#MAXIMUM MARKS 
def Max(marks): 
  max=0 
  count=0 
  for i in range(len(marks)): 
    if max<marks[i]: 
      max=marks[i] 
    return max 
#MINIMUM MARKS 
def Min(marks): 
  min=0 
  count=0 
  for a in range(len(marks)): 
    if marks[a] != -1: 
      min=marks[a] 
      break 
  for b in range(a+1, len(marks)): 
    if marks[b] !=-1 and marks[b]<min: 
      min=marks[b] 
    return min 
#AVERAGE 
def avg(marks): 
  addition=0 
  count=0 
  for i in range(len(marks)): 
    if marks[i] !=-1: 
      addition +=marks[i] 
      count +=1 
      avg=addition/count 
  print("Total Marks of Student",addition) 
  print("Average Marks of Students",avg) 
#ABSENT STUDENT 
def Absent(marks): 
  count=0 
  for i in range(len(marks)):
    if marks[i] == 0: 
      count +=1 
    return (count) 
#HIGHEST FREQUENCY 
def highfreq(marks): 
  i=0 
  max=0 
  print(" Marks----->Frequency Count") 
  for c in marks: 
    if marks.index(c) == i: 
      print(c,"----->",marks.count(c)) 
    if marks.count(c)>max: 
      max=marks.count(c) 
      mark=c 
    i+=1 
    return (marks,max) 
    n=int(input('Enter no. of Student in class:')) 
    marks=[] 
for i in range(n): 
 mrks=int(input('Enter Marks of Student' + str(i+1)+':')) 
 marks.append(mrks) 
while(10): 
  print("######## M E N U ########") 
  print("1.Average of class\n" 
  "2.Maximum Marks\n" 
  "3.Minimum Marks \n" 
  "4.Absent Students \n" 
  "5.Highest frequency of marks\n" 
  "6.Exit") 
  ch=int(input("Enter Your Choice for Grading:")) 
  if ch==1: 
    (avg(marks)) 
  elif ch==2: 
    print("Maximum marks is:",Max(marks)) 
  elif ch==3: 
    print("Minimum marks is:",Min(marks)) 
  elif ch==4: 
    print("Count of Absent Student:",Absent(marks)) 
  elif ch==5: 
    marks,count=highfreq(marks) 
    print("Highest Frequency of marks:",highfreq(marks)) 
  elif ch==6: 
    exit() 
  else: 
    print("YOU ENTER THE WRONG CHOICE") 
    break 




#*************************************OUTPUT******************************** 
********************MARKSHEET******************* 
Enter no. of Student in class:5 
Enter Marks of Student1:98 Enter Marks of Student2:25 Enter Marks of Student3:0 Enter Marks of Student4:54 Enter Marks of Student5:54 ######## M E N U ######## 1.Average of class 
2.Maximum Marks 
3.Minimum Marks  
4.Absent Students  
5.Highest frequency of marks 6.Exit 
Enter Your Choice for Grading:1 Total Marks of Student 231 Average Marks of Students 46.2 ######## M E N U ######## 1.Average of class 
2.Maximum Marks 
3.Minimum Marks  
4.Absent Students  
5.Highest frequency of marks 6.Exit 
Enter Your Choice for Grading:2 Maximum marks is: 98 
######## M E N U ######## 1.Average of class 
2.Maximum Marks 
3.Minimum Marks  
4.Absent Students  
5.Highest frequency of marks 6.Exit 
Enter Your Choice for Grading:3 Minimum marks is: 0 
######## M E N U ######## 1.Average of class 
2.Maximum Marks 
3.Minimum Marks  
4.Absent Students  
5.Highest frequency of marks 6.Exit 
Enter Your Choice for Grading:4 Count of Absent Student: 1 ######## M E N U ######## 1.Average of class 
2.Maximum Marks 
3.Minimum Marks  
4.Absent Students  
5.Highest frequency of marks 6.Exit 
Enter Your Choice for Grading:5 Marks----->Frequency Count 98 -----> 1 
25 -----> 1
MET’s Institute Of Engineering, NASHIK. Prepared By:  
SE Computer Engineering 2019 Pattern Data Structure Lab(DSL) 
0 -----> 1 
