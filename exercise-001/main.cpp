#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

int count = 87;

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        srand((unsigned) time(NULL));
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count);
        app.parse(argc, argv);

        std::vector<int> random_nums;
        
        for (int i = 0; i < count; i++)
        {
            int random = 1 + (rand() % 100);
            random_nums.push_back(random);
            std::cout << "Random numbers:" << random << "\n";
        }
        auto start = std::chrono::system_clock::now();
        sort(random_nums.begin(), random_nums.end());
        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        fmt::print("vektor:\n{}\n",fmt::join(random_nums, " und\n"));
        fmt::print("Vergangene Zeit:{}\n", elapsed);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
