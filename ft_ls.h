/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 21:01:40 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 15:52:41 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>

# define C_NONE		"\033[0m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_BROWN	"\033[33m"
# define C_BLUE		"\033[34m"
# define C_WHITE	"\033[37m"
# define C_CYAN		"\033[36m"
# define C_MAGENTA	"\033[35m"
# define XATTR_SIZE 10000

typedef struct		s_lst
{
	char			*name;
	char			*path;
	mode_t			st_mode;
	time_t			date;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	quad_t			st_blocks;
	off_t			st_size;
	char			*add;
	struct s_lst	*next;
}					t_file;

typedef struct		s_opt
{
	int				l;
	int				big_r;
	int				r;
	int				a;
	int				t;
	int				d;
	int				g;
	int				u;
	int				f;
	int				big_g;
	int				one;
}					t_opt;

typedef struct		s_elem
{
	char			*name;
	char			*path;
	mode_t			st_mode;
	time_t			date;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	quad_t			st_blocks;
	off_t			st_size;
	struct s_elem	*next;
}					t_elem;

void				ft_stack(int argc, char **argv, int flag, t_opt opt);
char				**ft_cur_dir(void);
int					ft_where(char **argv);
void				go_check(t_opt opt, char **str, int n);
t_opt				ft_check(char **str, t_opt opt, int argc);
t_opt				ft_check_opt(char **str, t_opt opt, int i, int j);
int					ft_file_or_dir(char *str, t_opt opt);
int					file_exist(char *filename);

t_elem				*ft_opt_t_elem(t_elem **headptr, t_opt opt);
void				swap_elem_elem(t_elem **a, t_elem **b);
void				ft_elem_cpy_elem(t_elem **dest, t_elem *source);
int					cpm_time_elem(t_elem *elem1, t_elem *elem2);
int					compare_names_elem(t_elem *a, t_elem *b);

void				ft_permission_denied(char *str);
void				ft_non_exist_file(char *str);
void				ft_illegal_err(char c);
int					ft_access(char *str);

t_elem				*ft_listadd(t_elem **elem, char *str,
					char *path, t_opt opt);
t_elem				*ft_listnew(char *name, char *the_way, t_opt opt);
t_file				*ft_list_add(t_file **elem, char *str,
					char *path, char *add);
t_file				*ft_list_new(char *the_way, char *name, char *add);

void				ft_long_file(t_elem *file, t_opt opt);
void				ft_long(t_file *file, t_opt opt);
void				print_acl(char *path);
void				print_last_mod(time_t date);

char				**ft_time_sort(char **str, t_opt opt);
char				**ft_reborn(t_elem **file, char **str);
int					ft_len_struct(t_elem **file);
t_elem				*ft_opt_f_elem(t_elem *begin, char *path, t_opt opt);
t_elem				*ft_opt_r_elem(t_elem **begin, t_opt opt);

t_file				*ft_opt_r_dir(t_file **begin, t_opt opt);
t_file				*ft_opt_a(t_file *begin, t_opt opt, char *path);
t_file				*ft_opt_t_dir(t_file **headptr);
void				swap_elem_dir(t_file **a, t_file **b);

void				print_from_last_list(t_file *n);
void				print_name_file(t_elem *tmp, t_opt opt);
void				ft_c_file(t_elem *tmp);
void				ft_notc_file(t_elem *tmp);
void				print_name_list(t_file *tmp, t_opt opt);

char				**ft_sort(char **str, int n);
char				**ft_reverse(char **str, int n);
t_file				*insert_sorted(t_file *headptr, char *name, char *argv);
int					compare_names(t_file *a, t_file *b);
t_file				*sort_list(t_file *dir, t_file *elem);

void				ft_creation_file(char **str, t_opt opt, int n);
t_file				*ft_file_manipulate(t_file *begin, char **str,
					int i, t_opt opt);
char				*ft_path(char **str, int i);
int					ft_count_j(char *str);
t_elem				*ft_creation_elem(char **str, int i,
					t_elem *elem, t_opt opt);

t_elem				*ft_new_el(t_elem *new, char *str, char *path, t_opt opt);
t_file				*ft_new_new(t_file *new, char *str, char *path, char *add);
void				ft_color(mode_t st_mode);
char				**ft_sort_str(char **str, int n, t_opt opt);
void				ft_notc_list(t_file *tmp);

void				ft_print_link(char *path);
char				*ft_join_f(char *s1, char *s2);
void				print_total(t_file *file);
void				print_permissions(mode_t st_mode);
void				print_what_is_it(mode_t st_mode);

void				print_bytes(off_t st_size);
void				print_links(nlink_t st_nlink);
void				print_grp_name(gid_t st_gid);
void				print_name(uid_t st_uid);
void				ft_c_list(t_file *tmp);

void				ft_elem_cpy_dir(t_file **dest, t_file *source);
int					cpm_time_dir(t_file *elem1, t_file *elem2);
t_file				*ft_opt_f(t_file *begin, char *path);
t_file				*ft_opt_f_with_d(t_file *begin, char *path, char *str);
t_file				*ft_opt_d(t_file *begin, char *path, char *str, t_opt opt);

void				do_recurse(char *str, char *name, t_opt opt);
void				ft_recursion(t_file **begin, t_opt opt);
void				fuck_off(char *str, char *name);
t_file				*surprise_mthf(t_file *all, t_file *directory,
					char *path, t_opt opt);

void				ft_none(t_file *all, t_file **tmp, t_file **file,
					t_file **directory);
void				ft_f(t_file *all, t_file **directory,
					t_file **new, char *path);
void				ft_none_f(t_file *all, t_file **tmp,
					t_file **directory, t_file **file);
void				ft_f_a(t_file *all, t_file **directory,
					t_file **new, char *path);

void				print_n(char *name);
t_file				*ft_create_f(DIR *dir, t_file *all, char *path);
t_file				*ft_screw_it(t_opt opt, t_file **directory);
void				ft_meow(t_opt opt, t_file **new,
					t_file **file, t_file **tmp);
void				lst_file_del(t_file **alst, void (*del)
					(char *c1, char *c2, char *c3));
void				free_elem(char *c1, char *c2, char *c3);
void				free_elem_el(char *c1, char *c2);
void				lst_file_del_el(t_elem **alst);

void				lst_el_del(t_elem **alst, void (*del)(char *c1, char *c2));
void				free_str_arr(char ***str);
void				ft_min(t_opt opt, char **str, int n);
void				ft_go(t_file *file, t_opt opt);
void				ft_null(t_file **tmp, t_file **new, t_file **file);
void				ft_base(char *name, t_file **tmp,
					t_file **directory, t_file **all);
void				ft_recurse_f(t_file **tmp, t_file *directory, t_opt opt);

void				ft_permission_denied_once(char *str);
char				*ft_path_el(char *path, char *str);
char				*ft_path_path(char *path, char *str);
void				ft_n_more(char **str);
void				ft_one_only(char *str);
void				ft_file_perm(char *str);

#endif
