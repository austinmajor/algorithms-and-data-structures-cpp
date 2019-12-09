class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	int index = 0;
	int processed = 0;

	// prepare stack 
	vector<int> st;

	while(processed < popped.size()){
		// check the stack top first 
		if (st.size() > 0 && st.back() == popped[processed]) {
			st.pop_back();
			processed++;
		}
		else {  // push to stack until ele is found 
			while (index < pushed.size()) {
				st.push_back(pushed[index]);
				index++;

				if (st.back() == popped[processed])
					break;
			}
		}

		if (index == pushed.size() && st.size() > 0 && st.back() != popped[processed])
			return false; 
	}

	return true;
    }
};