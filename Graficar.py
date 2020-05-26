import matplotlib.pyplot as plt

x,y = [],[]

for line in open('Grafica.txt','r'):
    values=[float(s) for s in line.split()]
    x.append(values[0])
    y.append(values[1])

plt.plot(x,y)
plt.show()