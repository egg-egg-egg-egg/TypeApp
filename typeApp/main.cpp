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
//	cout<<" ����: "<< data["name"] << "\n����: "<<data["age"];
    
	
//	"data.json"
	ifstream file("data.json");
	if(file){
		json file_data;
		file >> file_data;
		cout<<"�ļ�������: "<<file_data["name"];
	}else{
		cerr << "�ļ���ʧ��";
	}
	return 0;
}
