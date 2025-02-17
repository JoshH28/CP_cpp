import matplotlib.pyplot as plt
import numpy as np

# Given test case data
N = 2289
cells = [
    (1700, 1083, 'W'),
    (528, 967, 'B'),
    (1789, 211, 'W'),
    (518, 1708, 'W'),
    (1036, 779, 'B'),
    (136, 657, 'B'),
    (759, 1497, 'B'),
    (902, 1309, 'B'),
    (1814, 712, 'B'),
    (936, 763, 'B')
]

# Create an empty grid
grid = np.zeros((N, N))

# Fill the grid based on the given cells
for r, c, color in cells:
    if color == 'W':
        grid[r-1, c-1] = 1  # White cell
    else:
        grid[r-1, c-1] = -1  # Black cell

# Plot the grid
plt.figure(figsize=(12, 12))
plt.imshow(grid, cmap='gray', origin='upper')

# Adding grid lines
plt.grid(which='both', color='black', linestyle='-', linewidth=0.5)
plt.xticks(np.arange(-0.5, N, 1), '')
plt.yticks(np.arange(-0.5, N, 1), '')

# Mark the specific cells for better visibility
for r, c, color in cells:
    plt.text(c-1, r-1, 'W' if color == 'W' else 'B', ha='center', va='center', color='red' if color == 'B' else 'blue')

plt.title('Grid Visualization')
plt.xlabel('Column')
plt.ylabel('Row')
plt.show()
