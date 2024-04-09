    // printf("\n\ntable->philos[i].id = %d\n", table->philos->id);
    // printf("table->philos[i].meal_counter = %ld\n", table->philos->meal_counter);
    // printf("table->philos[i].last_meal_time = %ld\n", table->philos->last_meal_time);
    // printf("table->philos[i].is_full = %d\n", table->philos->is_full);
    // printf("end_sim = %d\n", table->end_sim);
    // printf("all_philos_running = %d\n", table->all_philos_running);
    // printf("n_philos_running = %ld\n\n", table->n_philos_running);
    // int i = 0;
    // while (i  < 4)
    // {    
    // i++;
    // }





        // printf("Valor retornado por pthread_join: %d\n", result);
        // printf("\n\ntable->philos[i].id = %d\n", table->philos->id);
        // printf("table->philos[i].meal_counter = %ld\n", table->philos->meal_counter);
        // printf("table->philos[i].last_meal_time = %ld\n", table->philos->last_meal_time);
        // printf("table->philos[i].is_full = %d\n", table->philos->is_full);
        // printf("end_sim = %d\n", table->end_sim);
        // printf("all_philos_running = %d\n", table->all_philos_running);
        // printf("n_philos_running = %ld\n\n", table->n_philos_running);


// void	*monitor_dinner(void *data)
// {
// 	int			i;
// 	t_table		*table;

// 	table = (t_table *)data;
// 	while (!all_threads_running(&table->table_mutex,
// 			&table->threads_running_nbr, table->philo_nbr))
// 		;
// 	while (!simulation_finished(table))
// 	{	
// 		i = -1;
// 		while (++i < table->philo_nbr && !simulation_finished(table))
// 		{
// 			if (philo_died(table->philos + i))
// 			{
// 				set_bool(&table->table_mutex, &table->end_simulation, true);
// 				write_status(DIED, table->philos + i, DEBUG_MODE);
// 			}
// 		}
// 	}
// 	return (NULL);
// }


        //busy wait for signal to start simulation
        //   while (!philo->table->start_sim);
        //loop executing whill all philos are alive
        //   while (philo->table->all_philos_running)
        //   {
        //    pthread_mutex_lock(&philo->write_mtx) ;
        //         write(1,"full\n", 5);
        //     pthread_mutex_unlock(&philo->write_mtx) ;
            //   }