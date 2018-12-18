//Will hold info about the counties and will point to city info
struct county {
   string name;
   string *city;
   int cities;
   int population;
   float avg_income;
   float avg_house;
};

//Will hold info about the states and will point to county info
struct state {
   string name;
   struct county *c;
   int counties;
   int population;
};

bool is_valid_arguments(char *[], int);
state * create_states(int);
void get_state_data(state *, int, ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state *, int);

int menu();
void op1(state *, int);
void op2(state *, int);
void op3(state *, int);
void op4(state *, int);
void op5(state *, int);
void op6(state *, int);
void op7(state *, int);
void op8(state *, int);
bool run_again();

