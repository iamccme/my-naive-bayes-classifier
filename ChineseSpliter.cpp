/*
 *ChineseSpliter.cpp
 *@desc    中文分词器，采用friso分词库
 *@author    chencheng
 *@email     cc@iamcc.me
 */

#include "ChineseSpliter.h"
#include <vector>


std::string StopWordHandler::stopWordList[] = {"的", "我们","要","自己","之","将","“","”","，","（","）","后","应","到","某","后","个","是","位","新","一","两","在","中","或","有","更","好",""};
//常用停用词

/*
@desc 判断一个词是否是停用词
*/
bool StopWordHandler::IsStopWord(std::string word)
{
    std::cout << stopWordNum << std::endl;
    for(int i = 0; i < stopWordNum; i++)
    {
        if(word == stopWordList[i])
            return true;
    }
    return false;
}

/*
@desc 用文件path初始化分词器
*/
ChineseSpliter::ChineseSpliter(const std::string _path_)
{
    path = const_cast<char*>(_path_.c_str());
    friso = friso_new_from_ifile(path);

}

ChineseSpliter::~ChineseSpliter(void)
{
    friso_free(friso);

}

/*
@desc 对文本进行分词，储存在vector中
*/
void ChineseSpliter::split(const std::string text, VS& result)
{

    task = friso_new_task();
    friso_set_text(task, const_cast<char*>(text.c_str()));
    
    while((friso_next(friso, friso->mode, task)) != NULL)
    {
        std::string word(task->hits->word); 
        result.push_back(word);
        if(task->hits->type == __FRISO_NEW_WORDS__)
            FRISO_FREE(task->hits->word);

    }
    friso_free_task(task);
}

//用于测试的主函数
int main(int argc, char* argv[])
{
    std::string text = "我是一个中国人";
    VS result;
    ChineseSpliter* spilterPtr = new ChineseSpliter("./friso-0.1/core/friso.ini");
    spilterPtr->split(text, result);

    VSiter iter;
    for(iter = result.begin(); iter != result.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    delete spilterPtr;
    std::cout << "我爱:" << StopWordHandler::IsStopWord("我爱") << std::endl;
    std::cout << "我们:" << StopWordHandler::IsStopWord("我们") << std::endl;
    return 0;
}
