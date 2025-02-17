ll dnc(ll left, ll right, ll totalh) {
    if (right < left || left < 0 || right >= n) return 0;
    if (left == right) return min((arr[left] - totalh)*x, y);
    ll ans = (right-left+1)*y, minn=INT_MAX,minindex;
    for (ll q = left; q <= right; q++) {
        if (arr[q] < minn) {
            minn = arr[q]; minindex = q;
        }
    }
    ans = min(ans, (minn - totalh)*x + dnc(left, minindex-1, minn) + dnc(minindex+1, right, minn));
    //cout << left << " " << right << " " << minn << " " << minindex << "\n";
    return ans;
}