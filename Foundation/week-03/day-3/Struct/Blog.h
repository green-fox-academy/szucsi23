//
// Created by hun46 on 2019. 04. 17..
//

#ifndef THREEMORECLASSES_FARM_H
#define THREEMORECLASSES_FARM_H

#include "BlogPost.h"
#include <vector>


class Blog {

public:
    void add(BlogPost);
    void deletepost(int);
    void update(int, BlogPost);

private:
    std::vector<BlogPost> posts;


};


#endif //THREEMORECLASSES_FARM_H