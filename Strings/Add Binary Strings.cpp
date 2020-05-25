Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

#Code

string Solution::addBinary(string a, string b) {
    string str="",dummy="";
        int l1=a.size(),l2=b.size();
        int len=l1;
        int carry=0;
        if(l1>l2){
            for(int i=0;i<l1-l2;i++)
                dummy+='0';
            for(int i=0;i<b.size();i++){
                dummy+=b[i];
            }
            len=l1;
            b=dummy;
            
        }
        else if(l2>l1){
            for(int i=0;i<l2-l1;i++)
                dummy+='0';
            for(int i=0;i<a.size();i++){
                dummy+=a[i];
            }
            len=l2;
            a=dummy;
        }
        for(int i=len-1;i>=0;i--){
            if(a[i]=='0' && b[i]=='0' && carry==0){
                str+='0';
                carry=0;
            }
            else if(a[i]=='0' && b[i]=='0' && carry==1){
                str+='1';
                carry=0;
            }
            else if(a[i]=='1' && b[i]=='0' && carry==0){
                str+='1';
                carry=0;
            }
            else if(a[i]=='1' && b[i]=='0' && carry==1){ 
                str+='0';
                carry=1;
            }
            else if(a[i]=='0' && b[i]=='1' && carry==0){ 
                str+='1';
                carry=0;
            }
            else if(a[i]=='0' && b[i]=='1' && carry==1){ 
                str+='0';
                carry=1;
            }
            else if(a[i]=='1' && b[i]=='1' && carry==0){ 
                str+='0';
                carry=1;
            }
            else if(a[i]=='1' && b[i]=='1' && carry==1){ 
                str+='1';
                carry=1;
            }
        }    
        if(carry==1){
            str+='1';
        }
        reverse(str.begin(),str.end());
        return str;
}
