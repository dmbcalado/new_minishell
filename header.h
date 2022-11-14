/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:03:02 by anfreire          #+#    #+#             */
/*   Updated: 2022/11/14 17:33:06 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

// Libraries in the header below

# include "libft/libft.h"
# include "./gnl/get_next_line.h"

// struct dos builtins

typedef struct s_built
{
	int		args;
	int		b_counter;
	int		builtin_n;
	char	**builtins;
	char	***builtin;
}				t_built;

// struct de redirecoes

typedef struct s_redir
{
	int		r_counter;
	int		input_n;
	int		output_n;
	int		append_n;
	int		heredoc_n;
	int		input_c;
	int		output_c;
	int		append_c;
	int		father_flag;
	char	*hdoc_key;
	char	*redir_lib;
	char	**output;
	char	**input;
}				t_redir;

// struct dos comandos

typedef struct s_cmd
{
	int		c_counter;
	char	**cmd;
	char	***cmdx;
	int		cmd_nbr;
	char	*infile;
	char	*outfile;
}				t_cmd;

// struct dos ids

typedef struct s_ids
{
	int		*inp_list;
	int		*outp_list;
	int		*appnd_list;
	int		*hered_list;
	int		in_fd;
	int		out_fd;
	int		**pfd;
	pid_t	*id;
}				t_ids;

// struct das paths

typedef struct s_paths
{
	char	*test_cmd;
	char	*p_str;
	char	**spaths;
	char	**paths;
	char	**path_cmd;
}				t_paths;

// struct para uso de builtins do Andre
typedef struct s_andre
{
	int		args;
	int		flag;
	int		exit;
	char	**c_dbl_ptr;
	char	*c_ptr;
}				t_andre;

// BIG MOMA

typedef struct s_data
{
	char	**par_line;
	char	*line;
	char	**envp;
	t_ids	ids;
	t_cmd	cmd;
	t_paths	paths;
	t_redir	redir;
	t_built	built;
	t_andre	andre;
}				t_data;

void	starting(t_data *data, char *envp[]);

//UTILS
// utils
int		len_str(char *str);
char	*str_cpy(char *dest, char *str);

// new split
int		count_rows(char *s, char c);
char	**spliting(char *s, char c);
int		find_c(char *s, char c, int index);
int		find_len(char *s, char c, int index);
char	*substring(char *s, int start, int len);

//PARSING
//allocation of needed information
void	alloc_cmds(t_data *data);
void	parse_alloc(t_data *data);

//line handling and utils
void	get_line(t_data *data);
void	count_line(t_data *data);
void	create_lists(t_data *data);
void	joining(t_data *data, char *str, int i_p);

//parsing detectors
int		full_detector(t_data *data, char *str);
int		redir_detector(t_data *data, char *str);
int		builtin_detector(t_data *data, char *str);
int		cmd_detector(t_data *data, char *str);

//parssing line
void	trim_spaces(char *str);
int		is_str_in_quotes(char *str, char c);
char	*is_string_expandable(char *str, t_data *data);
char	*realloc_string(char *ptr, char *str, int flag);
char	**realloc_list(char **ptr, int len);
char	**build_list(int len, char **ptr, char *str, t_data *data);
char	**parse_line(t_data *data);

//ENVIRONMENT
//parsing the env and extracting the paths
void	get_envp(t_data *data, char **envp);
void	get_paths(t_data *data);

//environment utils
char	*add_str(char *str);
char	*add_estr(t_data *data, int index);
int		equal(t_data *data, char *string, int index);

//PATH HANDLING
int		how_many_paths(char const *s, char c);
int		compare(const char *s1, const char *s2);
int		p_size(t_data *data, char *str, int i_p);
int		path_size(t_data *data, int index, int i_p);
void	path_join(t_data *data, int index, int i_p);

//COMMANDS
//parsing and testing if its executable
void	parse_cmds(t_data *data);
void	parse_cmd(t_data *data, int index);
int		acessing_cmd(t_data *data, int index);

//running commands
void	run_processes(t_data *data, int index);
void	run_command(t_data *data, int index, int cmd_i);
void	run_father(t_data *data, int index);
void	run_one_father(t_data *data);
void	run_child(t_data *data, int index);

// cmds - utils
void	count_cmds(t_data *data);

//BUILTINS
// parsing builtins
void	get_str(t_data *data, char *str, int index);
void	builting(t_data *data, int i, int index);
void	built_builting(t_data *data, int i, int index);
void	parse_builtin(t_data *data, int i, int index);

//env, export and unset builtins
void	env(t_data *data);
void	unset(t_data *data, char *str);
void	export(t_data *data, int index);
void	export_env(t_data *data);
void	export_var(t_data *data, char *str);
void	exec_builtin(t_data *data, int index, int i);
void	execve_builtin(t_data *data, int index, int jndex);

//cd, echo, and pwd, minishell and exit builtins
void	b_echo(t_data *data);
void	echo_with_n_flag(t_data *data);
void	b_pwd(void);
void	b_cd(t_data *data);
void	run_minishell(t_data *data, int index);
void	exit_minishell(t_data *data);

//utils
int		is_dot_cmd(char *str);
int		find_in_list(int *smal, int i);
int		get_next(t_data *data, int *smal);
int		env_var_detector(t_data *data, char *str);
char	*selection(t_data *data, int j);

// |-|-|-|-|     REDIRECTIONS     |-|-|-|-|
// parsing redirections

void	reset_counters(t_data *data);
void	alloc_redirections(t_data *data);
void	parse_redirec(t_data *data, int i);

//pipes
void	pipes(t_data *data);
void	piping(t_data *data, int index, int fn);
void	redirecting_input(t_data *data, int index);
void	redirecting_output(t_data *data, int index);
void	piping_first(t_data *data, int index);
void	piping_last(t_data *data, int index);
int		walk_till_pipe(t_data *data, int i);



// input and output
int		find_i_for_infile(t_data *data, int index);
int		find_i_for_outfile(t_data *data, int index);
void	extract_input(t_data *data, int index, int i);
void	extract_output(t_data *data, int index, int i);
int		bridge_infiles(t_data *data, int index, int last);
int		bridge_outfiles(t_data *data, int index, int last);

// heredoc
void	heredoc(t_data *data, int index);
void	extract_hdockey(t_data *data, int i);
int		compare_key(t_data *data, char *buffer, int len);

//running the redirections
int		redirect(t_data *data);
int		exec_in_redirect(t_data *data, int index, int save);
int		exec_out_redirect(t_data *data, int index, int save);


//SIGNALS
void	sig_handler(int signum);
void	sig_ignore(int signum);
void	exit_shell_sig(int sig);
void	exit_shell(t_data *data);

//MAIN
void	brain(t_data *data);
int		count_cmds_left(t_data *data, int i);

//FREES
void	close_files(t_data *data);
void	free_cmds(t_data *data);
void	free_builtins(t_data *data);
void	free_line_info(t_data *data);
#endif