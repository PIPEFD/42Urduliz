#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

typedef pthread_mutex_t     t_mtx;
typedef enum e_time_format  t_time_format;
typedef enum e_action       t_action;
typedef struct s_table      t_table;
typedef struct s_fork       t_fork;
typedef struct s_philo      t_philo;

enum e_time_format
{
    MILISECONDS,
    MICROSECONDS
};

enum e_action
{
    DEAD,
    EATING,
    SLEEPING,
    THINKING,
    TAKING_A_FIRST_FORK,
    TAKING_A_SECOND_FORK
};

struct  s_fork
{
    unsigned id;
    t_mtx   fork_mtx;
};

struct  s_philo
{
    unsigned    id;
    long        meal_counter;
    long        last_meal_time;
    bool        is_full;
    t_fork      *first_fork;
    t_fork      *second_fork;
    pthread_t   thread_id;
    t_mtx       philo_mtx;
    t_table     *table;
};

struct s_table
{
    long    n_philos;
    long    time_die;
    long    time_eat;
    long    time_sleep;
    long    n_time_eat;
    long    n_philos_running;
    bool    all_philos_running;
    long    start_time;
    bool    start_sim;
    bool    end_sim;
    t_philo *philos;
    t_fork  *forks;
    pthread_t   supervisor;
    t_mtx   table_mtx;
    t_mtx   write_mtx;
    t_mtx   control_mtx;
};

// Valid arguments

int     args_parsing(t_table *table, char **argv);

// Data initialization 
int     data_init(t_table *table);


// Error and help

void    help(char *error);

// Verification functions

bool    is_space(char c);
bool    is_sign(char c);

// Simulation functions
int     start_simulation(t_table *table);
bool	is_simulation_finish(t_table *table);
void    simulation_fair(t_philo *philo);


// Time functions
long    get_time(t_time_format time_format);
void    usleep_mod(long wait_time, t_table *table);

// Control functions
bool    get_bool(t_mtx *mtx, bool *value);
long    get_long(t_mtx *mtx, long *value);
void    set_bool(t_mtx *mtx, bool *var, bool value);
void    set_long(t_mtx *mtx, long *var, long value);

// Print functions
void    print_action(t_action action, t_table *table, t_philo philo);

// void	print_info(t_table table);

// Control of threads
void	wait_all_threads(t_table *table);
void	safe_exit(t_table *table);


// Control of actions

void    eating(t_philo *philo);
void    thinking(t_philo *philo);
bool    is_dead(t_philo *philo);


// Control of Philosophs
// bool	all_philos_running(t_mtx *mtx, t_table *table);
// void	increment_n_philos(t_table *table);


//PROOFS

bool	all_philos_running(t_mtx *mutex, long *threads,
		long philo_nbr);

// void increment_n_philos(t_mtx *mtx, long *n_philos_running);
#endif 