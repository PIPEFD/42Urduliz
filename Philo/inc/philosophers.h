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

int     args_parsing(t_table *table, char **argv);
int     data_init(t_table *table);
void    help(char *error);
bool    is_space(char c);
bool    is_sign(char c);





#endif 