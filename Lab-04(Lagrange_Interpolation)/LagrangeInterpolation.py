import matplotlib.pyplot as plt
import numpy as np

#Taking input from file:

def readfile(filename):
	coordinates = []
	with open(filename) as f:
		lines = f.readlines()
		for line in lines[1:]: 
			values = line.split()
			coordinate = (float(values[0]) ,
				 float(values[1]) )
			coordinates.append(coordinate)
	return coordinates
	
	
coordinates = readfile("data.txt")
X = [-7.0, -9.0, 0.0, 9.0, 8.0, 3.0, -3.0 ]
Y = [2.0, 8.0, 1.0, 9.0, 5.0, -3.0, -7.0]	
	
	
#Lagrange Part:
	
def lagrange(coordinates, x):
	n = len(coordinates)
	y = 0.0
	
	for i in range(n):
		fi = coordinates[i][1]
		prod = fi
		for j in range(n):
			if j !=i:
				xi = coordinates[i][0]
				xj = coordinates[j][0]
				prod = prod * ((x-xj)/(xi-xj))
		y+=prod
	return y
		


xs = np.arange(-10,10,0.1)
ys = []


for x in xs:
	ys.append(lagrange(coordinates, x))
	
	
plt.plot(xs, ys)
plt.plot(X,Y,'o')
plt.show()


#Newtons Part: 
	
def b(X, Y, r, l):
	if l==r:
		return Y[l]
	return ( b(X, Y, r, l+1) - b(X, Y, r-1, l) )/(X[r]-X[l])
	


def Newton(x):
	sum_ = 0.
	for i in range(len(X)):
		#print(i)
		mul = b(X, Y, i, 0)
		for j in range(i):
			mul *= (x-X[j])
		sum_ += mul
	return sum_		
		
		

x  = np.arange(-10, 10, 0.1)
y = Newton(x)


plt.plot(x, y)
plt.plot(X, Y, 'o')
plt.show()






