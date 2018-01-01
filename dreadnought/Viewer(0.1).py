import os, time
from datetime import date

NHB = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LYP = NHB.lower()
today = str(date.today())

SaveNHB = "recNHB" + today;
SaveLYP = "recLYP" + today;

while os.path.exists(SaveNHB):
	SaveNHB += "~"

while os.path.exists(SaveLYP):
	SaveLYP += "~"

os.system("mkdir " + SaveNHB)

os.system("mkdir " + SaveLYP)

totalTime = 300 * 60
recTime = 60

for i in xrange(totalTime / recTime):
	nowTime = time.localtime()
	timeString = "-" + str(nowTime.tm_hour) + 'h' + str(nowTime.tm_min) + "m" + str(nowTime.tm_sec) + "s";
	for a in NHB:
		nowFile = a + ".cpp"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveNHB + "/" + a + "-cpp"
			if not os.path.exists(Dir):
				os.system.mkdir(Dir)
			tmpFile = SaveNHB + "/" + a + "-cpp" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = nowFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
		nowFile = a + ".java"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveNHB + "/" + a + "-java"
			if not os.path.exists(Dir):
				os.system.mkdir(Dir)
			tmpFile = SaveNHB + "/" + a + "-java" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = nowFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
	for a in LYP:
		nowFile = a + ".cpp"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveLYP + "/" + a + "-cpp"
			if not os.path.exists(Dir):
				os.system.mkdir(Dir)
			tmpFile = SaveLYP + "/" + a + "-cpp" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = nowFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
		nowFile = a + ".java"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveLYP + "/" + a + "-java"
			if not os.path.exists(Dir):
				os.system.mkdir(Dir)
			tmpFile = SaveLYP + "/" + a + "-java" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = nowFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
	time.sleep(recTime)