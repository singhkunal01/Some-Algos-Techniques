	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		//instead of storing exact value store the index for that value so that we can easily take the width by using formula
		/*
		width = (nextSmaller-prevSmaller+1);
		area = elem * width;
		*/
		vector<int> nextSmaller(n), prevSmaller(n);
		stack<int> st;

		//finding the next smaller element for each value
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() and heights[st.top()] >= heights[i])  st.pop();
			nextSmaller[i] = (!st.empty()) ? st.top() - 1 : n - 1;
			//subtracting 1 because our boundary starts from the immediate next of that next smaller
			print(st)

			st.push(i);
		}
		//finding the previous smaller element for each
		stack<int> st2;
		for (int  i = 0; i < n; i++) {
			while (!st2.empty() and heights[st2.top()] >= heights[i]) st2.pop();
			prevSmaller[i] = (!st2.empty()) ? st2.top() + 1 : 0;
			//adding 1 because our boundary starts from the immediate next of that previous smaller
			st2.push(i);
		}
		long long maxArea = 0;
		for (int i = 0; i < n; i++) {
			long long area = (nextSmaller[i] - prevSmaller[i] + 1) * heights[i];
			maxArea = max(area, maxArea);
		}
		return maxArea;
	}
