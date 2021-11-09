import numpy as np
import numpy.linalg as npl


# WORKS
# RANK == rows
#
a = np.array([[3, -5, 4, 2], [1, -2, 7, 5], [6, -8, 1, 6]])
a_rank = a.ndim  # number of dimensions, axes  ->>> row-wise ops    (AXOS ZERP)
a_features = a.shape[1]  # number of rows      ->>> column-wise ops (AXIS ONE)
a_size = a.size

a.sum(axis=0)  # column-wise sum
a.sum(axis=1)   # row-wise sum

a.max()
a.min()
1/a.max() *a # matrix of coefs up to ONE


b = np.array([[7] ,[2], [0]])

x = npl.matrix_rank(a)

print(x)

# Polynomial of type x^2 + 2x + 3
c = np.poly1d([1,2,3])
c(0.5) # evaluate at 0.5
c.r # roots
c.c # coeficients
c.order
c = np.poly(c.r) # Find coefficients from roots
