import numpy as np
import matplotlib.pyplot as plt

n = 20
p = 0.5
num_sequences = 10000

x = np.arange(1, n+1)
sequences = np.random.binomial(n, p, size=(num_sequences, n))
s_values = np.sum(sequences, axis=1)

plt.hist(s_values, bins=np.arange(n,1), density=True)
plt.title(f"Binomial distribution: n = {n}, p = {p}")
plt.xlabel("Number of successes (s)")
plt.ylabel("Frequency")
plt.show()