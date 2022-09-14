/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:03:02 by anfreire          #+#    #+#             */
/*   Updated: 2022/09/14 23:24:07 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

// Libraries in the header below
#include "./libft/libft.h"

// struct dos builtins

typedef	struct s_built
{
	int		args;
	int		b_counter;
	int		builtin_n;
	char	**builtins;			// uma lista com o nome de todos os builtins
	char	***builtin;
}				t_built;

// struct de redirecoes
typedef struct s_redir
{
	int		input_n;
	int		output_n;
	int		append_n;
	int		heredoc_n;
	int		input_c;
	int		output_c;
	int		append_c;
	int		heredoc_c;
	char 	*redir_lib;
	char 	**heredoc;
	char 	**append;
	char 	**output;
	char	**input;
}				t_redir;

// struct dos comandos
typedef struct	s_cmd
{
	int		c_counter;
	char	**cmd;
	char	***cmdx;
	int		cmd_nbr;
	char	*infile;
	char	*outfile;
}				t_cmd;

// struct dos ids

typedef struct	s_ids
{
	int		*inp_list;
	int		*outp_list;
	int 	*appnd_list;
	int 	*hered_list;
	int		in_fd;	//associar o fd se infile. se nao = 0 (para ser o STDIN)
	int		out_fd; //associar o fd se outfile. se nao = 1 (para ser o STDIN)
	int		**pfd;		//fd dos pipes, em forma de double array, [index][0 ou 1]
	pid_t	id;
}				t_ids;

// struct das paths

typedef	struct s_paths
{
	char	*test_cmd;
	char	*p_str; 	// e onde fica a string inical depois do PATH:
	char	**spaths;	// temporario
	char	**paths;	// paths ja com a barra '/'
	char	**path_cmd; // se encontrar um ficheiro executavel assume path/cmd
	
}				t_paths;

// BIG MOMA

typedef struct	s_data
{
	char	**par_line;
	char	*line;
	char	**envp;
	t_ids	ids;
	t_cmd	cmd;
	t_paths	paths;
	t_redir	redir;
	t_built	built;
}				t_data;

//UTILS
// utils
int		len_str(char *str);

// new split
int		count_rows(char *s, char c);
char	**spliting(char *s, char c);
int		find_c(char *s, char c, int index);
int		find_len(char *s, char c, int index);
char	*substring(char *s, int start, int len);

//PARSING
//allocation of needed information
void	alloc_cmds(t_data *data);
void	alloc_redirections(t_data *data);
void	parse_alloc(t_data *data);

//line handling and utils
char	*get_line(t_data *data);
void	count_line(t_data *data);
void	create_lists(t_data *data);
void	joining(t_data *data, char *str, int i_p);

//parsing detectors
int		full_detector(t_data *data, char *str);
int		redir_detector(t_data *data, char *str);
int		builtin_detector(t_data *data, char *str);
int		cmd_detector(t_data *data, char *str);


//ENVIRONMENT
//parsing the env and extracting the paths
void	get_envp(t_data *data, char **envp);
void	get_paths(t_data *data);

//environment utils
char	*add_str(char *str);
char	*add_estr(t_data *data , int index);
int		equal(t_data *data, char *string, int index);

//PATH HANDLING
int		how_many_paths(char const *s, char c);
int		compare(const char *s1, const char *s2);
int		p_size(t_data *data, char *str, int i_p);
int		path_size(t_data *data, int index, int i_p);
void	path_join(t_data *data, int index, int i_p);

//COMMANDS
//parsing and testing if its executable
void	parse_cmd(t_data *data, int index);
int		acessing_cmd(t_data *data, int index);

//running commands
void	pipes(t_data *data);
void	run_processes(t_data *data, int index);
void	run_one_cmd(t_data *data, int in_fd, int out_fd);
void	run_father(t_data *data, int index);

// cmds - utils
void	count_cmds(t_data *data);

//BUILTINS
// parsing builtins
void	get_str(t_data *data, char *str, int index);
void    builting(t_data *data, int i, int index);
void	built_builting(t_data *data, int i, int index);
void    parse_builtin(t_data *data, int i, int index);

//env, export and unset builtins
void	env(t_data *data);
void	unset(t_data *data, char *str);
void	export(t_data *data, int index);
void	export_env(t_data *data);
void	export_var(t_data *data, char *str);
void    exec_builtin(t_data *data, int  i);

//utils
int		find_in_list(int *smal, int i);
int		get_next(t_data *data, int *smal);
int		env_var_detector(t_data *data, char *str);
char	*selection(t_data *data, int j);

// REDIRECTIONS
// parsing redirections
void	parse_redirec (t_data *data, int i);
void	extract_input(t_data *data, int i, int index, int flag);
void	extract_output(t_data *data, int i, int index, int flag);

//running the redirections
void	exec_redirect(t_data *data);
void	redirect(t_data *data);
//SIGNALS
void    sig_handler(int signum);
void	sig_ignore(int	signum);
void	exit_shell_sig(int sig);
void	exit_shell(t_data *data);

//MAIN
void	brain(t_data *data);
void	braining_cmds(t_data *data);
int		count_cmds_left(t_data *data, int i);

//FREES
void	free_cmds(t_data *data);
void	free_builtins(t_data *data);
void	free_line_info(t_data *data);
#endif