##This line initializes an empty list called numbers to store input values
numbers = [] 
##This line iterates from 0 to 9 using i as a loop variable
for i in range(0,10): 
##This line will prompt the user to enter a value and store it in inputnums variable
    inputnums = input("Enter your value: ") 
##This line will convert 'inputnums' to an int and add it to the numbers list
    numbers.append(int(inputnums))
##This line will print the unsorted list of numbers
print ("Unsorted list:",numbers, "\n")
##This line will iterate through the indices of the numbers list using i
for i in range (len(numbers)):
##This line will iterate through the remaining elements using j
    for j in range(i + 1, len(numbers)):
##This line will compare the number at index i with the element at index j
        if numbers[i] > numbers[j]:
##This line will change places of number i if it is greater than number j 
           numbers[i], numbers[j] = numbers[j], numbers[i]
##This line will print the sorted list of numbers.
print ("Sorted List:" ,numbers,"\n")
