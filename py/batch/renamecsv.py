# -*- coding: utf-8 -*- #

import re
import os
import shutil
import sys

from prefdef import prefcode

args = sys.argv
if len(args) != 4:
  print("Usage: python renamecsv.py <Prefecturename> <InputDir> <OutDir>")
  exit()

if __name__ == '__main__':

  # Setting
  prefname = "Kagoshima"        # modify this

  prefID = prefcode[args[2]]    # for outputfile
  indir = args[3]				# read directory
  outdir = args[4] + "bf_" + prefID		# write directory
  csvfile = r"^\d\d_.*\.csv$"	# read ??_*.csv
  mapIDFormat = r"^\d\d"        # extract ??

  # Process
  files = os.listdir(indir)
  for filename in files:
	if re.match(csvfile, filename):
	  if os.path.exists(outdir) is False:
		os.mkdir(outdir)

	  # Match
	  match = re.search(mapIDFormat, filename)
	  mapID = match.group(0)

	  # Copy
	  outputfile = "bf_" + prefID + mapID + ".csv"
	  shutil.copyfile(indir + "/" + filename, outdir + "/" + outputfile)
	  print filename + " Copied."

  print "All Copied Success."
