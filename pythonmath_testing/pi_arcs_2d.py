import numpy as np
import matplotlib.pyplot as plt

np.sqrt(10/8)
# 1.118033988749895

#plt.autoscale(enable=True)

fig = plt.figure()
ax = fig.add_subplot(111, polar=False)
ax.set_aspect('equal')
ax.grid(True)
ax1 = fig.add_subplot(312, polar=True)
ax1.set_aspect('equal')
ax1.grid(True)

A = np.linspace(0,4/8*np.pi,22);x = np.sin(A);y = np.cos(A)
ax.plot(x,y, '.--',color='red')
ax.annotate('1-1J', xy=(x[12],y[12]), xytext=(1,1), horizontalalignment='right', verticalalignment='top',)
AA = np.complex(x[12],y[12]) 
ax1.plot([0,AA.real],[0,AA.imag],marker='o')

A = np.linspace(4/8*np.pi,4/4*np.pi,22);x = np.sin(A);y = np.cos(A)
ax.plot(x,y, '.--',color='green')
ax.annotate('1+1J', xy=(x[11],y[11]), xytext=(1,-1), horizontalalignment='right', verticalalignment='bottom',)

A = np.linspace(4/4*np.pi,3/2*np.pi,22);x = np.sin(A);y = np.cos(A)
ax.plot(x,y, '.--',color='orange')
ax.annotate('-1+1J', xy=(x[11],y[11]), xytext=(-1, -1), horizontalalignment='left', verticalalignment='bottom',)

A = np.linspace(3/2*np.pi,2*np.pi,22);x = np.sin(A);y = np.cos(A)
ax.plot(x,y, '.--',color='magenta')
ax.annotate('-1-1J', xy=(x[11],y[11]), xytext=(-1,1), horizontalalignment='left', verticalalignment='top',)

plt.show()