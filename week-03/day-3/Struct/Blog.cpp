//
// Created by hun46 on 2019. 04. 17..
//

#include "Blog.h"

void Blog::add(BlogPost p)
{
    this->posts.push_back(p);
}

void Blog::deletepost(int index)
{
    std::vector<BlogPost>::iterator iterator = this->posts.begin();
    int i = 0;
    for (; iterator < this->posts.end(); iterator++) {
        if(i == index) {
            this->posts.erase(iterator);
        }
        i++;
    }
}

void Blog::update(int index, BlogPost bp)
{
    std::vector<BlogPost>::iterator iterator = this->posts.begin();
    int i = 0;
    for (; iterator < this->posts.end(); iterator++) {
        if(i == index) {
            iterator->setAuthorName(bp.getAuthorName());
            iterator->setPublicationDate(bp.getPublicationDate());
            iterator->setText(bp.getText());
            iterator->setTitle(bp.getTitle());
        }
        i++;
    }
}
