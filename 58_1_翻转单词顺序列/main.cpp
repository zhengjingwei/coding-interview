class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty())
            return str;
        int len = str.size();
        // 整个字符串翻转
        for(int i=0;i< len/2;++i){
            swap(str[i],str[len-i-1]);
        }

        int begin = 0;
        for(int i=1;i<len;++i){
            // 翻转单词内字符str
            if(str[i]==' ' && str[i-1]!=' '){
                ReverseWord(str,begin,i-1);
            }
            // 更新begin
            if(str[i]!=' ' && str[i-1]==' '){
                begin = i;
            }
            //最后一个单词
            if(i+1==len && str[i]!=' ')
                ReverseWord(str,begin,i);
        }
        return str;
    }
    // 单词内翻转
    void ReverseWord(string &str, int begin, int end){
        while(begin<end){
            swap(str[begin],str[end]);
            ++begin;
            --end;
        }
    }
};