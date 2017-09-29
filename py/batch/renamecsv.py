# -*- coding: utf-8 -*- #
import re
import os
import shutil

from prefdef import prefcode

if __name__ == '__main__':

  # Setting
  prefID = prefcode["Kumamoto"] # for outputfile
  indir = "csvdir"				# read directory
  outdir = "bf_" + prefID		# write directory
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
