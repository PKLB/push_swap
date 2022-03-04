/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:31:38 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:16:21 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void		ft_putstr(char *str);
void		*ft_create_struct(int number);
size_t		ft_strlen(const char *c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *c);
long int	ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2, int n);
char		**ft_split(char const *s, char c);
int			ft_check_if_sorted(char **numbers, int args);
int			ft_check_size(char **numbers, int args);
int			ft_check_duplicates(char **numbers, int args);
int			ft_check_number(char **number, int args);
int			ft_check_number_arg(char **argv);
int			ft_checks(char **numbers, int args);
int			ft_checks_args(char **numbers, int args);

typedef struct list
{
	int				content;
	int				index;
	int				position;
	struct list		*next;
}list,	t_a;

t_a			*ft_create_list(void);
void		*ft_lstadd_back(int number, t_a *pile);
void		ft_lstadd_front(int number, t_a **first_pile);
int			ft_fill_list(int n, char **other_numbers, t_a **first_pile);
int			ft_fill_list_args(int n, char **other_numbers, t_a **pile);
void		*ft_remove_last(t_a *pile);
int			ft_remove_first(t_a **first_pile);
void		ft_print_list(t_a **first_pile, char *str);
int			ft_check_empty_list(t_a *pile);
void		ft_print_both_list(t_a **first_pile, t_a **first_pile_b);
int			ft_list_length(t_a *pile);
int			ft_end(t_a *pile);
int			ft_is_sorted(t_a *pile);

int			ft_push_b(t_a **first_pile_b, t_a **first_pile);
int			ft_push_a(t_a **first_pile_b, t_a **first_pile);
int			ft_swap_a(t_a **first_pile);
int			ft_swap_b(t_a **first_pile_b);
int			ft_swap_both(t_a **first_pile_b, t_a **first_pile);
int			ft_rotate_a(t_a **first_pile);
int			ft_rotate_b(t_a **first_pile_b);
int			ft_reverse_rotate_a(t_a **first_pile);
int			ft_reverse_rotate_b(t_a **first_pile);

void		free_main(t_a **s);
int			ft_sort_three(t_a **first_pile);
int			ft_get_top(t_a **first_pile_b, t_a **first_pile);
int			ft_get_bottom(t_a **pile_b, t_a **pile);
int			ft_get_index(t_a **first_pile);
int			ft_get_pos(t_a **first_pile);
int			ft_get_bottom_optimized(t_a **pile_b, t_a **pile);
int			ft_get_bottom_optimized_b(t_a **pile_b, t_a **pile);
int			ft_get_first(t_a **first_pile, int chunk, t_a *copy);
int			ft_get_second(int chunk, t_a *copy, int first);
int			ft_get_first_big(t_a **pile, int chunk, t_a *copy);
int			ft_small_loop(t_a **pile_b, t_a **pile, int middle);
int			ft_big_loop(t_a **pile_b, t_a **pile, int middle);
int			ft_chunk_mid(t_a **pile_b, t_a **pile, int chunk, int mid);
int			ft_chunk_big(t_a **pile_b, t_a **pile, int chunk, int mid);
int			ft_algo(int *first_sec, int mid, t_a **pile, t_a **pile_b);
int			ft_al_big(int *first_sec, int mid, t_a **pile, t_a **p_b);
int			ft_sort_more(t_a **first_pile, t_a **first_pile_b);
int			ft_sort_five(t_a **first_pile_b, t_a **first_pile);
int			ft_push_swap(int n, char **other_numbers);
int			ft_push_swap_other(char **argv, int n);
#endif
