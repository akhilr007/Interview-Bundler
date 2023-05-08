class Solution{
public:
    vector<int> nextSmallerLeft(vector<int>& arr){

        int n = arr.size();
        stack<int> st;

        vector<int> nsl(n);

        for(int i=0; i<n; i++){

            while(st.size()>0 && arr[st.top()] >= arr[i])
                st.pop();

            if(st.size() == 0)
                nsl[i] = -1;
            else
                nsl[i] = st.top();

            st.push(i);
        }

        return nsl;
    }

    vector<int> nextSmallerRight(vector<int>& arr){

        int n = arr.size();
        stack<int> st;

        vector<int> nsr(n);

        for(int i=n-1; i>=0; i--){

            while(st.size()>0 && arr[st.top()] >= arr[i])
                st.pop();

            if(st.size() == 0)
                nsr[i] = n;
            else
                nsr[i] = st.top();

            st.push(i);
        }

        return nsr;
    }

    int maximumAreaHistogram(vector<int>& arr){

        vector<int> nsl = nextSmallerLeft(arr);
        vector<int> nsr = nextSmallerRight(arr);

        int maxArea = 0;
        
        for(int i=0; i<arr.size(); i++){

            int height = arr[i];
            int width = nsr[i] - nsl[i] - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;

    }

    int maximalRectangle(vector<vector<char>>& matrix){

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m);

        int maxArea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }

            maxArea = max(maxArea, maximumAreaHistogram(heights));
        }

        return maxArea;
    }
};