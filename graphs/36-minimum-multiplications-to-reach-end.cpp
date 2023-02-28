class Solution{
public:
    // time complexity -> O(100000 * N(arr_size))
    // space complexity -> O(N)
    int minimumMultiplications(int start, int end, vector<int>& arr){

        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        queue<pair<int, int>> q;
        q.push({ start, 0});

        int mod = 100000;

        while(!q.empty()){

            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(node == end) return steps;

            for(auto it : arr){

                int num = (it * node) % mod;

                if(dist[node] + 1 < dist[num]){
                    dist[num] = dist[node] + 1;
                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
}