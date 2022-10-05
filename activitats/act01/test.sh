#!/bin/sh
echo "Testing RMSF app.."
echo "Creating dummy files and directories."
touch testFile1.txt
touch testFile2.txt
mkdir testFolder
touch ./testFolder/testFile3.c
ls -la
echo "Created 3 dummy files and 1 folder." 
echo "Removing files.."
rmsf testFilel.txt testFile2.txt
rmsf testFolder 
echo "Removed!"
ls -la
cd $HOME/.trash
echo "Showing trash folder..."
ls -la