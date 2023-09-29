/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:29:58 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 04:58:12 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data *data;
	pthread_t *t;
	int philo_num;

	if (is_error(argc, argv) == true)
		return (0);
	philo_num = philo_ft_atoi(argv[1]);
	malloc_all(&data, &t, philo_num);
	get_set_all(data, argv);
	create_threads(data, t, philo_num);
	join_threads(t, philo_num);
	destory_mutexes(data, philo_num);
	free_all(data, t, philo_num);
	return (0);
}