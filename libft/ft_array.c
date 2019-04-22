#include "libft.h"

void	new_array(size_t amount)
{
	t_array	*res;

	res = malloc(sizeof(t_array));
	res->arr = malloc(sizeof(amount));
	res->len = 0;
	res->max = amount;
}

void	*push_array(void *dst ,void *elem)
{
	t_array	*cast;
	t_array	*tmp;

	cast = (t_array*)dst;
	if (cast->len >= cast->max)
	{
		cast->max *= 2;
		tmp = malloc(cast->max * sizeof(void*));
		memcpy(tmp, cast->arr, sizeof(void*) * cast->len);
		free(cast->arr);
		cast->arr = (void**)tmp;
	}
	return ((cast->arr[cast->len++] = elem));
}