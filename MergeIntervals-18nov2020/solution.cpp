class Solution {
private: void inserter(std::list<std::vector<int>>& list1, std::vector<int>& value) {
    std::list<std::vector<int>>::iterator it;
    it = list1.begin();
    while(it != list1.end()){
        if(value[0]<(*it)[0]) {
            list1.insert(it,value);
            break;
        }
        it++;
    }
    if (it == list1.begin())
        list1.insert(it,value);

    return;
}

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::list<std::vector<int>> listAnswer;
        int size = intervals.size();
        std::vector<bool> visited(size, false);
        for (int i = 0; i < size; i++) {
            if (visited[i])
                continue;
            else
                visited[i] = true;

            std::vector<int> v(2);
            v[0] = intervals[i][0];
            v[1] = intervals[i][1];

            for (int j = 0; j < size; j++) {
                if (intervals[i][0] <= intervals[j][1] && intervals[j][0] < intervals[i][0]) {
                    visited[j] = true;
                    v[0] = intervals[j][0];
                }
                if (intervals[i][1] >= intervals[j][0] && intervals[j][1] > intervals[i][1]) {
                    visited[j] = true;
                    v[1] = intervals[j][1];
                }
            }
           this->inserter(listAnswer,v);
        }
        std::vector<std::vector<int>> answer(listAnswer.begin(),listAnswer.end());
        return answer;
    }
};
