'''
Problem 

Find the min number of swaps of adjacent characters it takes to create a pallindrome from a given string.

Algorithm

First check if making a pallindrome is possible. For even length string, a map of availableCharacters should be empty. 
For odd length strings, there should be one avaliableCharacter in the map after traversal

The  start with a start and end index. If string[start] == string[end], continue
Else search for string[end] from start till end. 
Search for string[start] from end till start. 
Calculate distance (start or end) - foundIndex
Swap the character with the least index.
s++ e--

'''

def swapChar(current,target):
	if(current<target):
		store = inputStringList[current]

		for i in range(current,target):
			inputStringList[i]=inputStringList[i+1]

		inputStringList[target]=store
	else:
		store = inputStringList[current]

		for i in range(current,target,-1):
			inputStringList[i]=inputStringList[i-1]

		inputStringList[target]=store		


#Input
inputString = "abcabc"

inputStringList = list(inputString)

#Is pallindrome possible
charMap = dict()
minSwaps=0

for i in range(0,len(inputString)):
	if(charMap.has_key(inputString[i])):
		charMap.pop(inputString[i])
	else:
		charMap[inputString[i]]=i

if(len(inputString)%2 == 0 and len(charMap.keys()) != 0):
	print "Pallindome not possible"
elif(len(inputString)%2 != 0):
	if(len(charMap.keys()) != 1):
		print "Pallindome not possible"
	else:
		#Bring lonely letter to center
		if(inputString[len(inputString)/2] !=  charMap.keys()[0]):
			swapChar(charMap[charMap.keys()[0]],len(inputString)/2)
			minSwaps+=abs((len(inputString)/2)-charMap[charMap.keys()[0]])


#Start swapping
s=0
e=len(inputStringList)-1

while(s<e):
	# print "S = "+str(s) 
	# print "E = "+str(e)
	# print

	if(inputStringList[s] != inputStringList[e]):
		leftDistance=None
		leftIndex=None
		for i in range(s+1,e):
			if(inputStringList[e] == inputStringList[i]):
				leftDistance=abs(i-s)
				leftIndex=i
				break

		rightDistance=None
		rightIndex=None
		for i in range(e-1,s,-1):
			if(inputStringList[s] == inputStringList[i]):
				rightDistance=abs(i-e)
				rightIndex=i
				break

		if(leftDistance < rightDistance):
			swapChar(leftIndex,s)
			minSwaps+=leftDistance
		else:
			swapChar(rightIndex,e)
			minSwaps+=rightDistance

	s+=1
	e-=1

print inputStringList
print minSwaps