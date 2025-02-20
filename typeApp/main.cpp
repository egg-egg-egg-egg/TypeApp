#include <iostream>
#include <json.hpp>
#include <string>
#include <fstream>

using namespace std;
using json = nlohmann::json; 

int main() {
//	string jsonstr = "{\"name\": \"Tom\", \"age\": 30}";
//	json data = json::parse(jsonstr);
//	
//	cout<<" 姓名: "<< data["name"] << "\n年龄: "<<data["age"];
    
	
//	"data.json"
	ifstream file("data.json");
	if(file){
		json file_data;
		file >> file_data;
		cout<<"文件内容是: "<<file_data["name"];
	}else{
		cerr << "文件打开失败";
	}
	return 0;
}
