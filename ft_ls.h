#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
//# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <time.h>
# include <dirent.h>
# define FLAGS "Ralrt"

typedef struct	s_helpers
{
        DIR				*mydir;
        struct dirent	*mydirent;
        char			*tmp;
        char			*buf;
        int				num;
}						t_helpers;

typedef struct	s_files
{
	// char			flag;
	char			*file_name;
	char			*dir_path;
	struct s_files	*next;
}					t_files;

t_files		*basic(char *path);
t_files		*hidden(char *path);

char		*get_flags(int ac, char **flags_or_files);
t_files		*get_files(int, char **flags_or_files);
void		just_files(t_files *list);
void		just_flags(char *flags);

t_files		*dynamic_file(char *path, char *name, t_files *head);
t_files		*new_file(const char *name, char *path);
void		add_file(const char *name, char *path, t_files *files);
void		add_dir_path(char *path, char *file_name, t_files *list);

int			check_flags(char flag);
t_files		*check_files(char *path, t_files *files);
int			is_dir(char *path);
void		print_n_free(t_files **list);
void		free_list(t_files *list);

void	recursive(char *flags, t_files *list);
void	non_recursive(char *flags, t_files *list);

void	sort_sequence(t_files *files, char *flags);
void		sort_files(t_files *list);
void	sort_in_reverse_time(t_files *list);
void	sort_in_reverse(t_files *list);
void	sort_in_time(t_files *list);

void	list_them(t_files *list);
void	total_blocks(t_files *list);
void	show_permissions(t_files *list);
void	show_stats(t_files *list);

void flags_n_files(char *flags, t_files *list);
#endif