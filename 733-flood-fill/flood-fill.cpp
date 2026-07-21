class Solution {
public:
 void help(vector<vector<int>>& image, int sr, int sc, int oldColor,int newColor ,int m,int n){
   
      if(sr>=m||sc>=n||sr<0||sc<0){
        return;
      }
      if(image[sr][sc]!=oldColor){
       return;
      }
       image[sr][sc]=newColor;
      help(image,sr+1,sc,oldColor,newColor,m,n);
        help(image,sr,sc+1,oldColor,newColor,m,n);
          help(image,sr,sc-1,oldColor,newColor,m,n);
            help(image,sr-1,sc,oldColor,newColor,m,n);
    
 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int m=image.size();
      int n=image[0].size();
      int oldColor =image[sr][sc];
      int newColor=color;
        if (oldColor == color)
        return image;
       help(image,sr,sc,oldColor,newColor,m,n);
      return image;
    }
};