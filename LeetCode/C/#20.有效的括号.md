//#20 有效的括号



//## 解题思路

/*
step1 求出字符串s的长度，定义一个顺序栈并初始化。

step2 从左往右扫描字符串s：
	  当扫描到“左括号”（即'('、'['、'{'这三种），则将其入栈；
	  否则，当扫描到“右括号”且栈为空时，则括号匹配失败（“右括号”为单身）；
	  而当扫描到“右括号”且栈不为空时，出栈一个元素，并将其与该“右括号”进行匹配判断。

step3 当扫描完整个字符串s时：
	  若栈不为空，则括号匹配失败（“左括号”为单身）；
	  否则，括号匹配成功。
*/



//## 代码

bool isValid(char * s){
    int length = strlen(s);     //求出字符串s的长度
    
    char Stack[length];         //定义一个顺序栈
    int top = -1;               //初始化栈

    //从左往右扫描字符串s
    for(int i = 0; i < length; i++){                        
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){     //扫描到“左括号”
            Stack[++top] = s[i];                           //将“左括号”入栈
        }else{ 
            if(top == -1)
                return false;              //扫描到“右括号”且栈为空，则括号匹配失败（“右括号”为单身）

            char topElem; 
            topElem = Stack[top--];        //出栈一个元素并赋值给topElem

            if(s[i] == ')' && topElem != '(')
                return false;                     //左右括号不匹配
            if(s[i] == ']' && topElem != '[')
                return false;                     //左右括号不匹配
            if(s[i] == '}' && topElem != '{')
                return false;                     //左右括号不匹配
        }
    }

    if(top != -1)
        return false;        //扫描到完字符串s后栈不空，则括号匹配失败（“左括号”为单身）
    return true;
   
}