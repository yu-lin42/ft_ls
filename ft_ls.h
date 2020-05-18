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
	char			flag;
	char			*file_name;
	char			*dir_path;
	struct s_files	*next;
}					t_files;

t_files	*no_flags(char *path);
char	*get_flags(int ac, char **flags_or_files);
t_files	*get_files(int ac, char **flags_or_files);
t_files	*check_files(t_files *files);
void	ls_structure(char *flags);
void	list_them(t_files *list);
void	recursive(char *path, char *flags);
void	no_recursive(char *path, char *flags);
t_files	*dynamic_file(char *name, t_files *head);
t_files	*new_file(const char *name);
void	add_file(const char *name, t_files *files);
t_files		*direct_path(char *path, char *file_name);
void	get_all(char *path, char *flags, t_files *files, t_files *dir_path);
void	sort_sequence(t_files *files, char *flags);
void	sort_files(t_files *list);
void	sort_in_reverse_time(t_files *list);
void	sort_in_reverse(t_files *list);
void	sort_in_time(t_files *list);

void	show_modes(t_files *list);
void	show_stats(t_files *list);

int		check_flags(char flag);

void	print_list(t_files **stuff);
void	show_files(t_files *list);

void	multi(char *flags, t_files *files);
#endif