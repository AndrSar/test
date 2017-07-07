#include "../include/test.hpp"

#include <iostream>
#include <list>

using namespace test;


class ConsoleLogger : public Logger
{
public:
    void log(const std::string &str) override
    {
        std::cout << str << std::endl;
    }
};


int main(int argc, const char * const * argv)
{
    TestSuite suite{"My Suite"};

    using MyCase = struct : TestSuite::Case {
        void operator()()
        {
            assert.equal("WTF1", 1, 2);
            assert.not_equal("WTF2", 1, 1);
            assert.equal_sequences("WTF3", std::list<int>{1, 2, 3, 4}, std::list<int>{1, 2, 5, 4});
        }
    };

    suite.add_case<MyCase>("Simple Case");

    ConsoleLogger logger;
    execute({&suite}, logger);

    return 0;
}