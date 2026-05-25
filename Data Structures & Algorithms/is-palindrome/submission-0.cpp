class Solution {
private:
    bool isAlphaNum(char c){
        return ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || ( c >= '0' && c <= '9');
    }

    bool isUpperCase(char c)
    {
       return ( c >= 'A' && c <= 'Z' ); 
    }

    bool equal( char a, char b)
    {
        if(isUpperCase(a)) a += 'a'-'A';
        if(isUpperCase(b)) b += 'a'-'A';
        return a==b;
    }
public:
    bool isPalindrome(string s) {
        int front = 0, back = s.size()-1;
        while(front < back)
        {
            if(!isAlphaNum(s[front])) 
            {
                front++;
                continue;
            }
            if(!isAlphaNum(s[back])) 
            {
                back--;
                continue;
            }
            if(!equal(s[front], s[back])) return false;
            front++;
            back--;
        }
        return true;
    }
};
