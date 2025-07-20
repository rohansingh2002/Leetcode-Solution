class Node {
public:
    string name; 
    unordered_map<string, Node*> children;
    string signature;

    Node(string temp) {
        name = temp;
        signature.clear();
    }
};

class Trie {
private:
    Node* root;
    unordered_map<string, int> sigCount;

    void insert(const vector<string>& path) {
        Node* curr = root;
        for (auto& folder : path) {
            if (curr->children.find(folder) == curr->children.end()) 
                curr->children[folder] = new Node(folder);

            curr = curr->children[folder];
        }
    }

    string dfsSign(Node* node) {
        if (node->children.empty()) {
            node->signature.clear();
            return "";
        }

        vector<string> parts; 
        for (auto& p : node->children) {
            parts.push_back(p.first + "[" + dfsSign(p.second) + "]");
        }

        sort(parts.begin(), parts.end());

        string sig;
        for (auto& s : parts) sig += s;

        node->signature = sig; 
        sigCount[sig]++;

        return sig;
    }

    void dfsCollect(Node* node, vector<string>& path, vector<vector<string>>&answer) {
       
        if (!node->children.empty() && sigCount[node->signature] > 1) return;

        path.push_back(node->name);
        answer.push_back(path);

        
        for (auto& p : node->children) dfsCollect(p.second, path, answer);

        path.pop_back();
    }
public:
    Trie() {
        root = new Node("");
    }
    vector<vector<string>> collectAnswer(vector<vector<string>>& paths) {
       
        for (auto& path : paths) insert(path);

       
        for (auto& p : root->children) dfsSign(p.second);

        vector<vector<string>> answer;
        vector<string> current;
        for (auto& p : root->children) dfsCollect(p.second, current, answer);

        return answer;
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;
        return trie.collectAnswer(paths);
    }
};