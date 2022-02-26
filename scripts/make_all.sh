echo -en '\E[47;31m'"\033[1mBuild scq\033[0m\n"
tput sgr0

cd ..
mkdir -p build
cd build
cmake ..
make
