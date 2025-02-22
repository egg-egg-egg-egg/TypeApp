#include <iostream>
#include "include/json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
using json = nlohmann::json; 

// 定义字典项结构体
struct DictionaryItem {
    string id;
    string name;
    string description;
    string category;
    vector<string> tags;
    string url;
    int length;
    string language;
    string languageCategory;
};

struct Word {
    string name;
    vector<string> trans;
};

// 从文件读取 JSON 数据
json readJsonFile(const string& filePath) {
    ifstream file(filePath);
    json j;
    file >> j;
    return j;
}

// 显示菜单并返回用户选择的字典项
DictionaryItem displayMenuAndGetSelection(const vector<DictionaryItem>& items) {
    cout << "选择一个字典" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].name << " - " << items[i].description << endl;
    }
    int choice;
    cin >> choice;
    return items[choice - 1];
}

// 从字典文件中随机选择一个单词
json getRandomWord(const string& filePath) {
    json dict = readJsonFile(filePath);
    if (dict.empty()) {
        cerr << "字典文件为空或未正确读取!" << endl;
        return {};
    }
    srand(static_cast<unsigned>(time(0)));
    int randomIndex = rand() % dict.size();
    
    return dict[randomIndex];
}


void displayTrans(json& words) {
    for (const auto& word : words["trans"]) {
        cout << word << endl;
    }
    return ;
}

// 获取用户的单词输入
string getUserInput() {
    string input;
    cin >> input;
    return input;
}

int main() {
    // 读取 dictionary.json 文件
    json dictionaryJson = readJsonFile("../dictionary.json");

    // 将 JSON 数据转换为 DictionaryItem 结构体的向量
    vector<DictionaryItem> dictionaryItems;
    for (const auto& item : dictionaryJson) {
        dictionaryItems.push_back({
            item["id"],
            item["name"],
            item["description"],
            item["category"],
            item["tags"].get<vector<string>>(),
            item["url"],
            item["length"],
            item["language"],
            item["languageCategory"]
        });
    }

    // 显示菜单并获取用户选择的字典项
    DictionaryItem selectedDictionary = displayMenuAndGetSelection(dictionaryItems);

    // 从选择的字典文件中随机选择一个单词
    json randomWord = getRandomWord(selectedDictionary.url);
    displayTrans(randomWord);
    string user_input = getUserInput();


    if (randomWord["name"] == user_input) {
        cout << "答对啦！" << endl;
    } else {
        cout << "答错啦！" << randomWord["name"] << endl;
    }
    

    return 0;
}
