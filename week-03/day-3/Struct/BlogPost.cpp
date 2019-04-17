//
// Created by hun46 on 2019. 04. 17..
//

#include "BlogPost.h"

BlogPost::BlogPost(std::string aut, std::string tit, std::string tex, std::string pub)
{
this->authorName = aut;
this->title = tit;
this->text = tex;
this->publicationDate = pub;
}