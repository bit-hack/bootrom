.\VC152\CL.EXE /AT /G2 /Gs /Gx /c /Zl *.cpp
.\VC152\ML.EXE /AT /c *.asm 
.\VC152\LINK.EXE /TINY /NODEFAULTLIBRARYSEARCH StartPoint.obj bootmain.obj cdisplay.obj cstring.obj, out.com,,,,

mkdir output
move /Y *.com output
move /Y *.map output

mkdir temp
move /Y *.obj temp
