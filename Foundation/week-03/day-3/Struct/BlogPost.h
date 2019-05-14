//
// Created by hun46 on 2019. 04. 17..
//

#ifndef STRUCT_BLOGPOST_H
#define STRUCT_BLOGPOST_H

#include <string>


class BlogPost {
public:
    BlogPost(std::string aut, std::string tit, std::string tex, std::string pub);

    void setAuthorName(const std::string &authorName);

    void setTitle(const std::string &title);

    void setText(const std::string &text);

    void setPublicationDate(const std::string &publicationDate);

    const std::string &getAuthorName() const;

    const std::string &getTitle() const;

    const std::string &getText() const;

    const std::string &getPublicationDate() const;

private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;

};


#endif //STRUCT_BLOGPOST_H
