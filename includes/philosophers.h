/*
** philosophers.h for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Fri Mar 17 11:17:11 2017 Lucas Debouté
** Last update Sun Mar 19 23:34:32 2017 Lucas Debouté
*/

#ifndef PHILOSOPHERS_H_
# define PHILOSOPHERS_H_

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include "extern.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_RESET "\x1b[0m"

/*
** STRUCT
*/

typedef enum		t_action
  {
    EAT,
    THINK,
    REST,
    NOTHING
  }			e_action;

typedef struct		s_philo
{
  int			id;
  int			bowl;
  int			has_resting;
  pthread_mutex_t	chopsticks;
  int			can_eat;
  struct s_philo	*neighbor;
  struct s_table	*table;
  e_action		action;
}			t_philo;

typedef struct		s_table
{
  t_philo		*philos;
  int			philosophers;
  int			occurences;
  bool			running;
  pthread_t		*threads;
}			t_table;

/*
** FUNCTIONS
** DECLARATIONS
*/

int	check_arguments(int argc, char **argv);
int	check_all_parameters(char **argv);
int	display_error(char *error);
int	get_values(char **argv, t_table *table);
int	get_philosophers(char **argv);
int	get_occurences(char **argv);

int	init_philosopher(t_table *table);
int	init_simulator(t_table *table);

void	display_status(t_table *table);
void	display_help();

void	*philosophers(void *data);
void	action_eat(t_philo *philo);
void	action_think(t_philo *philo);
void	action_rest(t_philo *philo);

int	check_bowl_empty(t_table *table);
void	empty_bowls(t_table *table);

#endif /* !PHILOSOPHERS_H */
