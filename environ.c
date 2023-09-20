#include "shell.h"

/**
 * _myenv - it prints the current environment
 * @info: the Structure containing potential arguments. Used to maintain
 *          the constant function prototype.
 * Return: 0, Always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - it gets the value of an environ variable
 * @name: env var name
 * @info: the Structure containing potential arguments. Used to maintain
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - It initializes a new environment variable,
 *             or modify an existing one
 * @info: the Structure containing potential arguments. Used to maintain
 *        the constant function prototype.
 *  Return: 0, Always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - It removes an environment variable
 * @info: the Structure containing potential arguments. Used to maintain
 *        the constant function prototype.
 * Return: 0, Always
 */
int _myunsetenv(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}

/**
 * populate_env_list - it populates env linked list
 * @info: the Structure containing potential arguments. Used to maintain
 *          the constant function prototype.
 * Return: 0, Always
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}

