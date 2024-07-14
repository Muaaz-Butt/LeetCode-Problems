class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> values;
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = valToIndex.find(val);
        if (it == valToIndex.end()){
            return false;
        }
        int lastElement = values.back();
        int idx = it->second;
        values[idx] = lastElement;
        valToIndex[lastElement] = idx;
        values.pop_back();
        valToIndex.erase(it);
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % values.size();
        return values[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */