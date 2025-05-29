#include "package.hpp"
#include "utils.hpp"
#include "design.hpp"
#include "env.hpp"

int main()
{
    // JsonManager jm("src/json/data.json");

    // // Set values
    // jm.set("user_coordinate", "1,3|1,2|1,1|2,1|2,2");
    // nlohmann::json j;
    // j["1"] = "1,2|1,1|1,3|";
    // j["2"] = "1,2|1,1|1,3|";
    // jm.set("enemy", j);
    // jm.set("is_active", true);

    // // Get values
    // std::string name = jm.get<std::string>("name");
    // int age = jm.get<int>("age", 0);
    // bool isActive = jm.get<bool>("is_active", false);
    // vector<string> coordinate = split(jm.get<std::string>("user_coordinate"), '|');

    // // Output to verify
    // std::cout << "Name: " << name << "\nAge: " << age << "\nActive: " << isActive << '\n' << "\nCoordinate: " << coordinate;

    // // Save the data to file
    // jm.save();

    // // Print the full JSON
    // jm.print();
    // menuUtama();

    
    runMap(10, 10);
}
