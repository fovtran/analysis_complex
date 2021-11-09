import numpy as np


# WORKS
a = np.array([[3,-5,4], [1,-2,7], [6,-8,1]])
b = np.array([[7] ,[2], [0]])

x = np.linalg.solve(a, b)

print(x)
