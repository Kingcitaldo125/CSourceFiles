#include <chrono>
#include <iostream>
#include <list>
#include <unordered_set>
#include <unordered_map>

static inline long make_timepoint() {
  return static_cast<long>(
      std::chrono::system_clock::now().time_since_epoch().count());
}

struct Item {
  Item() {
    const auto tp = make_timepoint();
    timepoint = tp;
  }
  explicit Item(int i) {
    const auto tp = make_timepoint();
    timepoint = tp;
    value = i;
  }

  int value;
  long timepoint;
};

class LRU {
public:
  LRU() = delete;
  explicit LRU(int cap) : c_capacity(0), total_capacity(cap) {}

  void put(int key, int val);
  int get(int key);

protected:
  void add(int key, int val);
  void handle_overflow();
  void add_key(int key, int val);

private:
  std::unordered_set<int> keys;
  std::unordered_map<int, Item> keymap;
  std::unordered_map<long, int> keymap_r;

  std::list<long> timestamps;

  int c_capacity;
  int total_capacity;
};

void LRU::add(int key, int val) {
  Item i(val);

  std::cout << "I: '" << key << "' (" << i.timepoint << ")" << std::endl;

  keymap[key] = i;
  keymap_r[i.timepoint] = key;

  keys.insert(key);
  timestamps.push_back(i.timepoint);

  ++c_capacity;
}

void LRU::handle_overflow() {
  const auto l_timepoint = timestamps.front();
  const auto lru_key = keymap_r[l_timepoint];

  std::cout << "Erasing '" << lru_key << "' (" << l_timepoint << ")"
            << std::endl;

  keymap_r.erase(l_timepoint);
  keymap.erase(lru_key);
  keys.erase(lru_key);

  timestamps.pop_front();

  --c_capacity;
}

void LRU::add_key(int key, int val) {
  if (timestamps.size() == 0) {
    add(key, val);
    return;
  }

  const auto kmv = keymap[key].value;

  // Update the current key to have the most recent value
  if (keymap[key].timepoint == timestamps.front()) {
    handle_overflow();
  }

  add(key, val == -1 ? kmv : val);
}

void LRU::put(int key, int val) {
  if (c_capacity >= total_capacity && c_capacity > 0) {
    std::cout << "Overflow '" << key << "' (" << val << ")" << std::endl;
    handle_overflow();
  }

  // Update
  if (keys.find(key) != keys.end()) {
    add_key(key, -1);
    return;
  }

  // Add
  add_key(key, val);
}

int LRU::get(int key) {
  if (keys.find(key) != keys.end()) {
    // Update
    add_key(key, -1);

    // Actually get the value based on the key
    return keymap[key].value;
  }

  return -1;
}

inline void run() {
  LRU lr(2);

  lr.put(1, 1);
  lr.put(2, 2);

  std::cout << lr.get(1) << "\n";

  lr.put(3, 3);

  std::cout << lr.get(2) << "\n";

  lr.put(4, 4);

  std::cout << "lr.get(1) " << lr.get(1) << "\n";
  std::cout << "lr.get(3) " << lr.get(3) << "\n";
  std::cout << "lr.get(4) " << lr.get(4) << "\n";
}

int main() {
  run();

  return 0;
}
