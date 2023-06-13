@echo off

cls

for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "date=%dt:~0,4%_%dt:~4,2%_%dt:~6,2%"

ROBOCOPY "src" "target\debug\%date%\source\src" /mir /nfl /ndl /njh /njs /np /ns /nc > nul

rgbasm  -L -o target/debug/%date%/Test.o  src/entry.asm
rgblink -o    target/debug/%date%/Test.gb target/debug/%date%/Test.o
rgbfix        target/debug/%date%/Test.gb -c -i GBTS -j -k 4F -l 0x33 -m 0x1B -r 0x02 -s -t "gb test" -v -p 0x00
