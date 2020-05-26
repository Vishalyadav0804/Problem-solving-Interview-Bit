Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)

#Code

bool isdigit(char ch){
    return (ch>='0' && ch<='9')?true:false;
}
bool isValid(string IP){
    if(IP[IP.size()-1]=='.'){
            return "Neither";
        }
        int c=0;
        vector <string> tokens;  
        stringstream check1(IP); 
        string intermediate; 
        while(getline(check1, intermediate, '.')) 
            tokens.push_back(intermediate); 
        for(auto tmp:tokens){
            if(tmp.size()==0){
                return false;
            }
            if(tmp[0]=='-'){
                return false;
            }
            if(tmp.size()>1 && tmp[0]=='0'){
                return false;
            }
            if(tmp.size()>3){
                return false;
            }
            for(auto ch:tmp){
                if(!isdigit(ch)){
                    return false;
                }
            }
            if(stoi(tmp)<0 or stoi(tmp)>255){
                return false;
            }
            c++;
        }
        if(c==4){
            return true;
        }
}
string generateString(string A,int i,int j,int k)
{
    string S;
    for(int idx=0;idx<A.length();idx++)
    {
        S=S+A[idx];
    
        if(idx==i || idx==j || idx==k)
        {
            S=S+'.';   
        }
    }
    return S;
}
vector<string> Solution::restoreIpAddresses(string A) {
    int n=A.length();
    vector<string> ans;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                string S = generateString(A,i,j,k);
                
                if(isValid(S))
                {
                    ans.push_back(S);
                }
            }
        }
    }
    
    return ans;
}
