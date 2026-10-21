// AI-generated in response to issue #1. No API keys, just birthday cake.
#include <iostream>
#include <string>

std::string generate_cake(unsigned candles)
{
    std::string cake = "  ";
    for (unsigned i = 0; i < candles; ++i) cake += "i ";
    cake += "\n .";
    for (unsigned i = 0; i < candles; ++i) cake += "--";
    cake += ".\n |";
    for (unsigned i = 0; i < candles; ++i) cake += "==";
    cake += "|\n '";
    for (unsigned i = 0; i < candles; ++i) cake += "--";
    cake += "'\n";
    return cake;
}

int main()
{
    constexpr unsigned candles = 5; // Decorative. Birthday age remains private.
    std::cout
        << "Klefstad45C Generative Birthday Intelligence\n"
        << "Model: cake-45c | Parameters: butter, sugar, questionable decisions\n"
        << "Human-code complaint received. Allocating additional homework...\n\n"
        << generate_cake(candles)
        << "\nHappy birthday, ezshrimps!\n"
        << "Your gift: one more C++ assignment. You're welcome.\n"
        << "Inference cost: O(candles). Tuition sold separately.\n";
}
