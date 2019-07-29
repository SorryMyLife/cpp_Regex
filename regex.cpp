#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <vector>

class Mange{
public:
std::fstream f;
std::string tmp = "" , res = "" , data = "";

public : std::string readFile(std::string path){
	res = "";tmp = "";
	f.open(path,std::ios::in);
	while(getline(f,tmp)){
		res.append(tmp);
		res.append("\n");
	}
	f.close();
return res;
}

public : std::vector<std::string> getMatchData(std::string src , std::string reg , std::string removeString){
		std::regex st_re(reg);
		std::smatch m;
		std::vector<std::string> v;
		tmp = "";
		while(std::regex_search(src,m,st_re)){
			for(std::string d : m){
				v.push_back(replaceAll(d,removeString,""));
			}
		src = m.suffix().str();
}
return v;
}

public : std::string replaceAll(std::string src , std::string oldString , std::string newString){
	std::string::size_type pos(0);
	while((pos = src.find(oldString)) != std::string::npos){
		src.replace(pos,oldString.length(),newString);
	}
return src;
}

public : void printHTML(std::string filePath){
	data = readFile(filePath);
	for(std::string d : getMatchData(data , "href=\"(.+?\\.(h|ht|htm|html|sht|shtm|shtml)\")", "href=\"")){
		std::cout << d << std::endl;
	}
}

public : void printImage(std::string filePath){
	data = readFile(filePath);
	for(std::string d : getMatchData(data , "src=\"(.+?\\.(jp|jpg|jpeg|png|gif)\")", "src=\"")){
		std::cout << d << std::endl;
	}
}

public : void printHELP(char *ar[]){
std::cout << "Usage: "<< ar[0] << " [OPTION]\n"<<std::endl;
std::cout <<"\t--printHTML|--HTML|HTML|--html|html : print all html url\n\t--printIMG|-IMG|IMG|--img|img : print all image url\n\t-f : select file path\n\t--help|-help|-h : print help\n\n" << std::endl;
std::cout <<"\t" << ar[0] << " -f file Patter removeString\n" <<std::endl;
std::cout <<"\t" << ar[0] << " -f file --printHTML\n" <<std::endl;
std::cout <<"\t" << ar[0] << " -f file --printIMG\n" <<std::endl;

}
};

void check(char *ar[]){
Mange m;
std::string opt = ar[1];
if("-f" == opt){
	std::string fopt = ar[2];
	if(fopt != ""){
		std::string opt2 = ar[3];
		if("--printHTML" == opt2 ||"html" == opt2||"--html" == opt2||"HTML" == opt2 || "--HTML" == opt2){
			m.printHTML(fopt);
		}else if("--printIMG" == opt2 ||"IMG" == opt2||"--IMG" == opt2||"--img" == opt2||"img" == opt2){
			m.printImage(fopt);
		}else{
			if(opt2 != ""){
				std::string opt3 = ar[4];
				if(opt3 != ""){
					std::string data = m.readFile(fopt);
					for(std::string d : m.getMatchData(data , opt2, opt3)){
						std::cout << d << std::endl;
					}
				}else{
					m.printHELP(ar);
				}
			}else{
				m.printHELP(ar);
			}
		}
	}else{
		m.printHELP(ar);
	}
//ttt
}else if("--help" == opt || "-help" == opt || "-h" == opt){
//std::cout << "this help " <<std::endl;
m.printHELP(ar);

}
else{
std::cout << "invalid : " << ar[1]<<std::endl;
}
}

int main(int argc , char *argv[]){
if(argc < 2){
std::cout << "Usage: "<< argv[0] << " [OPTION]"<<std::endl;
std::cout << "Try '" << argv[0] << " --help' for more options."<<std::endl;
}else{
check(argv);
}
//std::cout << std::regex_match(res,m,st_re) << std::endl;
//std::cout << res << std::endl;
/*
while(std::regex_search(res,m,re)){
std::cout << "hello" << std::endl;
for(std::string s : m){
std::cout << s<<std::endl;
}
res = m.suffix().str();
}*/

return 0;
}
