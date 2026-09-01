class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        // If already cloned, return the clone
        if (mp.find(node) != mp.end())
            return mp[node];

        // Create clone
        Node* clone = new Node(node->val);

        // Store before visiting neighbors
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};