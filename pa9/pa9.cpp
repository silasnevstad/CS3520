#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

// function object to print prices of an item
struct print_item_prices {
    string item_name;
    print_item_prices(const string& name) : item_name(name) {}
    void operator() (const pair<string, double>& store_price) {
        // cout << store_price.first << ": " << store_price.second << endl;
        // print item name and price neatly using setw
        cout << setw(15) << left << store_price.first << setw(10) << right << store_price.second << endl;
    }
};

struct print_best_stores {
    void operator() (const pair<string, string>& store_price) {
        // cout << store_price.first << ": " << store_price.second << endl;
        // print item name and price neatly using setw
        cout << setw(15) << left << store_price.first << setw(10) << right << store_price.second << endl;
    }
};

int main() {
    // create nested container to store prices
    map<string, map<string, double>> prices = {
        {"iPhone14", {{"BestBuy", 999.99}, {"Amazon", 978.99}, {"eBay", 1009.99}, {"OfficeMax", 1020.0}, {"Staples", 1005.5}}},
        {"iPad Pro", {{"BestBuy", 1499}, {"Amazon", 1459.98}, {"eBay", 1545.99}, {"OfficeMax", 1515.5}, {"Staples", 1532.0}}},
        {"Headphones", {{"BestBuy", 299}, {"Amazon", 289.99}, {"eBay", 315.99}, {"OfficeMax", 309.5}, {"Staples", 308.0}}},
        {"Back Roller", {{"BestBuy", 39.99}, {"Amazon", 45.99}, {"eBay", 39.49}, {"OfficeMax", 41.0}, {"Staples", 44.99}}},
        {"Bike", {{"BestBuy", 599.99}, {"Amazon", 620.0}, {"eBay", 575.99}, {"OfficeMax", 610.0}, {"Staples", 599.0}}}
    };

    // print prices of each store in the nested container as a table
    cout << setw(15) << left << "Name" << setw(10) << right << "BestBuy" << setw(10) << right << "Amazon" << setw(10) << right << "eBay" << setw(10) << right << "OfficeMax" << setw(10) << right << "Staples" << endl;
    for (const auto& store : prices) {
        cout << setw(15) << left << store.first;
        for (const auto& item_price : store.second) {
            cout << setw(10) << right << setprecision(2) << fixed << item_price.second;
        }
        cout << endl;
    }

    // create a list of stores
    vector<string> stores = {"BestBuy", "Amazon", "eBay", "OfficeMax", "Staples"};

    // print prices of each store for each item
    cout << endl << "Prices of each item from each store:" << endl;
    // loop through the list of stores creating a table of prices for each store
    for (const auto& store : stores) {
        cout << endl << store << ":" << endl;
        // loop through the nested container to find the prices for each item from the current store
        for (const auto& item : prices) {
            // print the item name and price
            cout << setw(15) << left << item.first << setw(10) << right << setprecision(2) << fixed << item.second.at(store) << endl;
        }
    }

    
    // calculate and print average price for each item
    vector<pair<string, double>> avg_prices;
    for (const auto& item_prices : prices) {
        double sum = accumulate(item_prices.second.begin(), item_prices.second.end(), 0.0,
            [](double acc, const pair<string, double>& store_price) { return acc + store_price.second; });
        double avg = sum / item_prices.second.size();
        avg_prices.push_back(make_pair(item_prices.first, avg));
    }
    sort(avg_prices.begin(), avg_prices.end(), [](const pair<string, double>& p1, const pair<string, double>& p2) { return p1.second < p2.second; });

    // print average prices of each item using setw
    cout << endl << "Average prices of each item:" << endl;
    for_each(avg_prices.begin(), avg_prices.end(), print_item_prices(""));
    cout << endl;
    
    // calculate what store has the best price for each item
    vector<pair<string, string>> best_items;
    for (const auto& item_prices : prices) {
        auto best_price = min_element(item_prices.second.begin(), item_prices.second.end(),
            [](const pair<string, double>& p1, const pair<string, double>& p2) { return p1.second < p2.second; });
        best_items.push_back(make_pair(item_prices.first, best_price->first));
    }

    // print best prices of each item and store using setw
    cout << endl << "Best prices of each item:" << endl;
    for_each(best_items.begin(), best_items.end(), print_best_stores());
    cout << endl;


    return 0;
}