import numpy as np
import matplotlib.pyplot as plt
# func = np.poly1d(np.array([2.42857, -1.17605, 0.545455, -0.040404]).astype(float))

x = np.arange(0, 10, 1)
y = -0.040404*x*x*x + 0.545455*x*x - 1.17605*x + 2.42857
y1 = x
plt.plot(x, y)
plt.plot(x, y1)

plt.xlabel('x')
plt.ylabel('y(x)')
plt.show()

# x = np.array([1, 2, 3, 4, 5, 6, 7, 8])
# y = np.array([2, 1, 4, 3, 6, 5, 8, 7])
# z1 = np.polyfit(x, y, 3)
# p1 = np.poly1d(z1)
# print(p1)
# yvals=p1(x)
# plot1=plt.plot(x, y, '*',label='original values')
# plot2=plt.plot(x, yvals, 'r',label='polyfit values')
# plt.xlabel('x axis')
# plt.ylabel('y axis')
# plt.legend(loc=4) 
# plt.title('polyfitting')
# plt.show()
# plt.savefig('p1.png')

