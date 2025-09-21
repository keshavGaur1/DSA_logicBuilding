class MovieRentingSystem {
    unordered_map<long long, int> price_map;
    unordered_map<int, set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;

    long long key(int shop, int movie) {
        return ((long long)shop << 20) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            price_map[key(shop,movie)] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        auto &s = available[movie];
        int cnt = 0;
        for (auto &[price, shop] : s) {
            res.push_back(shop);
            if (++cnt == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = price_map[key(shop,movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = price_map[key(shop,movie)];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &[price, shop, movie] : rented) {
            res.push_back({shop, movie});
            if (++cnt == 5) break;
        }
        return res;
    }
};