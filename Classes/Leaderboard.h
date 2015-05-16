#pragma once

struct Entry {
    std::string name;
    int score;
};

class Leaderboard
{
public:
    static void push(std::string name, int score);
    static void pull(int much = 0);

    static std::vector<Entry> scores;
};

