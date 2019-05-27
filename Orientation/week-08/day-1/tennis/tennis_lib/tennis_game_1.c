#include "tennis_game_1.h"
#include <string.h>
#include <stdlib.h>

tennis_game_1_t create_tennis_game_1(const char *player1_name, const char *player2_name)
{
    tennis_game_1_t result;

    result.player1_name = player1_name;
    result.player2_name = player2_name;
    result.m_score1 = 0;
    result.m_score2 = 0;

    return result;
}

void won_point_1(tennis_game_1_t *tennis_game, const char *player_name)
{
    if (player_name == tennis_game->player1_name) {
        tennis_game->m_score1 += 1;
    } else {
        tennis_game->m_score2 += 1;
    }
}

char *get_score_1(tennis_game_1_t *tennis_game)
{
    char *score = NULL;
    int tempScore = 0;

    char equal_scores[][12] = {
            {"Love-All"},
            {"Fifteen-All"},
            {"Thirty-All"},
            {"Forty-All"},
            {"Deuce"}
    };

    char personal_scores[][8] = {
            {"Love"},
            {"Fifteen"},
            {"Thirty"},
            {"Forty"}
    };

    if (tennis_game->m_score1 == tennis_game->m_score2) {

        for (int i = 0; i < 5; ++i) {
            if(tennis_game->m_score1 == i) {
                score = (char *) calloc (sizeof(equal_scores[i]), 1);
                strcat(score, equal_scores[i]);
                //TODO: why doesn't return
                //score = equal_scores + i;
            }
        }

    } else if (tennis_game->m_score1 >= 4 || tennis_game->m_score2 >= 4) {

        int minusResult = tennis_game->m_score1 - tennis_game->m_score2;

        if(minusResult == 1 || minusResult == -1) {
            score = (char *) calloc(18, 1);
            if(minusResult == 1)score = "Advantage player1";
            else score = "Advantage player2";

        }else {
            score = (char *) calloc(15, 1);
            if(minusResult >= 2) score = "Win for player1";
            else score = "Win for player2";
        }

    } else {

        for (int i = 0; i < 4; ++i) {
            if(tennis_game->m_score1 == i) {
                score = (char *) calloc ((sizeof(personal_scores[i]) * 2) - 1, 1);
                strcat(score, personal_scores[i]);
                strcat(score, "-");
            }
        }
        for (int i = 0; i < 4; ++i) {
            if(tennis_game->m_score2 == i) {
                strcat(score, personal_scores[i]);
            }
        }
    }
    return score;
}