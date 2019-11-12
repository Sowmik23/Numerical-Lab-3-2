import matplotlib.pyplot as plt
import numpy as np


def b(X, Y, r, l):
	if l==r:
		return Y[l]
	return ( b(X, Y, r, l+1) - b(X, Y, r-1, l) )/(X[r]-X[l])
	


def f(x):
	sum_ = 0.
	for i in range(len(X)):
		#print(i)
		mul = b(X, Y, i, 0)
		for j in range(i):
			mul *= (x-X[j])
		sum_ += mul
	return sum_
	
	
X = [-7.0, -9.0, 0.0, 9.0, 8.0, 3.0, -3.0 ]
Y = [2.0, 8.0, 1.0, 9.0, 5.0, -3.0, -7.0]



x  = np.arange(-10, 10, 0.1)
y = f(x)


plt.plot(x, y)
plt.plot(X, Y, 'o')
plt.show()


