#include <bits/stdc++.h>
#define ll long long
using namespace std;


// Function to determine the minimum possible maximum number of parcels
ll getMinMaxParcels(ll extra_parcels, vector<ll>& parcels) {
    ll sum = 0;
    for (const auto& it: parcels)
        sum += it;
    
    sum += extra_parcels;
    ll parcel_per_agent = sum / parcels.size();
    ll remaining = sum % parcels.size();
    return (remaining == 0)? parcel_per_agent : parcel_per_agent + 1;
}

int main() {
    ll n, extra_parcels; 
    cin >> n >> extra_parcels;
    
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];

    ll ans = getMinMaxParcels(extra_parcels, arr);
    cout << "Result: " << ans << endl; 
}
