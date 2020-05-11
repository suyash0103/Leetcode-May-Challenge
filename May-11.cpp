class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int m, int n, int newColor, int oldColor)
    {
        if(sr < 0 || sr >= m || sc < 0 || sc >= n)
        {
            return;
        }
        
        image[sr][sc] = newColor;
        
        if(sr - 1 >= 0 && image[sr - 1][sc] == oldColor)
        {
            fill(image, sr - 1, sc, m, n, newColor, oldColor);
        }
        if(sr + 1 < m && image[sr + 1][sc] == oldColor)
        {
            fill(image, sr + 1, sc, m, n, newColor, oldColor);
        }
        if(sc - 1 >= 0 && image[sr][sc - 1] == oldColor)
        {
            fill(image, sr, sc - 1, m, n, newColor, oldColor);
        }
        if(sc + 1 < n && image[sr][sc + 1] == oldColor)
        {
            fill(image, sr, sc + 1, m, n, newColor, oldColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<int> > visited(m, vector<int>(n, -1));
        
        int oldColor = image[sr][sc];
        
        if(oldColor == newColor)
            return image;
        
        fill(image, sr, sc, m, n, newColor, oldColor);
        return image;
    }
};