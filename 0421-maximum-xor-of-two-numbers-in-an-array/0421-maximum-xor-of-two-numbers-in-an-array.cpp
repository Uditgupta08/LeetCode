class Node {
public:
    Node* links[2]; // 0 OR 1 AT NODE
    bool containsKey(int bit) { return (links[bit] != NULL); } 
    Node* get(int bit) { return links[bit]; }
    void put(int bit, Node* node) { links[bit] = node; } // INSERT KARDE BHAI NODE
};
class Trie {
public:
    Node* root; // MAKING A TRIE
    Trie() { root = new Node(); } // EMPTY TRIE FOR THE BEGINNING
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) { // 32 BITS BINARY NUMBER 
            int bit = (num >> i) & 1; // RIGHT SHIFT AND CHECK IF ITS 'AND' WITH 1 IS 0 OR 1
            if (!node->containsKey(bit)) { // NODE DONT EXIST FOR THAT BIT
                node->put(bit, new Node()); // INSERT KARDE NODE
            }
            node = node->get(bit); // AAGE NEXT BITS BHI TO INSERT KAREGA NA
        }
    }
    int getMax(int num) { // 1 NUM DIA HAI USKA HIGHEST XOR VALUE KISKE SATH H YE BTA RHA
        Node* node = root;
        int maxNum = 0; // ISME STORE KARDO
        for (int i = 31; i >= 0; i--) { // 32 BITS KA HAI
            int bit = (num >> i) & 1; // HM LOG NUM KO BINARY MAI KAR RHE CONVERT
            if (node->containsKey(1 - bit)) {   // CHECK KARLE KI JO BIT AYA USSE OPP BIT HAI YA NHI
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (auto it : nums) {
            trie.insert(it);
        }
        int maxi = 0;
        for (auto it : nums) {
            maxi = max(maxi, trie.getMax(it));
        }
        return maxi;
    }
};