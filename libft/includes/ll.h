/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:45:25 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/05 20:46:06 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL_H
# define LL_H

typedef struct		s_node
{
	void			*data;
	struct s_node	*next;
}					t_node;

typedef struct		s_list
{
	t_node			*head;
	t_node			*tail;
	t_node			*cur;
}					t_list;

typedef int(*t_compare)(void*, void*);
typedef	void(*t_display)(void*);

/*
**	Initializes the list. The struct is created as such:
**	t_example example (notice it is not a pointer to struct)
*/

void				init_list(t_list *list);

/*
**	Adds a node to the head of the list
*/

void				unshift_node(t_list *list, void *data);

/*
**	Adds a node to the tail of the list
*/

void				append_node(t_list *list, void *data);

/*
**	GET_NODE USAGE
**	get_node requires a function returning an int passed via
**	the t_compare struct. If your function used ft_strcmp to compare names,
**	returning a 0 would indicate a match. A function call should look like this
**	where compare_names is the function of your choice returning an int.
**
**	t_node *node;
**	node = get_node(&list, (int (*)(void*, void*))compare_name, "a_string")
*/

void				*get_node(t_list *list, t_compare compare, void *data);

/*
**	DISPLAY_LIST USAGE
**	display_list is a function to display the linked list. You will need to pass
**	a custom function based on the data in your list. The only argument in
**	the callis the address of your list.
**	example: display_list(&list, (t_display)(print_list))
**	print_list is your custom function.
*/

void				display_list(t_list *list, t_display display);

/*
**	Deletes a node from the list. Use get_node first and then pass that
**	to this function.
*/

void				delete_node(t_list *list, t_node *node);

#endif
