#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

template<typename T, typename Info>
class Repository {
public:
    Repository() = default;
    Repository(const Repository&) = default;
    Repository(Repository&&) noexcept = default;
    Repository& operator=(const Repository&) = default;
    Repository& operator=(Repository&&) noexcept = default;
    ~Repository() = default;

    // Add a new item to the repository
    void add(const T& item, const Info& info) {
        // find the item in the vector
        auto it = std::find(items.begin(), items.end(), item);

        // if the item is not found, add it to the vector
        if (it == items.end()) {
            items.push_back(item);
            infoList.push_back(info);
        } else { // if the item is found, update the info
            auto index = std::distance(items.begin(), it);
            infoList[index] = info;
        }
    }

    // Add a list of new items to the repository
    void add(const std::vector<T>& newItems, const std::vector<Info>& newInfo) {
        // for each item in the list, add it to the repository
        for (size_t i = 0; i < newItems.size(); ++i) {
            add(newItems[i], newInfo[i]);
        }
    }

    // Get the info of an item
    int getOrder(const T& item) const {
        // find the item in the vector
        auto it = std::find(items.begin(), items.end(), item);

        // if the item is not found, return -1
        if (it == items.end()) {
            return -1;
        } else {
            // if the item is found, return the index
            return std::distance(items.begin(), it);
        }
    }

    // remove an item from the repository
    void remove(const T& item) {
        // find the item in the vector
        auto it = std::find(items.begin(), items.end(), item);

        // if the item is found, remove it from the vector
        if (it != items.end()) {
            auto index = std::distance(items.begin(), it);
            items.erase(it);
            infoList.erase(infoList.begin() + index);
        }
    }


    // remove a list of items from the repository
    void remove(const std::vector<T>& removeItems) {
        for (const T& item : removeItems) {
            remove(item);
        }
    }

    // get the size of the repository
    size_t size() const {
        return items.size();
    }

private:
    std::vector<T> items;
    std::vector<Info> infoList;
};

#endif
