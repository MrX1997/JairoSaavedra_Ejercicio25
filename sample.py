import numpy as np 
import matplotlib.pylab as plt

data=np.genfromtxt('sample.dat')

N_array=data[:-3]
N=data[-3]
mu=data[-2]
sigma=data[-1]
def ND(x,mu,sigma):
	return (np.exp(-(x-mu)**2.0 / 2.0*sigma**2.0)/(sigma*(2.0*np.pi )**0.5 ))
ii=np.argmin(N_array)
oo=np.argmax(N_array)

x=np.linspace(N_array[ii],N_array[oo],1000)
f=ND(x,mu,sigma)
plt.hist(N_array,bins=100,density=True,label='Histograma')
plt.plot(x,f,label='Curva analitica')
plt.legend()
plt.title('Distribucion Normal')
plt.savefig('sample.pdf')


