/*
 *TrainingDataManager.h

 *@author    chencheng
 *@email     chencheng1022@gmail.com
 *@date:     2013-05-30
 */
#ifndef TRAINING_DATA_MANAGER_H
#define TRAINING_DATA_MANAGER_H

#include "comm.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class TrainingDataManager
{
    public:
        TrainingDataManager();
        ~TrainingDataManager();
        VS getTrainingClassifications(void);                           //返回训练文本类别，这个类别就是目录名
        VS getFilePath(std::string classification);  //根据训练文本类别返回这个类别下的所有训练文本路径
        std::string getText(std::string filePath);             //给定分类下所有文件的路径
        int getTrainingFileCount(void);                             //返回训练文本集所有文本的数目
        int getTrainingFileCountOfClassification(std::string classification);
        int getCountContainKeyOfClassification(std::string classification, std::string key); 

    private:
        VS traningFileClassifications;
        std::string traingTextDir;
        static std::string defaultPath;

};

#endif
