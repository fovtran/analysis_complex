# -*- coding: utf-8 -*-
#
import numpy as np

# Surface Area of a Cube = 6 a 2
# Surface Area of a Cube = 6 a 2
# Surface Area of a Sphere = 4 pi r 2
# Surface Area of a Cylinder = 2 Π r2 + 2 Π r h 
tube1_r = .3 # centimeters
tube1_h = 25.0 #centimeters
tube2_r = 1.1 # centimeters
tube2_h = 24.0 #centimeters
tube3_r = 2.25 # centimeters
tube3_h = 24.7 #centimeters
tube4_r = 3 # centimeters
tube4_h = 27.0 #centimeters
diameters = [0.3, 0.25, 0.25, 0.25]

area = lambda r, h: 2*(np.pi * r**2) + 2 * np.pi * r * h

tube1_area = area(tube1_r, tube1_h)
tube2_area = area(tube2_r, tube2_h)
tube3_area = area(tube3_r, tube3_h)
tube4_area = area(tube4_r, tube4_h)

print("Lamp tube (r=%.1f, h=%.1f) area is: %.3f square cm" % (tube1_r, tube1_h,tube1_area))
print("Tube 2 (r=%.1f, h=%.1f) area is: %.3f square cm" % (tube2_r, tube2_h,tube2_area))
print("Tube 3 (r=%.1f, h=%.1f) area is: %.3f square cm" % (tube3_r, tube3_h,tube3_area))
print("Tube 4 (r=%.1f, h=%.1f) area is: %.3f square cm" % (tube4_r, tube4_h,tube4_area))

# heat conduction
# Q/t = kA(T_h - T_c) / d
# Q heat transferred in time t
# k thermal conductivity of the barrier
# A = Area  T = temperature
# d = thickness of the barrier

# Two pipe problem
# Q = 2pik (T_a - T_b)  /  k/r1h1 + k/r2h2 + ln(r2/r1)

# heat per unit lenght
# Q = 2pi * r2 * h(0) * (T_a - T_b)  > h(0) unit lenght

# Overall heat transfer coefficient
# 1/h(0) = r2/r1*h1 + r2/k * ln(r2/r1) + 1/h_2

# Forced convection
# Q = hA(T_a - T_b)

# 1 Joules = 1watts * segundo

T = np.linspace(30,100,1)
Q = lambda k,T_a,T_b,r1,h1,r2,h2 : (2*np.pi* k * (T_a - T_b)) / (k/r1*h1) + (k/r2*h2) + np.log(r2/r1)
fc = lambda h,A,T_a,T_b: h*A*(T_a - T_b)
transfer = lambda h1,h2,k,r1,r2: (r2/r1*h1 + r2/k)  * np.log(r2/r1) + 1 /h2

air_heat = 0.001297
air_heat2= 1.4

# heat equations
h_0 = transfer(1,1,air_heat, tube1_r, tube4_r)
Q_t = lambda h, T_a, T_b: fc(h, A, T_a, T_b)


dx = 0.25

while(q_ < 800):
    q_=30
    s = []
    counter = 0
    for T in np.arange(0, 12, 1):
        ''' Time set '''
        for m in np.linspace(0,tube2_h, dx):
            '''Phonon position'''
            counter += 1
            q_ = Q(air_heat, 800, q_, tube2_r, tube2_h, tube4_r, tube4_h)
            s.insert(counter, "%.4f" % q_)
    
#tx = lambda self: [Q(air_heat, 800, self, tube2_r, tube2_h, tube4_r, tube4_h) for t in self]
#ht = [tx(n) for n in np.linspace(0,tube2_h, 0.25)]
print(s)

heat = fc(air_heat, tube1_area, 800, 30)
heat1 = fc(air_heat, tube1_area, 800, heat)
print("Forced convection output %.3f" % heat)
print("Final Forced convection output %.3f" % heat1)

heat2 = Q(air_heat, 800, 30, tube2_r, tube2_h, tube4_r, tube4_h)
heat3 = Q(air_heat, 800, heat2, tube2_r, tube2_h, tube4_r, tube4_h)
heat4 = Q(air_heat, 800, heat3, tube2_r, tube2_h, tube4_r, tube4_h)
heat5 = Q(air_heat, 800, heat4, tube2_r, tube2_h, tube4_r, tube4_h)
print("Cylindric Forced Convection output %.3f" % heat2)
print("Final Cylindric Forced Convection output %.3f" % heat3)
print("Final Final Cylindric Forced Convection output %.3f" % heat4)
print("Final Final Final Cylindric Forced Convection output %.3f" % heat5)






