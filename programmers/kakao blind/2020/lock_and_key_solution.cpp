#include <vector>
#include <string>
#include <iostream>

using namespace std;

void edge(vector<vector<int>> & lock, int & x1, int & x2, int & y1, int & y2);
bool same(const vector<vector<int>> & key, const vector<vector<int>> & lock, const int x, const int y, const int x1, const int x2, const int y1, const int y2, int type);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
   int x1, x2, y1, y2, keyLen = key.size();
   edge(lock, x1, x2, y1, y2);
   cout << x1 << x2 << y1 << y2;
   if (x2 - x1 == 0 || y2 - y1 == 0) return true;
   if (keyLen < x2 - x1 || keyLen < y2 - y1) return false;

   for (int i = 0; i < keyLen - (y2 - y1 - 1); i++) {
      for (int j = 0; j < keyLen - (x2 - x1 - 1); j++) {
         if (same(key, lock, i, j, x1, x2, y1, y2, 0)) return true;
         if (same(key, lock, i, j, x1, x2, y1, y2, 2)) return true;
      }
   }

   for (int i = 0; i < keyLen - (x2 - x1 - 1); i++) {
      for (int j = 0; j < keyLen - (y2 - y1 - 1); j++) {
         if (same(key, lock, i, j, x1, x2, y1, y2, 1)) return true;
         if (same(key, lock, i, j, x1, x2, y1, y2, 3)) return true;
      }
   }

   return false;
}

bool same(const vector<vector<int>> & key, const vector<vector<int>> & lock, const int x, const int y, const int x1, const int x2, const int y1, const int y2, int type) {
   switch (type)
   {
   case 0:
      for (int i = 0; i < x2 - x1; i++)
         for (int j = 0; j < y2 - y1; j++)
            if (key[x + i][y + j] != lock[x1 + i][y1 + j]) return false;
      return true;
   case 1:
      for (int i = 0; i < x2 - x1; i++)
         for (int j = 0; j < y2 - y1; j++)
            if (key[x + i][y + j] != lock[x2 - j - 1][y1 + i]) return false;
      return true;
   case 2:
      for (int i = 0; i < x2 - x1; i++)
         for (int j = 0; j < y2 - y1; j++)
            if (key[x + i][y + j] != lock[x2 - i - 1][y2 - j - 1]) return false;
      return true;
   case 3:
      for (int i = 0; i < x2 - x1; i++)
         for (int j = 0; j < y2 - y1; j++)
            if (key[x + i][y + j] != lock[x1 + j][y2 - i - 1]) return false;
      return true;
   }
   return false;
}

void edge(vector<vector<int>> & lock, int & x1, int & x2, int & y1, int & y2) {
   int len = lock.size();
   bool stop = false;
   x1 = y1 = 0; x2 = y2 = len;
   for (int i = 0; i < len && !stop; i++) {
      for (int j = 0; j < len && !stop; j++) {
         if (lock[i][j] != 1) stop = true;
      }
      if (!stop) y1 = i + 1;
   }
   stop = false;
   for (int i = 0; i < len && !stop; i++) {
      for (int j = 0; j < len && !stop; j++) {
         if (lock[j][i] != 1) stop = true;
      }
      if (!stop) x1 = i + 1;
   }
   stop = false;
   for (int i = len - 1; i > y1 && !stop; i--) {
      for (int j = 0; j < len && !stop; j++) {
         if (lock[i][j] != 1) stop = true;
      }
      if (!stop) y2 = i;
   }
   stop = false;
   for (int i = len - 1; i > x1 && !stop; i--) {
      for (int j = 0; j < len && !stop; j++) {
         if (lock[j][i] != 1) stop = true;
      }
      if (!stop) x2 = i;
   }
}