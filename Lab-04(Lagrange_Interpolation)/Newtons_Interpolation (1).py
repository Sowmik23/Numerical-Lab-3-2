import random as rn
from numpy import *
import matplotlib.pyplot as plt

def f(points, x):
	res = 0.
	for i in range(len(points)):
		
		pro = 1.0
		for j in range(len(points)):
			if i != j:
				pro = pro * (x - points[j][0])/(points[i][0]-points[j][0])
		res = res + pro*points[i][1]
	
	
	
	return res
	

def proterm(i, value, x):  
    pro = 1;  
    for j in range(i):  
        pro = pro * (value - points[i][j]);  
    return pro; 


def dividedDiffTable(x, y, n): 
	for i in range(1, n):  
    	for j in range(n - i):  
        y[j][i] = ((y[j][i - 1] - y[j + 1][i - 1]) /
                                 (x[j] - x[i + j])); 
return y;



points = [
	[-7.0, 2.0],
	[-9.0, 8.0],
	[0.0, 1.0],
	[9.0 ,9.0],
	[8.0 ,5.0],
	[3.0, -3.0],
	[-3.0, -7.0]
	]

x = linspace(-20., 20., 200)
y = f(points, x)


X = linspace(-50, 50)
plt.plot(x, y)
plt.plot(x, x*0)
plt.plot(X*0, X)
for i in range(len(points)):
	plt.plot(points[i][0], points[i][1], 'o')
plt.ylim(-10,10)
plt.xlim(-10,10)
plt.show()
