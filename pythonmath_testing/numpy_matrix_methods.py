from __future__ import division
from numpy.testing import assert_, assert_raises
from numpy import array, float64, sum, arange, ma, where, indices, ogrid, zeros, Nan

a = arange(0,40)
A = a.reshape(10,4)  # Y, X

print(A)

#print(A[0, 2:4])   # row 0 columns 2-4
#print(A[3:, 3:])
#print(A[:, 2]) # only column 2
#print(A[2::2, ::2])  # even rows since 2 from column

a_ = ma.zeros(40)
A_ = a_.reshape(10,4)
assert A.all() == A_.all()
ma.masked_where( A_ != A , A_)

where( A == 36 )[0]  # row value
where( A == 36 )[1]  # column
A[9,0] = 0.  # Y,  X  -> row, column
A[ where( (A >5) & (A <26) )[0], where( (A >5) & (A <26) )[1] ]
x, y = ogrid[:3, :4]

a = arange(0,40)
A = a.reshape(10,4)  # Y, X
where(A < 4, A, -1)
indices(A.shape)

B = zeros([5,5])
y= indices(B.shape)[0]
x= indices(B.shape)[1]

b = arange(0,40)
B = b.reshape(10,4)  # Y, X
row= B.shape[0]
col= B.shape[1]
for r in arange(0,row):
	for c in arange(0,col):
		if c>0:
			prev = B[r,c-1]
		if c<col:
			post = B[r,c+1]
		val = B[r,c]
		if r>0:
			up = B[r-1,c]
		if r<row:
			down = B[r+1,c]

step = 2
for r in arange(0, row, step):
	for c in arange(0, col, step):
		mat = B[r:r+step, c:c+step]


import scipy.ndimage
x = np.arange(9).reshape(3,3)

print 'Original array:'
print x

print 'Resampled by a factor of 2 with nearest interpolation:'
print scipy.ndimage.zoom(x, 2, order=0)


print 'Resampled by a factor of 2 with bilinear interpolation:'
print scipy.ndimage.zoom(x, 2, order=1)


print 'Resampled by a factor of 2 with cubic interpolation:'
print scipy.ndimage.zoom(x, 2, order=3)


import numpy as np

image = np.arange(12).reshape((4, 3))
mask = np.array([[0,0,0],[0,1,0],[1,0,0],[0,0,0]])
i, j = np.where(mask)

indices = np.meshgrid(np.arange(min(i), max(i) + 1), np.arange(min(j), max(j) + 1), indexing='ij')

# 50ms
i, j = np.where(mask)
indices = np.meshgrid(np.arange(min(i), max(i) + 1),
              np.arange(min(j), max(j) + 1),
              indexing='ij')
sub_image = image[indices]


# 5ms
where = np.array(np.where(mask))

x1, y1 = np.amin(where, axis=1)
x2, y2 = np.amax(where, axis=1)
sub_image = image[x1:x2, y1:y2]
