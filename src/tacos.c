#include <stdlib.h>
#include <stdio.h>
#include "llist.h"
#include "tacos.h"
#include "window.h"
#include "game.h"

tacos_t *tacos_create(void)
{
	tacos_t *result;

	result = malloc(sizeof(*result));
	if (!result)
		return (NULL);
	result->window = window_create();
	result->sprites = ll_new();
	result->clock = sfClock_create();
	if (!result->clock || !result->sprites || !result->window) {
		tacos_destroy(result);
		return (NULL);
	}
	return (result);
}

void tacos_run(tacos_t *game)
{
	printf("running tacos :D\n@%p\n", (void *)game);
	game_loop(game);
}

void tacos_destroy(tacos_t *game)
{
	ll_free(game->sprites);
	sfRenderWindow_destroy(game->window);
	sfClock_destroy(game->clock);
	free(game);
}
