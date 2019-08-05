import matplotlib.pyplot as plt
import numpy as np

N=10000
theta = np.linspace(0, 10*np.pi, N)
r = np.sin(2.3*theta)**2 + np.cos(2.3*theta)**4

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1, projection='polar')
ax.set_ylim(0, 1)
ax.scatter(theta, r, s=1)

fig.suptitle('graph of sin(2.3x)^2 + cos(2.3x)^4 for x in [0,10pi]')

plt.savefig('107501006.png')