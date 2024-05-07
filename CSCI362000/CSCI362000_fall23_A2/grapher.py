#This line imports the Matplotlib library, specifically the pyplot module, and assigns it the alias plt.
import matplotlib.pyplot as plt
#This line imports the patches module from Matplotlib and assigns it the alias patches. It is used to create and manipulate graphical patches, in this case, rectangles.
import matplotlib.patches as patches

#These lines initialize empty lists to store information about the x-coordinates, y-coordinates, widths, and heights of rectangles.
x_coords = []
y_coords = []
widths = []
heights = []

# This line opens a text file named 'rectangles.txt' in read ('r') mode using a context manager (with statement). 
with open('rectangles.txt', 'r') as file:
#This line starts a loop that iterates through each line in the opened text file.   
    for line in file:
#This line splits each line of the file into parts using the comma and space (', ') as the delimiter. It creates a list of strings called parts.
        parts = line.split(', ')
#This line extracts the x and y coordinates from the first and second parts of the line, respectively. 
#It first splits the relevant part using '(' and ')' as delimiters, converts the resulting strings to float values, and assigns them to the variables x and y.
        x, y = float(parts[0].split('(')[1]), float(parts[1].split(')')[0])
#This line extracts the width of the rectangle from the third part of the line, converting it to a float and assigning it to the variable width.
        width = float(parts[2].split(': ')[1])
#This line extracts the height of the rectangle from the fourth part of the line, converting it to a float and assigning it to the variable height.
        height = float(parts[3].split(': ')[1])
#These lines add the extracted values of x, y, width, and height to their respective lists.
        x_coords.append(x)
        y_coords.append(y)
        widths.append(width)
        heights.append(height)

# This line creates a Matplotlib figure (fig) and an axis (ax) for plotting.
fig, ax = plt.subplots()

#This line starts a loop that iterates through the x-coordinates, y-coordinates, widths, and heights of the rectangles using zip() to iterate over corresponding elements simultaneousl
for x, y, width, height in zip(x_coords, y_coords, widths, heights):
#This line creates a Matplotlib rectangle patch (rect) with the specified parameters, including its position, size, line width, edge color, and face color.
# The rectangle is created based on the extracted information from the file
    rect = patches.Rectangle((x - width / 2, y - height / 2), width, height, linewidth=1, edgecolor='blue', facecolor='none')
#This line adds the created rectangle (rect) to the Matplotlib axis (ax).
    ax.add_patch(rect)

#These lines set labels for the x-axis, y-axis, and the title of the plot, respectively.
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.title('Rectangles on the Graph')

# These lines set the limits of the x and y axes based on the minimum and maximum values of the x-coordinates, y-coordinates, widths, and heights of the rectangles. 
# This ensures that all rectangles are visible in the plot.
plt.xlim(min(x_coords) - max(widths), max(x_coords) + max(widths))
plt.ylim(min(y_coords) - max(heights), max(y_coords) + max(heights))

#This line enables the grid in the plot by setting it to True.
plt.grid(True)
#This line displays the plot with the rectangles, labels, and grid on the screen.
plt.show()

