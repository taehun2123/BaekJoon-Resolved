#include <bits/stdc++.h>

using namespace std;

struct Date {
  int year;
  int month;
  int day;

  static Date parseDate(const string& s) {
    return {
      stoi(s.substr(0, 4)),
      stoi(s.substr(5, 2)),
      stoi(s.substr(8, 2))
    };
  }

  bool isAfterOrEqual(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day >= other.day;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string currentDateStr;
  cin >> currentDateStr;

  Date currentDate = Date::parseDate(currentDateStr);

  int n; cin >> n;

  int validCount = 0;
  while (n--) {
    string giftDateStr; cin >> giftDateStr;

    Date giftDate = Date::parseDate(giftDateStr);

    if (giftDate.isAfterOrEqual(currentDate))
      validCount++;
  }

  cout << validCount << "\n";

  return 0;
}