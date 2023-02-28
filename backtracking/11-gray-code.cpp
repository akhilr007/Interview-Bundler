class Solution{
private:
    // recursive code
    vector<string> generate(int n){

        if(n == 1){
            return {"0", "1"};
        }

        vector<string> temp = generate(n-1);
        vector<string> ans;

        for(int i=0; i<temp.size(); i++){
            ans.push_back("0" + temp[i]);
        }

        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back("1" + temp[i]);
        }

        return ans;
    }

    vector<int> grayCode(int n){

        vector<string> grayCodeList = generate(n);
        vector<int> ans;

        for(string binaryCode : grayCodeList){
            ans.push_back(stoi(binaryCode, 0, 2)); // stoi(string, starting_pos, binary or decimal)
        }

        return ans;
    }

public:
    vector<int> grayCode(int n){

        vector<int> result(1, 0);

        for(int i=0; i<n; i++){
            int cursize = result.size()-1;
            for(int j=cursize-1; j>=0; j--){
                result.push_back(result[j] + (1 << i));
            }
        }

        return result;
    }
};