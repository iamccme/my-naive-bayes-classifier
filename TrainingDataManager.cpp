/*
 *TrainingDataManager.cpp
 *desc       训练集管理器
 *@author    chencheng
 *@email     cc@iamcc.me
 *@date:     2013-05-30
 */

#include "TrainingDataManager.h"

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

namespace fs = boost::filesystem;

std::string TrainingDataManager::defaultPath("./TrainingSet/");

/*
 *@desc   初始化训练集管理器
 */
TrainingDataManager::TrainingDataManager()
{
    traingTextDir = defaultPath;
    fs::path root(traingTextDir);
    std::string path, classification;

    if(!fs::exists(root) || !fs::is_directory(root))
        throw std::runtime_error("训练语料库搜索失败!");

    fs::directory_iterator end_iter;
    for(fs::directory_iterator dir_itr(root); dir_itr != end_iter; dir_itr++)
    {
        if(fs::exists(*dir_itr))
        {
                path = dir_itr->path().string();
                classification = path.substr(path.find_last_of('/') + 1);
                traningFileClassifications.push_back(classification);
        } 

    }

}
TrainingDataManager::~TrainingDataManager()
{
}

VS TrainingDataManager::getTrainingClassifications(void)
{
    return this->traningFileClassifications;
}

VS TrainingDataManager::getFilePath(std::string classification)
{
    VS ret;
    std::string classificationDir = traingTextDir + "/" + classification;
    fs::path root(classificationDir);

    if(!fs::exists(root) || !fs::is_directory(root))
    {
        //throw std::runtime_error("分类不存在!");
        std::cerr << classification << "分类不存在!" << std::endl;
        return ret;
    }

    fs::directory_iterator end_iter;
    for(fs::directory_iterator dir_itr(root); dir_itr != end_iter; dir_itr++)
    {
        if(fs::is_regular(*dir_itr))
        {
                ret.push_back(dir_itr->path().string());
        }
    }

   return ret; 

}

/*
 *@desc 读取filePath下的文本内容
 */
std::string TrainingDataManager::getText(std::string filePath)
{
    std::string text, line;
    std::ifstream infile(filePath.c_str());
    if(!infile)
    {
        std::cerr << "errror: unable tp open input file:" << filePath << std::endl;
        return text;
    }
    
    while(getline(infile, line))
        text += line;
        
    return text;
}

/*
 *@desc  获取训练集文件的数目
 */
int TrainingDataManager::getTrainingFileCount(void)
{
    VSiter iter;
    int count = 0;
    for(iter = traningFileClassifications.begin(); iter != traningFileClassifications.end(); iter++)
    {
        count += getTrainingFileCountOfClassification(*iter);
    }

    return count;
}

/*
 *@desc  获取某个分类训练集文件的数目
*/

int TrainingDataManager::getTrainingFileCountOfClassification(std::string classification)
{
    return getFilePath(classification).size();

}
/*
 *@desc 获取某个分类中出现key的问本的数目
 */

int TrainingDataManager::getCountContainKeyOfClassification(std::string classification, std::string key)
{
    std::string text;
    VS filePath = getFilePath(classification);
    VSiter iter;
    int ret = 0;

    for(iter = filePath.begin(); iter != filePath.end(); iter++)
    {
        text = getText(*iter);
        if(text.find(key, 0) != std::string::npos)
            ret++;
    }

    return ret;
    

}
// 用于测试的主函数 

/*
int main(int argc, char* argv[])
{
    VS result;
    int count;
    TrainingDataManager manager;
    result = manager.getTraningClassfications();
    result = manager.getFilePath("C000007");
    count = manager.getTrainingFileCountOfClassification("C000007");
    std::cout << "C000007分类下的训练文本数目是" << count << std::endl;
    count = manager.getTrainingFileCount();
    std::cout << "总的训练文本数目是" << count << std::endl;
    count = manager.getCountContainKeyOfClassification("C000007", "汽车");
    std::cout << "C000007分类包含“汽车”的训练文本数目是：" << count << std::endl;

    VSiter iter;
    for(iter = result.begin(); iter != result.end(); iter++)
    {
        std::cout << *iter << std::endl;
        std::cout << manager.getText(*iter) << std::endl;
    }
    
    return 0;
}
*/

