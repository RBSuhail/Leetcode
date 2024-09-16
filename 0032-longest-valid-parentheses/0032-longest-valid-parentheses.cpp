class Solution {
public:
    int longestValidParentheses(string s) {
        int op=0,cl=0,len=0,n=s.size(),len2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                op++;
            }else
            {
                cl++;
            }
            if(cl>op)
            {
                op=0,cl=0;
            }
            else if(op==cl)
            {
                len=max(len,cl*2);
            }
        }


        for(int i=n;i>=0;i--)
        {
            if(s[i]==')')
            {
                cl++;
            }
            else
            {
                op++;
            }
            if(op>cl)
            {
                op=0,cl=0;
            }
            else if(op==cl)
            {
                len2=max(len2,2*op);
            }

        }return max(len,len2);
    }
};