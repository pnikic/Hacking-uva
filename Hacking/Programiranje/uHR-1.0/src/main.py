# -*- coding: utf-8 -*-
# Copyright (C) 2017 Patrick Nikic <pnikic@mathos.hr>

import urllib2
import json
from datetime import datetime
from time import localtime, strftime, time

t = localtime()
today = str(t[2]).rjust(2, '0') + "-" + str(t[1]).rjust(2, '0') + "-" + \
str(t[0]) + " " + str(t[3]).rjust(2, '0') + ":" + str(t[4]).rjust(2, '0')

#******************* PREFERENCES ***********************
rTime = 86400			# Report type
nSub = 100				# Number of subs per user
fileName = today		# Custom output file name
#*******************************************************
out = open("../" + fileName, 'w')

def fetchProblems():
	call = urllib2.urlopen("http://uhunt.felix-halim.net/api/p")
	info = json.load(call)

	archive = open("archive.txt", 'w');
	for line in info:
		archive.write(str(line[0]) + " " + str(line[1]) + " " + line[2].encode('utf8') + "\n")
	archive.close()

def findProblem(idnum):
	for line in archiveL:
		problem = line.split(" ", 2)

		if idnum == int(problem[0]):
			return '{0: <7}'.format(str(problem[1]) + ":")  + '{0: <33}'.format(problem[2].rstrip())
	
	fetchProblems()		# ...if problem name was not found
	return findProblem(idnum)

List = [(831136,"Mislav (mblazev)"), (851541, "Matej (Tantor)"),
		(862206, "Patrick (rickpa)"), (862009, "Antonio (ajovanovic)"),
		(863145, "Renato (renatodean)"), (848200, "Iwan (josipoviciwan)"),
		(889120, "Marko (marko_t)"), (894240, "Bartol (gvremena)"),
		(862152, "Tomislav (tmijosev)")]
	
Verdict = {10 : "Submission error", 15 : "Can't be judged",
		20 : "In queue", 30 : "Compile error", 35 : "Restricted function",
		40 : "Runtime error", 45 : "Output limit", 50 : "Time limit",
		60 : "Memory limit", 70 : "Wrong answer", 80 : "PresentationE",
		90 : "Accepted"}


try:
	archive = open("archive.txt", 'r');
except IOError:
	fetchProblems()
	archive = open("archive.txt", 'r');
archiveL = list(archive)
head = "Problem\t\t\t\t\tVerdict\t\tTime\n"
fmt = "{Problem:s}{Verdict:s}\t{Time:s}\n"
Res = []

for user in List:
	response = urllib2.urlopen("http://uhunt.felix-halim.net/api/subs-user-last/" + str(user[0]) + "/" + str(nSub))
	data = json.load(response)
	res = user[1] + ":\n" + head
	cnt = 0
	solved = []
		
	for sub in reversed(data['subs']):
		t = datetime.fromtimestamp(float(sub[4]))
		if (time() - float(sub[4]) < rTime):
			res += fmt.format(Problem = findProblem(sub[1]), Verdict = Verdict[int(sub[2])], Time = str(t))
			if sub[2] == 90 and sub[1] not in solved:
				solved.append(sub[1])
				cnt += 1
	
	res += "\t" * 5 + "ΣAC =  " + str(cnt) + "\n"
	Res.append((cnt, res + "\n"))

Res.sort(reverse = True)
for line in Res:
	out.write(line[1])

out.close()
archive.close()
