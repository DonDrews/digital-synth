import math

for x in range(0, 256):
	print(int((math.sin((x * math.pi) / 128) + 1) * 32768))
