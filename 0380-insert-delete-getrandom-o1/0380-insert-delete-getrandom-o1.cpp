class RandomizedSet {
public:
    vector<int> newDs;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // if not present
        if(mp.find(val) != mp.end()){ // if val is already present
            return false;
        }
        newDs.push_back(val);
        mp[val] = newDs.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){ // if val is not present
            return false;
        }

        int idx = mp[val];
        int lastNum = newDs.back();
        newDs.back() = val;

        newDs[idx] = lastNum;
        mp[lastNum] = idx;

        newDs.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int n = newDs.size();
        int randInd = rand() % n;
        return newDs[randInd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */