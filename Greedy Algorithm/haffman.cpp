#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// Huffman tree node
struct HuffmanNode {
    char data; // character
    int frequency; // frequency of the character
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for Huffman nodes
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) const {
        return a->frequency > b->frequency; // min-heap based on frequency
    }
};

// Function to build the Huffman tree
HuffmanNode* buildHuffmanTree(const map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Combine nodes until there is only one node left in the priority queue, which will be the root of the Huffman tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        // Create a new internal node with the sum of the frequencies of the two nodes
        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}

// Function to traverse the Huffman tree and generate codes
void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& codes) {
    if (root == nullptr) return;

    if (root->data != '$') {
        codes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

// Function to encode a string using Huffman coding
string huffmanEncode(const string& str, const map<char, string>& codes) {
    string encodedString;
    for (char c : str) {
        encodedString += codes.at(c);
    }
    return encodedString;
}

// Function to decode a string using Huffman coding
string huffmanDecode(const string& encodedString, const HuffmanNode* root) {
    string decodedString;
    const HuffmanNode* current = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->data != '$') {
            decodedString += current->data;
            current = root;
        }
    }
    return decodedString;
}
int calculateTotalCost(const map<char, int>& frequencyMap, const map<char, string>& codes) {
    int totalCost = 0;
    for (const auto& pair : codes) {
        totalCost += frequencyMap.at(pair.first) * pair.second.length();
    }
    return totalCost;
}

int main() {
    string inputString;
    cout<<"Enter string:";
    cin >> inputString; // = "this is so dark";
    map<char, int> frequencyMap;
    for (char c : inputString) {
        frequencyMap[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(frequencyMap);

    map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (const auto& pair : codes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string encodedString = huffmanEncode(inputString, codes);
    cout << "\nEncoded String: " << encodedString << endl;

    string decodedString = huffmanDecode(encodedString, root);
    cout << "\nDecoded String: " << decodedString << endl;

    int totalCost = calculateTotalCost(frequencyMap, codes);
    cout << "\nTotal Cost of Huffman Coding: " << totalCost << endl;

    return 0;
}