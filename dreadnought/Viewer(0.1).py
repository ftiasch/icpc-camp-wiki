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

LogNHB = "NHB.log"
LogLYP = "LYP.log"

for i in xrange(totalTime / recTime):
	nowTime = time.localtime()
	timeString = "-" + str(nowTime.tm_hour) + 'h' + str(nowTime.tm_min) + "m" + str(nowTime.tm_sec) + "s";

	LogNHBFile = open(SaveNHB + "/" + LogNHB,"a");
	for a in NHB:
		nowFile = a + ".cpp"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveNHB + "/" + a + "-cpp"
			if not os.path.exists(Dir):
				os.system("mkdir "+Dir)
			tmpFile = SaveNHB + "/" + a + "-cpp" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
				LogNHBFile.write(nowFile + " created at " + timeString + "\n")
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = tmpFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
					LogNHBFile.write(nowFile + " changed at " + timeString + "\n")
		nowFile = a + ".java"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveNHB + "/" + a + "-java"
			if not os.path.exists(Dir):
				os.system("mkdir "+Dir)
			tmpFile = SaveNHB + "/" + a + "-java" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
				LogNHBFile.write(nowFile + " created at " + timeString + "\n")
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = tmpFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
					LogNHBFile.write(nowFile + " changed at " + timeString + "\n")
	LogNHBFile.close()

	LogLYPFile = open(SaveLYP + "/" + LogLYP,"a");
	for a in LYP:
		nowFile = a + ".cpp"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveLYP + "/" + a + "-cpp"
			if not os.path.exists(Dir):
				os.system("mkdir "+Dir)
			tmpFile = SaveLYP + "/" + a + "-cpp" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
				LogLYPFile.write(nowFile + " created at " + timeString + "\n")
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = tmpFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
					LogLYPFile.write(nowFile + " changed at " + timeString + "\n")
		nowFile = a + ".java"
		if os.path.exists(nowFile):
			if os.path.isdir(nowFile):
				continue
			Dir = SaveLYP + "/" + a + "-java"
			if not os.path.exists(Dir):
				os.system("mkdir "+Dir)
			tmpFile = SaveLYP + "/" + a + "-java" + "/tmp"
			flag = False
			if not os.path.exists(tmpFile):
				os.system("cp " + nowFile + " " + tmpFile)
				os.system("cp " + nowFile + " " + tmpFile + timeString)
				LogLYPFile.write(nowFile + " created at " + timeString + "\n")
			else:
				nowFileObject = open(nowFile, "r")
				nowFileContext = nowFileObject.readlines()
				nowFileObject.close()
				tmpFileObject = open(tmpFile, "r")
				tmpFileContext = tmpFileObject.readlines()
				tmpFileObject.close()
				if tmpFileContext != nowFileContext:
					os.system("cp " + nowFile + " " + tmpFile)
					os.system("cp " + nowFile + " " + tmpFile + timeString)
					LogLYPFile.write(nowFile + " changed at " + timeString + "\n")
	LogLYPFile.close();

	print i
	time.sleep(recTime)
