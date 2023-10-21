#include "shell.h"

/**
 * find_exe - searches for an executable in the PATH
 * @cmd: name of executable
 *
 * Return: On success, returns pathname of executable,
 * otherwise NULL.
*/
char *find_exe(char *cmd)
{
	char *dir, *temp, *pathname;
	DIR *dir_stream;
	struct dirent *entry;
	char *path = _strdup(get_env("PATH"));

	dir = strtok(path, ":");
	/*open and read directory*/
	while (dir)
	{
		dir_stream = opendir(dir);
		while ((entry = readdir(dir_stream)) != NULL)
		{
			if (_strcmp(entry->d_name, cmd) == 0)
			{
				temp  = _strcat(dir, "/");
				pathname = _strcat(temp, cmd);
				free(temp);
				free(path);
				closedir(dir_stream);
				return (pathname);
			}
		}
		closedir(dir_stream);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
