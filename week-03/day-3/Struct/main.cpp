#include <iostream>
#include <BlogPost.h>


class PostIt {
    std::string backgroundColor;
    std::string textColor;
    std::string text;
public:
    PostIt(std::string bC = "white", std::string tC = "black", std::string t = "")
    {
        this->backgroundColor = bC;
        this->textColor = tC;
        this->text = t;
    }
};

int main()
{
    PostIt p1("orange", "blue", "Idea 1");
    PostIt p2("pint","black", "Awesome");
    PostIt p3("yellow", "green", "Superb!");

    BlogPost b1("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost b2("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    BlogPost b3("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing. ", "2017.03.28.");
    BlogPost b4("", "", "", "");

    return 0;
}