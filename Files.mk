FILES	=																	\
	builtins/cd builtins/echo builtins/env builtins/exit builtins/export	\
	builtins/pwd builtins/unset core/error/print_arg_error					\
	core/error/print_cmd_errno core/error/print_gen_error					\
	core/prompt/build_prompt_message core/signal/signal env/ft_env_varcmp	\
	env/ft_envp env/ft_envp_tab env/ft_getenv env/ft_setenv					\
	env/ft_to_env_format env/ft_unsetenv execution/executing				\
	execution/fd_helper execution/here_doc execution/pipes_helper			\
	execution/piping execution/piping_utils execution/setup_cmd_fds			\
	minishell parsing/commander/commander parsing/commander/expander		\
	parsing/commander/handle_quotes parsing/commander/parse_tokens			\
	parsing/commander/redirector parsing/tokenizer/error_handling			\
	parsing/tokenizer/token_specializer parsing/tokenizer/token_worder		\
	parsing/tokenizer/tokenizer pathing/get_cmd pathing/is_valid_builtin	\
	utils/cmd/ft_add_one_to_tab utils/cmd/ft_cmd_count						\
	utils/cmd/ft_free_cmd utils/cmd/ft_which utils/core/ft_last_exit_code	\
	utils/core/ft_token_from_list utils/core/term_colors					\
	utils/parsing/split_out_of_quotes utils/redir/ft_lastredir				\
	utils/redir/ft_redir_from_list											\
