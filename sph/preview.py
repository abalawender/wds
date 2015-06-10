import struct
import os
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as animation

f = open("run2.out", "rb")
h = f.readline()
n = struct.unpack( 'I', f.read(4) )[0]
print( "HEADER: ", h, " N: ", n )

i = 0

def data_gen():
    while f.tell() != os.fstat(f.fileno()).st_size:
        xdata.clear()
        ydata.clear()
        for i in range(n):
            x, y = struct.unpack( 'f', f.read(4) )[0], struct.unpack( 'f', f.read(4) )[0]
            rho = struct.unpack( 'f', f.read(4) )[0]
            #_ = f.read(4)
            xdata.append(x)
            ydata.append(y)
            print( "( %4.4f, %4.4f ) -> rho = %4.4f " % (x, y, rho ) )
            #_ = f.read( 12 * (n-1) ) # skip n-1 particles
        yield xdata, ydata

def run(data):
    global i
    xdata, ydata = data
    #xdata.append(x)
    #ydata.append(y)
    #line.set_data( xdata, ydata )
    line.set_data( xdata, ydata )
    #dupa = input("%i sane?" % i)
    i+=1
    return line,

fig, ax = plt.subplots()
line, = ax.plot([], [], 'bo', lw=2, markersize=28)
ax.set_ylim(0, 2)
ax.set_xlim(0, 2)
ax.grid()
xdata, ydata = [], []

ani = animation.FuncAnimation( fig, run, data_gen, blit=False, interval=0, repeat=True)
plt.show()
