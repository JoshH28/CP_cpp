str1 = list(input())
str2 = list(input())

def check():	
	if len(str1) != len(str2):
		return "No"
	elif str1 == str2:
		return "Yes"
	for i in range(len(str1)-1):
		gay = str1[i]
		bruh = str1[i+1]
		str1[i] = bruh
		str1[i+1] = gay
		if str1 == str2:
			return "Yes"
		str1[i] = gay
		str1[i+1] = bruh
	return "No"
print(check())


	