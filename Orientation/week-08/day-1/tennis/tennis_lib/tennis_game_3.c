#include "tennis_game_3.h"
#include <string.h>
#include <stdlib.h>

tennis_game_3_t create_tennis_game_3(const char *name1, const char *name2)
{
    tennis_game_3_t result = {
            0,
            0,
            (char *) calloc(strlen(name1) + 1, 1),
            (char *) calloc(strlen(name2) + 1, 1)
    };
    strcpy(result.player_name1, name1);
    strcpy(result.player_name2, name2);
    return result;
}

void won_point_3(tennis_game_3_t *tennis_game, const char *player_name)
{
    strcmp(player_name, "player1") ? tennis_game->points_2++ : tennis_game->points_1++;
}

const char *get_score_3(tennis_game_3_t *tennis_game)
{
    char *score;

    if (tennis_game->points_1 < 4 && tennis_game->points_2 < 4) {
        static const char *point[] = {"Love", "Fifteen", "Thirty", "Forty"};
        char temp_score[20];
        strcpy(temp_score, point[tennis_game->points_1]);
        if (tennis_game->points_1 == tennis_game->points_2) {
            strcat(temp_score, "-All");
        } else {
            strcat(temp_score, "-");
            strcat(temp_score, point[tennis_game->points_2]);
        }
        score = (char *) calloc(strlen(temp_score) + 1, sizeof(char));
        strcpy(score, temp_score);
        return score;
    } else {
        if (tennis_game->points_1 == tennis_game->points_2)
            return "Deuce";

        char temp_score[20];
        (tennis_game->points_1 > tennis_game->points_2) ? strcpy(temp_score, tennis_game->player_name1) : strcpy(temp_score, tennis_game->player_name2);

        char temp_score2[15];
        ((tennis_game->points_1 - tennis_game->points_2) * (tennis_game->points_1 - tennis_game->points_2) == 1) ? strcpy(temp_score2, "Advantage ") : strcpy(temp_score2, "Win for ");

        score = (char *) calloc(strlen(temp_score) + strlen(temp_score2) + 1, sizeof(char));
        strcpy(score, temp_score2);
        strcat(score, temp_score);
        return score;
    }
}