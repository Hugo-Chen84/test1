#include<stdio.h>
#include<string.h>

int main(){
    // 修正1：改为二维数组（11个字符串，每个最多99个字符+'\0'）
    char string[11][100];  
    int n;

    // 修正2：检查n的范围（避免数组越界）
    scanf("%d",&n);
    if(n < 1 || n > 11){
        printf("n必须在1~11之间\n");
        return 1;
    }

    int x=0; 
    for(;x<n;x++){
        // 修正3：scanf参数改为string[x]（二维数组行地址，char*类型）
        scanf("%s", string[x]);  
    } 

    char check[10000]={'\0'};
    // 修正4：strcpy参数改为check（首地址），string[n-1]（最后一个输入的字符串）
    strcpy(check, string[n-1]);  

    char output[12000]={'\0'};
    int i=0;
    int index=0;

    while(check[i]!='\0'){
        int none=1;  // 标记是否未匹配到任何子串
        int k=0;
        for(;k<n-1;k++){  // 遍历前n-1个字符串（作为待匹配子串）
            // 修正5：temp大小扩大到100，避免溢出（与string每行长度一致）
            char temp[100]={'\0'};
            strcpy(temp, string[k]);  // 修正：参数为temp（首地址）

            // 检查当前check[i]是否与子串首字符匹配
            if(check[i] == temp[0]){
                int j=0;
                // 逐字符匹配子串
                while(temp[j]!='\0' && check[i+j]!='\0'){
                    if(temp[j] != check[i+j]){
                        break;
                    }
                    j++;
                }
                // 修正6：用==判断子串是否匹配完成
                if(temp[j] == '\0'){
                    none=0;  // 标记已匹配
                    // 写入带*的子串
                    output[index++] = '*';
                    int p=0;
                    for(; p<j; p++){
                        output[index++] = temp[p];
                    }
                    output[index++] = '*';
                    // 修正7：跳过已匹配的字符（关键！）
                    i += j;  
                    break;  // 匹配一个子串即可，跳出k循环
                }
            }
        }
        // 未匹配到任何子串，直接写入当前字符
        if(none){
            output[index++] = check[i];
            i++;  // 推进到下一个字符
        }
    }

    // 输出结果（原代码未打印output，补充）
    printf("%s\n", output);
    return 0;
}
