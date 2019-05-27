#include "tennis_game_2.h"
#include <string.h>
#include <stdlib.h>

tennis_game_2_t create_tennis_game_2(const char *player1_name, const char *player2_name)
{
    tennis_game_2_t result;

    strcpy(result.player1_name, player1_name);
    strcpy(result.player2_name, player2_name);
    result.P1res = "";
    result.P2res = "";
    result.P1point = 0;
    result.P2point = 0;

    return result;
}

void won_point_2(tennis_game_2_t *tennis_game, const char *player_name)
{
    if (strcmp("player1", player_name) == 0) {
        tennis_game->P1point++;
    } else {
        tennis_game->P2point++;
    }
}

const char *get_score_2(tennis_game_2_t *tennis_game)
{
    char *score = NULL;
    char partial_scores[][8] = {
            {"Love"},
            {"Fifteen"},
            {"Thirty"},
            {"Forty"}
    };

    if (tennis_game->P1point == tennis_game->P2point && tennis_game->P1point < 4) {
        for (int i = 0; i < 4; ++i) {
            if (tennis_game->P1point == i) {
                score = (char *) calloc(18, 1);
                strcpy(score, partial_scores[i]);
                strcat(score, "-All");
                return score;
            }
        }
    }
    if (tennis_game->P1point == tennis_game->P2point && tennis_game->P1point > 3) {
        score = (char *) calloc(6, 1);
        strcpy(score, "Deuce");
        return score;
    }

    if (tennis_game->P1point >= 4 || tennis_game->P2point >= 4) {

        int minusResult = tennis_game->P1point - tennis_game->P2point;

        if (minusResult == 1 || minusResult == -1) {
            score = (char *) calloc(18, 1);
            if (minusResult == 1) {
                score = "Advantage player1";

            } else {
                score = "Advantage player2";
            }

        } else {
            score = (char *) calloc(15, 1);
            if (minusResult >= 2) {
                score = "Win for player1";
            } else {
                score = "Win for player2";
            }
        }
        return score;
    }

    for (int i = 0; i < 4; ++i) {
        if (tennis_game->P1point == i) {
            tennis_game->P1res = partial_scores[i];
            score = (char *) calloc(15, 1);
            strcpy(score, partial_scores[i]);
            strcat(score, "-");
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (tennis_game->P2point == i) {
            tennis_game->P2res = partial_scores[i];
            strcat(score, partial_scores[i]);
            return score;
        }
    }
}