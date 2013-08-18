/*
 *ChineseSpliter.h

 *@author    chencheng
 *@email     chencheng1022@gmail.com
 */
#ifndef CHINESE_SPLITER_H
#define CHINESE_SPLITER_H

extern "C"
{
    #include "include/friso_API.h"
    #include "include/friso.h"
}

#include "comm.h"

#include <fstream>
#include <iostream>
#include <vector>


class ChineseSpliter
{
    public:
        ChineseSpliter(const std::string _path_);
        ~ChineseSpliter();
        void split(const std::string text, VS& result);

    private:
        char* path;
        friso_t friso;
        friso_task_t task;

};

/*
 * 停用词处理器 
 */

class StopWordHandler
{
    public:
        static bool IsStopWord(std::string word); 
    private:
        const static int stopWordNum = 30;
        static std::string stopWordList[stopWordNum];

};
#endif
