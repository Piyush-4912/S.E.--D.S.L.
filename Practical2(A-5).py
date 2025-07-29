# Write a Python program to compute different functions for string operations.
# PALINDROME
def palindrome(): 
    s1 = input("Enter your string: ") 
    s2 = s1[::-1] 
    print("Reversed string:", s2) 
    if s1 == s2: 
        print("Your string is a palindrome") 
    else: 
        print("Your string is not a palindrome") 


# LONGEST SUBSTRING (word)
def long_len(): 
    s3 = input("Enter your string: ") 
    words = s3.split()
    if words:
        longest = max(words, key=len) 
        print("Longest word is:", longest) 
        print("Length:", len(longest))
    else:
        print("No words found.")


# CHARACTER FREQUENCY
def char_freq(): 
    s4 = input("Enter your string: ") 
    character = input("Enter the character to find frequency of: ")  
    print("Character =", character) 
    b = s4.count(character) 
    print("Frequency =", b) 


# FREQUENCY OF EACH WORD
def word_freq(): 
    s5 = input("Enter your string: ") 
    s5_words = s5.split() 
    unique_words = [] 
    for word in s5_words: 
        if word not in unique_words: 
            unique_words.append(word) 
    print("Frequency of each word in your string:")  
    for word in unique_words: 
        print(f"Frequency of '{word}' is: {s5_words.count(word)}") 


# OCCURRENCE OF SUBSTRING IN MAIN STRING
def occur_substr(): 
    str1 = input("Enter your string: ") 
    str1_sub = input("Enter the substring to find in your string: ") 
    list_str1 = str1.split(" ") 
    for i in range(len(list_str1)): 
        if str1_sub == list_str1[i]: 
            print("Substring found at word index:", i) 
            break
    else:
        print("Substring not found.")


# Uncomment below to test all functions
# palindrome()
# long_len()
# char_freq()
# word_freq()
# occur_substr()
