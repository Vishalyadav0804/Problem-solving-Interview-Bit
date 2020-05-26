Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
 Note: Each word is guaranteed not to exceed L in length. 
 
 #Code
 
 string makestring(vector<string>& temp, int ct, int tot, int maxW)
{
    string res="";

    // If only one word, put all spaces after it.
    if(ct==1){
        res = temp[0] + string(maxW-tot,' ');
        return res;
    }

    bool first=false; // First Word
    for(auto wrd:temp){
        if(!first) {res+=wrd; first=true;}
        else{
            // More spaces to the left as much as possible.
            double left=(1.0*(maxW-tot))/(ct-1);
            int space=(int)(ceil(left)); // Number of spaces
            res+= string(space,' ')+wrd;
            tot+=space;
            ct--;
        }   
    }
    return res;
}
vector<string> Solution::fullJustify(vector<string> &words, int maxWidth) {
    vector<string> temp,ans;
    if(words.size()==0){
        return ans;
    }
    int n=words.size();
    int ct=0, tot=0;
    for(int i=0;i<n;i++){
        string str=words[i];
        if(ct==0){
            tot+=str.length();
            ct++;
            temp.push_back(str);
        }
        else{
            if(tot+str.length()+1 <= maxWidth){ // 1 for extra space
                ct++;
                tot+=str.length()+1;
                temp.push_back(" "+str);
            }
            else{
                string res=makestring(temp,ct,tot,maxWidth);
                ans.push_back(res);
                temp.clear();
                ct=0; tot=0;
                i--;
            }
        }
    }

    // Code for handling the last line.
    string str="";
    for(auto wrd:temp) str+=wrd;
    ans.push_back(str+string(maxWidth-tot,' '));
    return ans;
}
