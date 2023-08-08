//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node * createParentchild(Node* root, int target, map<Node*,Node*>&mp){
        Node * first = root;
        queue<Node*>q;
        q.push(root);
        mp[first] = NULL;
        Node* res = NULL;
        while(!q.empty()){
            Node* fr = q.front();
            q.pop();
            if(fr -> data == target){
                res = fr;
            }
            if(fr->left){
                mp[fr->left] = fr;
                q.push(fr->left);
            }
            if(fr->right){
                mp[fr->right] = fr;
                q.push(fr->right);
            }
        }
        return res;
    }
    
    int timetakentoburn(Node* target, map<Node*,Node*>mp, map<Node*,bool>vis){
        int time = 0;
        queue<Node*>q;
        q.push(target);
        vis[target] = true;
        while(!q.empty()){
            bool flag = false;
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
              Node* fr = q.front();
              q.pop();
            if(fr->left && !vis[fr->left]){
                vis[fr->left] = true;
                q.push(fr->left);
                flag = true;
            }
            if(fr->right && !vis[fr->right]){
                vis[fr->right] = true;
                q.push(fr->right);
                flag = true;
            }
            if(mp[fr] && !vis[mp[fr]]){
                vis[mp[fr]] = true;
                q.push(mp[fr]);
                flag = true;
             }
            }
            if(flag == true){
              time++;
            }
        }
        return time;
    }
    int minTime(Node* root, int target) 
    { 
      map<Node*,Node*>mp;
      Node * targetNode = createParentchild(root, target, mp);
      map<Node*,bool>vis;
      return timetakentoburn(targetNode, mp, vis);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends