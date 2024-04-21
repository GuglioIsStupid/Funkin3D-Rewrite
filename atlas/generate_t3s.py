""" rem prompt user for folder containing .png
set /p folder="Enter folder containing .png files: "

cd %folder%
rem get all files that are png (in a-z0-9)
rem create .t3s file following the format below:
rem --atlas -f rgba -z auto

rem 0.png
rem 1.png

set textdata=--atlas -f rgba -z auto

rem go through all files in folder/
for %%f in (*.png) do (
    echo %%f
    set textdata=%textdata% %%f
)

cd ..
echo %textdata% > %folder%.t3s """

import os, sys

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

def main():
    folder = input("Enter folder containing .png files: ")
    os.chdir(os.path.join(BASE_DIR, folder))
    textdata = "--atlas -f rgba -z auto\n"

    for file in os.listdir():
        if file.endswith(".png"):
            print(file)
            textdata += "\n" + folder + "/" + file

    os.chdir("..")
    with open(folder + ".t3s", "w") as f:
        f.write(textdata)
        
if __name__ == "__main__":
    main()