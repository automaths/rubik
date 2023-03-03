# Import libraries
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
from random import random
 
# Change the Size of Graph using
# Figsize
fig = plt.figure(figsize=(10, 10))
 
# Generating a 3D sine wave
ax = plt.axes(projection='3d')
 
# Create axis
axes = [3,3,3]
 
# Create Data
data = np.ones(axes)
print(data)

# Control Tranperency
alpha = 1
 
# Control colour
colors = np.empty(axes + [4])
print(colors)

for i in range(3):
    for j in range(3):
        for k in range(3):
            colors[i][j][k] = [random(), random(), random(), alpha]
 
# colors[0] = [[1, 0, 0, alpha] , # red
#              [0, 1, 0, alpha],  # green
#              [0, 0, 1, alpha]]  # blue
# colors[1] = [[1, 0, 0, alpha] , # red
#              [0, 1, 0, alpha],  # green
#              [0, 0, 1, alpha]]  # blue
# colors[2] = [[1, 0, 0, alpha] , # red
#              [0, 1, 0, alpha],  # green
#              [0, 0, 1, alpha]]  # blue
print(colors)
# colors[3] = [1, 1, 0, alpha]  # yellow
# colors[4] = [1, 1, 1, alpha]  # grey
 
# turn off/on axis
plt.axis('off')
 
# Voxels is used to customizations of
# the sizes, positions and colors.
ax.voxels(data, facecolors=colors, edgecolors='grey')
plt.show()
