// JsonManager.hpp

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <package/nlohmann/json.hpp>

class JsonManager {
private:
    std::string filename;
    nlohmann::json data;

public:
    // Constructor that loads data from file
    JsonManager(const std::string& file) : filename(file) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            try {
                inFile >> data;
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse JSON: " << e.what() << '\n';
                data = nlohmann::json::object(); // default to empty object
            }
        } else {
            std::cerr << "File not found. Starting with empty JSON.\n";
            data = nlohmann::json::object();
        }
    }

    // Get a value from JSON (returns default if not found)
    template <typename T>
    T get(const std::string& key, T defaultValue = T()) const {
        if (data.contains(key)) {
            return data.at(key).get<T>();
        }
        return defaultValue;
    }

    // Set a value in the JSON
    template <typename T>
    void set(const std::string& key, const T& value) {
        data[key] = value;
    }

    // Save the current data back to the file
    void save() const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << data.dump(4); // pretty print with 4-space indent
        } else {
            std::cerr << "Failed to open file for writing: " << filename << '\n';
        }
    }

    // Print JSON for debugging
    void print() const {
        std::cout << data.dump(4) << '\n';
    }
};
