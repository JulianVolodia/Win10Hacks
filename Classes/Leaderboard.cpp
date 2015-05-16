//#include "pch.h"
#include "Leaderboard.h"
#include "cocos2d.h"
#include "HttpClient.h"

USING_NS_CC;

std::vector<Entry> Leaderboard::scores;

void Leaderboard::push(std::string name, int score)
{
    network::HttpRequest* request = new network::HttpRequest();
    request->setUrl("http://www.daltostronic.com/win10hacks/submit.php");

    request->setRequestType(network::HttpRequest::Type::POST);
    request->setResponseCallback([=](network::HttpClient* client, network::HttpResponse* response) {
        CCLOG("Done");
        // dump data
        std::vector<char> *buffer = response->getResponseData();
        printf("Http Test, dump data: ");
        for (unsigned int i = 0; i < buffer->size(); i++)
        {
            CCLOG("%c", (*buffer)[i]);
        }
    });

    const char* postData = String::createWithFormat("name=%s&score=%d", name.c_str(), score)->getCString();
    request->setRequestData(postData, strlen(postData));

    request->setTag("POST push");
    network::HttpClient::getInstance()->send(request);
    request->release();
}

void Leaderboard::pull(int much)
{
    scores.clear();

    network::HttpRequest* request = new network::HttpRequest();
    request->setUrl("http://www.daltostronic.com/win10hacks/get.php");

    request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
    request->setResponseCallback([=](network::HttpClient* client, network::HttpResponse* response) {
        CCLOG("Pull");
        // dump data
        std::vector<char> *buffer = response->getResponseData();
        CCLOG("Http Test, dump data: ");
        std::string result = "";
        for (unsigned int i = 0; i < buffer->size(); i++)
        {
            result += std::string(String::createWithFormat("%c", (*buffer)[i])->getCString());
        }
        CCLOG(result.c_str());

        std::string stringdelimiter = " ";
        std::string scoresdelimiter = "\n";

        size_t pos = 0;
        while ((pos = result.find(stringdelimiter)) != std::string::npos) {
            Entry e;

            e.name = result.substr(0, pos);
            result.erase(0, pos + stringdelimiter.length());

            pos = result.find(scoresdelimiter);
            e.score = std::atoi(result.substr(0, pos).c_str());
            result.erase(0, pos + scoresdelimiter.length());

            scores.push_back(e);
        }

        for (auto score : scores)
        {
            CCLOG(String::createWithFormat("%s: %d", score.name.c_str(), score.score)->getCString());
        }
    });

    if (much > 0)
    {
        const char* getData = String::createWithFormat("much=%d", much)->getCString();
        request->setRequestData(getData, strlen(getData));
    }

    request->setTag("GET pull");
    cocos2d::network::HttpClient::getInstance()->send(request);
    request->release();
}