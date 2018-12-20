#include <iostream>
using namespace std;


void init_game(int *);
int prompt_for_load(int *);
int load_game(int count);
void delete_file_contents(void);
int check_for_save(void);
void print_game_state(string[]);
void print_opening_info(void);
void print_opening_saved_info(void);
int check_move(char * move);
void get_move(char * move);
int wall_checker_up(void);
int wall_checker_down(void);
int wall_checker_left(void);
int wall_checker_right(void);
int tree_checker_up(void);
int tree_checker_down(void);
int tree_checker_left(void);
int tree_checker_right(void);
int rock_checker_up(void);
int rock_checker_down(void);
int rock_checker_left(void);
int rock_checker_right(void);
int wall_checker(char move);
int tree_checker(char move);
int rock_checker(char move);
void handle_ammo(char * move);
void handle_food(char * move);
void handle_gun(char * move);
void handle_B_box(char * move);
void handle_E_box(char * move);
void handle_corpse(char * move);
void handle_sign(char * move);
void handle_note(char * move);
void handle_dresser(char * move);
void handle_snake_health(void);
void handle_snake(char * move);
void handle_L_door(char * move);
void handle_key(char * move);
void handle_heli(char * move);
void handle_dot(char * move);
int handle_nearby_shop(char * move);
int handle_nearby_GHHouse(char * move);
int handle_nearby_SEForest(char * move);
int handle_nearby_helipad(char * move);
int handle_nearby_EWoods(char * move);
int handle_nearby_Filmore(char * move);
int handle_nearby_WWoods(char * move);
int handle_nearby_Reptile(char * move);
int handle_in_shop(char * move);
int handle_in_GHHouse(char * move);
int handle_in_SEForest(char * move);
int handle_in_helipad(char * move);
int handle_in_EWoods(char * move);
int handle_in_Filmore(char * move);
int handle_in_WWoods(char * move);
int handle_in_Reptile(char * move);
int handle_in_small_building(char * move);
void update_after_up(char prev);
void update_after_down(char prev);
void update_after_left(char prev);
void update_after_right(char prev);
int save_game(int count);
void perform_move(char * move);





