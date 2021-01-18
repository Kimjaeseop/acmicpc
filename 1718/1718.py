import sys
#input = sys.stdin.readline

sys.stdin = open('input_1.txt', 'r')

text = []
key = []

input_text = input()
input_key = input()

# l 12 n 15
text.extend(ord(i) for i in input_text)
key.extend(ord(i) for i in input_key)

while len(text) > len(key):
	key += key

for i, j in zip(text, key):
	print(chr(i-j+97-1) if i-j > 0 else chr(i-j+26+97-1) if i != 32 else chr(32), end = '')

