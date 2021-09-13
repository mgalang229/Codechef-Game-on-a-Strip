#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int cnt = 0;
		// 'first_max' = store the largest zero-segment
		// 'second_max' = store the second largest zero-segment
		int first_max = 0;
		int second_max = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				// if the current element is 1, then check if 'cnt' is greater than 0
				// if yes, then check if 'cnt' is STRICTLY greater than 'first_max'
				// if yes, then store the value of 'first_max' to 'second_max'
				// and update the value of 'first_max' (store the value of 'cnt')
				// otherwise, if 'cnt' is only greater than the 'second_max', then
				// store the the value of 'cnt' to it
				// don't forget to reset the value of 'cnt' to zero
				if (cnt > 0) {
					if (cnt > first_max) {
						second_max = first_max;
						first_max = cnt;
					} else if (cnt > second_max) {
						second_max = cnt;
					}
					cnt = 0;
				}
			} else {
				// if the current element is 0, then keep incrementing 'cnt'
				cnt += 1;
			}
		}
		// in order for Nayeon to win, then the largest zero-segment ('first_max') must be
		// an odd number and the second largest zero-segment ('second_max') should be
		// smaller than the number of free cells of Nayeon in the largest zero-segment ('first_max')
		// let l = largest zero-segment (must be odd as well)
		// ceil(l / 2) = formula for free cells of Nayeon
		cout << ((first_max % 2 != 0) && (second_max < (first_max + 1) / 2) ? "Yes" : "No") << '\n';
	}
	return 0;
}
