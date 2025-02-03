FILES	=																	\
	builtins/cd builtins/echo builtins/env builtins/exit builtins/export	\
	builtins/pwd core/error/print_arg_error									\
	core/error/print_cmd_errno_error core/error/print_gen_error				\
	core/prompt/build_prompt_message core/signal/signal env/ft_env_varcmp	\
	env/ft_envp env/ft_envp_tab env/ft_getenv env/ft_setenv env/ft_unsetenv	\
	execution/executing execution/fd_helper execution/here_doc				\
	execution/pipes_helper execution/piping execution/piping_utils			\
	minishell parsing/parse_commands parsing/parsing_utils					\
	parsing/parsing_utils2 pathing/get_cmd pathing/is_valid_builtin			\
	utils/env_utils utils/expand_variables utils/ft_cmd_count				\
	utils/ft_free_split utils/ft_last_exit_code utils/ft_lstremove			\
	utils/ft_which utils/split_out_of_quotes utils/term_colors				\
