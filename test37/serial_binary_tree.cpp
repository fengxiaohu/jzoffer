#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};



class Code{
 public:
  string serialize(TreeNode* root) {
    string res;
    if (root == nullptr) return res;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();
      if (node == nullptr) res += "null,";
      else {
        res += to_string(node->val);
        res += ",";

        queue.push(node->left);
        queue.push(node->right);
      }
    }
    return res;
  }
  TreeNode* deserialize(string data)
  {
    string delimeter = ",";
    vector<string> res = split(data,delimeter);
    queue<TreeNode*> queue;
    TreeNode* root = new TreeNode(stoi(res[0]));
    queue.push(root);
    int index = 1;
    while(!queue.empty())
    {

      TreeNode* node = queue.front();
      queue.pop();
      TreeNode *leftnode,*rightnode;
      if(res[index] != "null") {

        leftnode = new TreeNode(stoi(res[index]));
        queue.push(leftnode);
      }
      else
      {
        leftnode = nullptr;
      }

      index++;
      node->left = leftnode;

      if(res[index] != "null") {
        rightnode = new TreeNode(stoi(res[index]));
        queue.push(rightnode);
      }
      else
      {
        rightnode = nullptr;
      }
      index++;
      node->right = rightnode;
    }
    return root;


  }



 private:
  // for string delimiter
  vector<string> split(string str,string delimeter)
  {
    int deli_lenght = delimeter.size();
    string token;
    size_t start = 0;
    size_t end = 0;
    vector<string> res;
    while((end = str.find(delimeter,start))!= string::npos)
    {
      token = str.substr(start,end-start);
      cout << token <<endl;
      res.push_back(token);
      start = start + (end-start) + deli_lenght;
    }
    res.push_back(str.substr(start,str.size()-1));
    return res;
  }
};





int main() {
  Code codec;
  string str = "1,2,3,null,null,4,5,null,null,null,null";
  //getline(cin,str);
  TreeNode* root =  codec.deserialize(str);
  string  res = codec.serialize(root);

}
