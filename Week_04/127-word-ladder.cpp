class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> wordMap;
        unordered_set<string> wordsSet;
        for (string word : wordList) wordsSet.insert(word);
        // 处理边界场景
        if (wordsSet.count(endWord) == 0) return 0;

        int step = 0;
        {
            // 广度优先搜索
            unordered_set<string> visited; // 记录已访问过的节点，避免重复访问

            // 广度优先搜索基于队列实现，一般采用双端队列
            deque<string> queue; 
            // 起始词为第一个元素
            queue.push_back(beginWord);

            while(!queue.empty()) {
                step++;

                int size = queue.size();
                while(size--) {
                    string word = queue.front(); 
                    queue.pop_front();
                    visited.insert(word);

                    if (word == endWord) {
                        // 找到了直接返回
                        return step;                        
                    }

                    vector<string>& nextWords = transferList(word, wordsSet, wordMap);
                    for (string& next : nextWords) {
                        // 由于有 visited, 最差的情况下，所有选项都尝试过
                        // 还是没找到终点，跳出循环，终止查找
                        // 注意，如果没有 visited 会无法终止查找
                        if (visited.find(next) == visited.end()) {
                            queue.push_back(next);
                        }
                    }
                }
            }
        }
        // 找到的话在上面就返回了，跑到这里表示没找着，返回 0
        return 0;
    }
private:
    vector<string>& transferList(string& word, unordered_set<string>& wordsSet, unordered_map<string, vector<string>>& caches) {
        if (caches.find(word) != caches.end()) {
            // 有缓存，直接使用缓存
            return caches[word];
        }

        vector<string> nextSet;
        // 无缓存，生成缓存
        if (wordsSet.size() < 26) {
            // 通过字典计算
            for (string right : wordsSet) {
                if (canTransferTo(word, right)) {
                    nextSet.push_back(right);
                }
            }
        } else {
            // 逐字符替换
            for (int i = 0; i < word.size(); i++) {
                char old = word[i];
                for (char choice = 'a'; choice <= 'z'; choice++) {
                    word[i] = choice;
                    if (wordsSet.find(word) != wordsSet.end()) {
                        nextSet.push_back(word);
                    }
                }
                word[i] = old;
            }
        }
        caches[word] = nextSet;
        return caches[word];
    }

    bool canTransferTo(string& left, string& right) {
        int diff = 0;
        for (int i = 0; i < left.size(); i++) {
            if (left[i] != right[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    void print(deque<string>& queue) {
        for (string word : queue) {
            cout << word << " ";
        }
        cout << endl;
    }
};

// 考察要点: 广度优先搜索

// 实现难点: 根据题意，计算得到单词的转换关系，即从 word => nextWords 的关系图
//          当字典很大的情况下，容易超时(单词转换算法的调优、按需生成单词转换表)

// 边界场景: 
// 1. wordList 不包含 endWord 时，提前终止
// 2. 引入 visited 避免重复选中已访问过的单词

// 使用到的数据结构:

// deque: 双端队列
//      1. push_back 往对尾添加元素
//      2. empty 队列是否为空
//      3. size 获取队列的大小
//      4. front 访问队列的第一个元素
//      5. pop_front 移除队列的第一个元素

// set: 基于红黑树的集合，内部有序
// unordered_set: 基于哈希的集合，内部无需
//      1. insert 插入元素
//      2. size 获取集合大小
//      3. find 查找元素是否在集合中，当返回值 == set.end() 时，表示没找到
