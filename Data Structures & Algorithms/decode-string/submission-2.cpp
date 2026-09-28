class Solution {
public:
    
    string solve(string s){
        stack<int>st;
        stack<string>ch;
        string ans;
        for(int k = 0 ; k < s.size() ;k++){
            char i = s[k];
            if(i >='0' and  i<='9'){
                int l = k;
                int cnt = i-'0' ;
                while(l+1 < s.size() and s[l+1] >= '0' and s[l+1] <='9'){    cnt =cnt*10 + s[l+1]-'0'; ++l;}
                cout<<"cnt : "<<cnt<<endl;
                k=l;
                st.push(cnt);
            }else if(i == '['){
                string temp =""; temp+=i;
                
                cout<<i<<" < "<<temp<<endl; 
                ch.push(temp);
            }else if(i>='a' and i <='z'){
                string temp =""; temp+=i;
                cout<<i<<" "<<temp<<endl; 
                ch.push(temp);
            }else if( i == ']'){
                string temp, final;
                while(!ch.empty() and ch.top() != "["){
                    temp += ch.top(); ch.pop();
                }
                ch.pop();
                // reverse(temp.begin(),temp.end());
                int cnt = st.top(); st.pop();
                for(int i = 0 ; i < cnt; i++){
                    final += temp;
                }
                cout<<"final : " <<final<< " "<<temp<<endl;
                ch.push(final);
            }
        }
        while(!ch.empty()){
            
            ans += ch.top(); 
            ch.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string decodeString(string s) {
        return solve(s);
    }
};