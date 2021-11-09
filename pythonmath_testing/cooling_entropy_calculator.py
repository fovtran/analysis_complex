# -*- coding: utf-8 -*-
import math
import time
import __future__
import numpy as np
import matplotlib.pyplot as plt

# Examples
""" 9164 Watts will need 1450 CFM at 20 F ΔT: 9164 = .316 x 1450 x 20 """
claudius = 4.1868   # Joules
C = 80   # Celsius
O = 150E6   # Moles
P_w = 130  # CPU Watts
t_s = 30   # Seconds
work = lambda w, t: w * t  #  P_w = E_j / t_s

cputime = 0
force = []

def force_calculator():
    for cputime in range(t_s):
        F = (1.8) * C + 32   # Farenheits from C
        T = (F + 459.67) / 1.8  #Kelvins from F
        S = T * math.log(O)   # Maxwell Bolzman entropy
        J_e = T / claudius

        print ("Celsius %.f " % C)
        print ("Farenheits %.f " % F)
        print("Kelvins %.f " % T)
        print("Entropy %.f " % S)
        print("Joules %.f " % J_e)
        dU = work(J_e, cputime)
        force.append(dU)

force_calculator()

fig1 = plt.figure()

l, = plt.plot([], [], 'r-')
#plt.xlim(0, 1)
#plt.ylim(0, 1)
plt.xlabel('x')
plt.title('test')
fig2 = plt.figure()
plt.show()
