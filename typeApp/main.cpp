
#include <iostream>
#include "include/json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
using json = nlohmann::json; 

/**
 * @brief 结构体定义：字典项
 * 
 * @param id 字典项的唯一标识符
 * @param name 字典项的名称
 * @param description 字典项的描述
 * @param category 字典项的类别
 * @param tags 字典项的标签
 * @param url 字典项的URL
 * @param length 字典项的长度
 * @param language 字典项的语言
 * @param languageCategory 字典项的语言类别
 */
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

/**
 * @brief 结构体定义：单词
 * 
 * @param name 单词的名称
 * @param trans 单词的翻译
 */
struct Word {
    string name;
    vector<string> trans;
};

/**
 * @brief 从文件读取 JSON 数据
 * 
 * @param filePath 文件路径
 * @return json 读取的 JSON 数据
 */
json readJsonFile(const string& filePath) {
    ifstream file(filePath);
    json j;
    file >> j;
    return j;
}

/**
 * @brief 显示菜单并返回用户选择的字典项
 * 
 * @param items 字典项的向量
 * @return DictionaryItem 用户选择的字典项
 */
DictionaryItem displayMenuAndGetSelection(const vector<DictionaryItem>& items) {
    cout << "选择一个字典" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].name << " - " << items[i].description << endl;
    }
    int choice;
    cin >> choice;
    return items[choice - 1];
}

/**
 * @brief 生成指定范围内的随机数
 * 
 * @param start 起始位置
 * @param end 结束位置
 * @return int 随机数
 */
int randint(int start, int end) {
    srand(static_cast<unsigned>(time(0)));
    int randomIndex = start + rand() % (end - start + 1);
    return randomIndex;
}

/**
 * @brief 显示单词的翻译
 * 
 * @param words 单词结构体
 */
void displayTrans(Word words) {
    for (const auto& word : words.trans) {
        cout << word << endl;
    }
    return ;
}

/**
 * @brief 获取用户的单词输入
 * 
 * @return string 用户输入的单词
 */
string getUserInput() {
    string input;
    getline(cin,input);
    return input;
}

/**
 * @brief 初始化字典项
 * 
 * @param filePath 文件路径
 * @return vector<DictionaryItem> 字典项的向量
 */
vector<DictionaryItem> init_DictionaryItems(const string& filePath){
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
    return dictionaryItems;
}

/**
 * @brief 初始化字典
 * 
 * @param filePath 文件路径
 * @return vector<Word> 单词的向量
 */
vector<Word> init_Dict(const string& filePath){
    json dict = readJsonFile(filePath);
    vector<Word> words;
    for (const auto& word : dict){
        words.push_back({word["name"], word["trans"]});
    }
    return words;
}

/**
 * @brief 进行听写练习
 * 
 * @param words 单词的向量
 */
void dictationPractice(vector<Word>& words) {
    cout<<"开始听写"<<endl;
    while (!words.empty()) {
        int randomIndex  = randint(0,words.size());
        Word& randomWord = words[randomIndex];
        displayTrans(randomWord);
        string user_input = getUserInput();

        if (randomWord.name == user_input) {
            cout << "答对啦！" << endl;
            // 删除正确的单词
            words.erase(words.begin() + randomIndex);
        } else {
            cout << "答错啦！正确答案是: " << randomWord.name << endl;
        }

    }

    cout<<"恭喜你，听写完成！"<<endl;
}

/**
 * @brief 主函数
 * 
 * @return int 程序执行结果
 */
int main() {
    vector<DictionaryItem> dictionaryItems = init_DictionaryItems("../dictionary.json");
    // 显示菜单并获取用户选择的字典项
    DictionaryItem selectedDictionary = displayMenuAndGetSelection(dictionaryItems);
    // 获得一个字典
    vector<Word> words = init_Dict(selectedDictionary.url);
    
    // 开始听写
    dictationPractice(words);
    return 0;
}
