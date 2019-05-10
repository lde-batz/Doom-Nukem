/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:20:18 by hdussert          #+#    #+#             */
/*   Updated: 2019/05/08 02:24:27 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_screen(t_doom *doom)
{
	double	**z_buffer;

	doom->raycasting.x = -1;
	z_buffer = malloc(sizeof(double *));
	*z_buffer = malloc(sizeof(double) * WIN_W);
	while (++doom->raycasting.x < WIN_W)
		draw_wfc(doom, z_buffer);
	doom->lsprite.spritesorder = malloc(sizeof(int)
		* doom->lsprite.numbsprites);
	doom->lsprite.spritesdist = malloc(sizeof(double)
		* doom->lsprite.numbsprites);
	draw_sprites(doom, &doom->raycasting, &doom->you, z_buffer);
	free(*z_buffer);
	free(z_buffer);
	free(doom->lsprite.spritesorder);
	free(doom->lsprite.spritesdist);
}
