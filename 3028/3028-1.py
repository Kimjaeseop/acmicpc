string = input()

x = '1'
y = '2'
z = '3'

for i in string:
	if i == 'A':
		x,y = y,x
	elif i == 'B':
		y,z = z,y
	else:
		x,z = z,x

if x == '1':
	print(1)
elif y == '1':
	print(2)
else:
	print(3)

