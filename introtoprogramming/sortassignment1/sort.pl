## This is a shebang line which tells the computer that I want Perl to execute this program
#!/usr/bin/perl

##This line creates an empty array called @numbers to store the input values
my @numbers;
##This line iterates from 0 to 9 using $i as a loop variable
for my $i (0..9) {
##This line will prompt the user to enter a value
    print "Enter your value: ";
##This line will read the of input from the user and store it in $inputnums. The <STDIN> is and input stream where data from the user will 
##be sent to and read by later in the program
    my $inputnums = <STDIN>;
##This line will remove the newline character from the input so the numbers will all be on the same line
    chomp($inputnums);
##This line adds the input value to the @numbers array
    push @numbers, $inputnums;
}
##This line prints the unsorted list of numbers
print "Unsorted list: @numbers\n";
##This line iterates through the elements of @numbers using $i as an index
for my $i (0..$#numbers) {
##This lin iterates through the remaining numbers using $j as an index
    for my $j ($i+1..$#numbers) {
##This line checks if the current element is greater than the next element
        if ($numbers[$i] > $numbers[$j]) {
##This line will change places of number i if it is greater than number j 
            ($numbers[$i], $numbers[$j]) = ($numbers[$j], $numbers[$i]);
        }
    }
}
##This line will print the sorted list of numbers
print "Sorted List: @numbers\n";

