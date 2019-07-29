function runProgram(){
echo -ne "1.getHTML\n2.getIMAGES\n3.getOther\n88.exit\nplease select : "
read pp
case $pp in
1)
echo "input your link : "
read u
curl -o aaa.html $u
./regex -f aaa.html html
;;
2)
echo "input your link : "
read u
curl -o aaa.html $u
./regex -f aaa.html img
;;
3)
echo "input your link : "
read u
echo "input your pattern : "
read patternStr
echo "input your removeString : "
read reStr
curl -o aaa.html $u
./regex -f aaa.html patternStr reStr;;
88)
exit 0;;
*)runProgram;;
esac
}

buildProgram(){
clone
cd cpp_Regex
echo "build tools"
g++ -std=c++11 regex.cpp -o regex
echo "run program !"
./regex -h
sleep 3
clear
runProgram
}

clone(){
echo "start clone src"
git clone https://github.com/SorryMyLife/cpp_Regex.git
}

linux(){
echo "1.debian\n2.redhat\nplease select : "
read d
case $d in
1)
apt -y install git curl gcc g++
;;
2)
yum -y install git curl gcc gcc-c++
;;
*)
linux
;;
esac
buildProgram
}

termux(){
apt -y install git clang curl 
buildProgram
}

menu(){
echo -ne "1.termux\n2.linux\nplease select : "
read ys
echo "intstall !"
case $ys in
1)
termux
;;
2)
linux
;;
*)
echo "bye bye !"
exit 0
;;
esac
}
menu
