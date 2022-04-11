//#14 最长公共前缀



//## 解题思路

/*
以第一个字符串作为比较的标准，采用两层循环进行纵向对比，最后用字符串数组的第一个字符串保存最长公共前缀。
*/



//## 代码

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0){
        return "";              //字符串数组为空，返回空字符串
    }

    int flag = 0;               //flag等于0表示最长公共前缀还未找到
    
    //以第一个字符串作为比较的标准，采用两层循环进行纵向对比，最后用字符串数组的第一个字符串保存最长公共前缀

    for(int i = 0; i < strlen(strs[0]); i++){  //i表示列，strlen(strs[0])表示数组中第一个字符串的长度

        for(int j = 1; j < strsSize; j++){     //j表示行
            if(strs[0][i] != strs[j][i]){      //若字符串的第i列不同，则最长公共前缀已找到，跳出内层循环
                strs[0][i] = '\0';             //用数组的第一个字符串保存最长公共前缀
                flag = 1;
                break;
            }
        }

        if(flag == 1){                         //最长公共前缀已找到，跳出外层循环
            break;
        }

    }

    return strs[0];                            //最长公共前缀已找到

}