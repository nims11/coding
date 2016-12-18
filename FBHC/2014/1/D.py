import copy, fractions
from collections import deque

MAX = 150

def precompute():
	global GCD_TABLE
	GCD_TABLE = (MAX + 1) * [0]
	for i in range(1, MAX + 1):
		GCD_TABLE[i] = set()
		for j in range(i, MAX):
			if fractions.gcd(i, j) != 1:
				GCD_TABLE[i].add(j)

def solve():
	global t_ages, t_sum, min_sum, all_possible
	all_possible = set()
	for i in range(1, MAX + 1):
		all_possible.add(i)
	t_sum = 0
	min_sum = 100000000
	t_ages = N * [0]
	recurse(0)

def recurse(index):
	global t_ages, t_sum, min_sum, all_possible

	left = N - index
	if left == 0:
		if t_sum < min_sum:
			min_sum = t_sum
		return
	deleted_lower = set()

	lower_bound = new_ages[index]

	if index > 0:
		lower_bound = max(t_ages[index - 1], new_ages[index])

	if lower_bound > 1:
		for number in sorted(all_possible):
			if number >= lower_bound:
				break
			deleted_lower.add(number)
			all_possible.remove(number)
		i = 0
		lowest_sum = 0
		for number in sorted(all_possible):
			lowest_sum += number
			i += 1
			if i == left:
				break

	else:
		lowest_sum = left

	if t_sum + lowest_sum >= min_sum:
		all_possible = all_possible.union(deleted_lower)
		return
	i = 0
	for number in sorted(all_possible):
		i += 1
		if i == 2 and left == 1:
			break
		deleted = set()
		for number_2 in all_possible.intersection(GCD_TABLE[number]):
			deleted.add(number_2)
			all_possible.remove(number_2)

		t_ages[index] = number
		t_sum += number

		recurse(index + 1)

		t_sum -= number
		all_possible = all_possible.union(deleted)
	all_possible = all_possible.union(deleted_lower)

precompute()
f = open("alz.in", "r")

T = int(f.readline())

for t in range(T):
	temp = f.readline()
	temp = list(temp.split(' '))
	for i in range(len(temp)):
		temp[i] = int(temp[i])

	N = temp[0]
	K = temp[1]

	temp = f.readline()
	ages = list(temp.split(' '))
	for i in range(len(ages)):
		ages[i] = int(ages[i])
	ages = sorted(ages)

	lessThanEqualToK = True
	for age in ages:
		if age > K:
			lessThanEqualToK = False
	answer = 0
	if ages[0] == 0 and lessThanEqualToK:
		answer = (len(ages) - 1) * K - sum(ages)
	else:
		new_ages = copy.deepcopy(ages)
		for i in range(len(new_ages)):
			new_ages[i] = max(new_ages[i], 1)
			age = new_ages[i]
			if age % K != 0:
				age = age - age % K + K
			new_ages[i] = age / K

		solve()

		answer = min_sum * K - sum(ages)
	print "Case", "#" + str(t + 1) + ":", answer


