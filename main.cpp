/*
This is a program that will predict how long it should take me to catch up to the one piece anime
assuming that i watch 7 episodes per day and the one piece anime realeses one episode every week
and the anime has 1080 episode from the moment i started watching the one piece anime
*/

#include <iostream>
#include <string>
#include <iomanip>

// FUNCTION PROTOTYPES
int episodes_watched_per_week(int); // this function will calculate how many episodes I watched in one week
void new_episode_added(); // this function will check if one week has passed and if so then the number of episodes left will increase
void watching_the_anime(); //this function will increase the number of episdes watched and decrease the number of episodes left 

// VARIABLE DECLARATIONS
int episodes_per_day;   //the user will input how many episodes they want to watch every day
int episodes_watched = 0;   //this will store the number of episodes watced and will be used to determine the number of episodes left
const int EPISDES_ADDED_PER_WEEK = 1;
int present_number_of_episodes;  // the user will input how many episodes they are at the present time 
int number_of_episodes_left; // this will store the number of episodes left and it will decrease by the number of episodes watched
int time_to_catchup;        //this will store the time it will take to catch up to the anime
int number_of_weeks = 0;    //this will be incremented every time a new episode is added
int average_number_of_episodes;   //this will store the number of episodes watched in one week

int main()
{
    std::cout << std::setw(15) << "This is a program that will predict how long it\
     should take me to catch up to the one piece anime depending on the number of episodes i watch every day\n";
    std::cout << "If I watch: ";
    std::cin >> episodes_per_day;
    std::cout << " episodes per day and there are: ";
    std::cin >> present_number_of_episodes;
    number_of_episodes_left = present_number_of_episodes; 
    std::cout << " episodes of one piece for me to watch and one new episode coming out every week.\n";
    /* there are one 1080 episodes of one piece when i started and the more episodes i watch, the less episodes
    */
    //Let's say i want to watch 7 episodes everyday and there are 1080 episodes of one piece rigth now 
    //and every week a new episode is added when i watch a episode of one piece the number of episodes
    //left should decrease by the number of episodes that i watched, but after a week has passed, one episdoe
    //should be added to hte number of episodes left

    average_number_of_episodes = episodes_watched_per_week(episodes_per_day)/7;
    watching_the_anime();
    std::cout << "It will take you: " << time_to_catchup << " weeks to catch up with the One Piece Anime";

    system("pause>0");
    return 0;
}

//FUNCTION DEFINTIONS
int episodes_watched_per_week(int episodes_watched_per_day)
{
    int episodes_watched_per_week = episodes_watched_per_day * 7;
    return episodes_watched_per_week;
}

void  new_episode_added()
{
    if (episodes_watched % average_number_of_episodes == 0)   // if the remainder of the number of episodes watched divided by the average_number_of_episodes
    {
        ++number_of_episodes_left;                            //that means that the number of episodes watched is either equal to the average_number_of_episodes
        ++present_number_of_episodes;                          //or is multiple of the number and thus a week has passed
        ++number_of_weeks;
    }


}

void watching_the_anime()
{
    while (episodes_watched <= present_number_of_episodes && number_of_episodes_left > 0)
    {
        ++episodes_watched;
        --number_of_episodes_left;
        new_episode_added();
        time_to_catchup = number_of_weeks;

    }
}