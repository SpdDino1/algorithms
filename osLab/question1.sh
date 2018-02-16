echo File Path\?...
read filePath

if [ -r $filePath ]
	then
		echo Writeable
else
	echo Not Writeable
fi