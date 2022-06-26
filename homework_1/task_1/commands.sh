echo "Number of lines in data.dat: "
wc -l data.dat
echo "Number of lines containing either 'dolor' or 'dalor' in them:  "
((grep "dolor" data.dat) || (grep "dalor" data.dat)) | wc -l
echo "Number of words in data.dat: "
wc -w data.dat 
echo "Number of words in data.dat beginning with 'mol': "
grep -o 'mol\S*' data.dat | wc -l
