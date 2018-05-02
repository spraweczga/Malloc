/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:20:50 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/30 16:20:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include <stdlib.h>
#include <unistd.h>

# define TINY	128
# define SMALL	1024

# define IS_TINY(x)		x > 0 && x < TINY ? 1 : 0
# define IS_SMALL(x)	x => TINY && x < LARGE ? 1 : 0
# define IS_LARGE(x)	x => LARGE ? 1 : 0

# define BLACK	'b'
# define RED	'r'

#define GRANDPA		root->parent->parent
#define PARENT		root->parent
#define UNCLE_LEFT	GRANDPA->left
#define UNCLE_RIGHT	GRANDPA->right

extern t_tag	*g_tags_tree;

typedef struct	s_tag
{
	char			color;
	short			size;
	struct s_rbtree	*parent;
	struct s_rbtree	*left;
	struct s_rbtree	*right;
}				t_tag;


/*
** free.c
*/
void ft_free(void *ptr);

/*
** malloc.c
*/
void *ft_malloc(size_t size);
//void *ft_realloc(void *ptr, size_t size);

/*
** malloc_rbtags.c
*/
t_tag	*create_tag(t_tag *root, size_t size);
t_tag	*insert_tag(t_tag *root, size_t size);
void	valid_tree(t_tag *root);
void	insertion(t_tag *root, size_t size);

/*
 ** malloc_rotations.c
 */
void	rotate_left(t_rbtree *root, t_rbtree *root_parent);
void	rotate_right(t_rbtree *root, t_rbtree *root_parent);

#endif
