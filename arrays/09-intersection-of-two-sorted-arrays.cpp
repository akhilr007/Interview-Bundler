class Solution {
public:
    // brute force
    // time complexity -> O(n2) and space complexity -> O(n)
    vector<int> bruteForce(vector<int>& a, vector<int>& b){

        int n = a.size();
        int m = b.size();

        vector<int> vis(m, 0);
        vector<int> ans;

        int i=0, j=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(a[i] == b[j] && vis[j] == 0){
                    ans.push_back(a[i]);
                    vis[j] = 1;
                    break;
                }
                else if(b[j] > a[i])
                    break;
            }
        }
        return ans;
    }

    // optimal
    // time complexity -> O(n) : n begin min length and space complexity -> O(n+m)
    vector<int> intersectionOfTwoSortedArrays(vector<int>& a, vector<int>& b){

        int n = a.size(), m = b.size();

        vector<int> Intersection;
        int i=0, j=0;
        while(i<n and j<m){

            if(a[i] < b[j])
                i++;
            else if(b[j] < a[i])
                j++;
            else{
                Intersection.push_back(a[i]);
                i++;
                j++;
            }
        }

        return Intersection;
    }
};