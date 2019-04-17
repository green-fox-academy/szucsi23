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

void BlogPost::setAuthorName(const std::string &authorName)
{
    BlogPost::authorName = authorName;
}

void BlogPost::setTitle(const std::string &title)
{
    BlogPost::title = title;
}

void BlogPost::setText(const std::string &text)
{
    BlogPost::text = text;
}

void BlogPost::setPublicationDate(const std::string &publicationDate)
{
    BlogPost::publicationDate = publicationDate;
}

const std::string &BlogPost::getAuthorName() const
{
    return authorName;
}

const std::string &BlogPost::getTitle() const
{
    return title;
}

const std::string &BlogPost::getText() const
{
    return text;
}

const std::string &BlogPost::getPublicationDate() const
{
    return publicationDate;
}
