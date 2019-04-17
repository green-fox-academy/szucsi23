//
// Created by hun46 on 2019. 04. 17..
//

#ifndef STRUCT_BLOGPOST_H
#define STRUCT_BLOGPOST_H

#include <string>


class BlogPost {
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;
public:
    BlogPost(std::string aut, std::string tit, std::string tex, std::string pub);

};


#endif //STRUCT_BLOGPOST_H
