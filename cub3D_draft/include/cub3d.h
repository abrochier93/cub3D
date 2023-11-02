/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:28:25 by abrochie          #+#    #+#             */
/*   Updated: 2023/11/02 18:00:58 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* *** CONSTANTS *** */
# define WIDTH 1920
# define HEIGHT 1080
# define X 0
# define Y 1

/* *** ERROR MESSAGES *** */
# define ERR_MALLOC "malloc : something went wrong."
# define ERR_ARG "You should enter only one argument."
# define ERR_WALLS "The map is not surrounded by wall"
# define ERR_MAP "The map is not valid"
# define ERR_BIG_MAP "The map is too big"
# define ERR_SMALL_MAP "The map is too small"
# define ERR_FILE_FOUND "File not found"
# define ERR_FILE_TYPE "Textures format or extension file is not valid"
# define ERR_FILE_OPEN "File cannot be open"
# define ERR_FILE_EMPTY "File is empty"
# define ERR_PLAYER "There is no player"
# define ERR_PLAYER_POSITION "Player position not found"
# define ERR_COLOR_FORMAT "The color must be RGB format"
# define ERR_RGB_NUMERIC "RGB color needs 3 positives numerical parameters"
# define ERR_FEW_CHAR	"Add character on the last line"

/* *** STRUCTURES *** */
typedef struct s_lines_list
{
	char				*line;
	struct s_lines_list	*next;
	struct s_lines_list	*prev;
	int					coord[4];
	int					place;

}						t_lines_list;

typedef struct s_map
{
	int					width;
	int					height;
	char				**map;
	char				**settings;
	t_lines_list		*lines_list;
	mlx_texture_t		*north;
	mlx_texture_t		*south;
	mlx_texture_t		*west;
	mlx_texture_t		*east;
	unsigned int		floor;
	unsigned int		ceiling;
	float				square_size;
	float				cell_size;
	int					settings_nbr;
}						t_map;

typedef struct s_cub
{
	mlx_t				*mlx;
	mlx_image_t			*win;
	t_map				*map;
	mlx_texture_t		*texture;
	float				way_wall;
	int					dest[2];
	float				coord[2];
	int					deltat;
	size_t				p_x;
	size_t				p_y;
	char				p_dir;
	float				player_angle;
	float				starting_a;
	float				ray_x;
	float				ray_y;
	float				ray_a;
	float				distance_x;
	float				distance_y;
	float				fov;
	mlx_image_t			*image;
	int					flag;
}						t_cub;

/* *** FUNCTIONS *** */

/*ERRORS*/
int						ft_msg_err_close(char *error, int *fd);
int						ft_msg_err(char *error);

/*FREEE*/
void					free_settings(char **settings);
void					free_game(t_cub *cub);
void					free_map_line(t_lines_list *lines_list);
void					free_map(char **map);

/*HOOK*/
void					hook_base(void *param);
void					hook_player(void *param);
void					hook_color(void *param);

/*INIT*/
t_cub					*init_cub(void);
void					init_game(t_cub *cub);
t_lines_list			*init_lines_list(void);
t_map					*init_map(void);

/*LIST*/
t_lines_list			*ft_last_lines_list(t_lines_list *lines_list);
void					ft_lines_list_add_back(t_lines_list **lines_list,
							char *line);
t_lines_list			*ft_lines_list_new(char *line);
char					**ft_list_to_array(t_cub *cub);

/*MOVES*/
void					adjust(t_cub *cub, float dx, float dy,
							unsigned char flag);
void					moves(t_cub *cub);
void					rotate(t_cub *cub);

/*PARSING*/
void					assign_path(t_map *map, char *line);
bool					manage_settings(t_map *map, char *line);
bool					map_correction(t_cub *cub);
bool					map_is_valid(t_cub *cub);
bool					parsing(t_cub *cub, char *file);
bool					store_map_infos(t_cub *cub, char *line);
bool					store_map(t_cub *cub, int fd);

/*FOV*/
void					render_fov(t_cub *cub);
bool					render_wall(t_cub *cub, float angle, int pos_x);
void					draw_wall(t_cub *cub, float wall[2], int pos_x,
							float angle);
bool					is_wall(t_cub *cub, float destx, float desty);
mlx_texture_t			*get_texture(t_cub *cub, float dest[2]);

/*COLOR*/
uint32_t				get_pixels(t_cub *cub, int j, float coef_y, int j_min);
unsigned int			get_rgba(int r, int g, int b, int a);
bool					load_color(unsigned int *c, char *line);
bool					manage_colors(t_map *map, int line);

/*UTILS*/
int						ft_file_access(char *file, char *ext);
char					*ft_char_correction(char *line);
float					ft_deg_to_rad(float a);
char					**ft_duplicate_map(char **map);
int						ft_arraylen(char **array);
int						ft_iswhitespace(int c);
char					*ft_strtrim(char const *s1, char const *set);
bool					floodfill(t_cub *cub, char **new_map, int i, int j);
char					*get_path(char *line_in, char *str);
bool					get_player_angle(t_cub *cub);
bool					get_player_pos(char **map, size_t *pos);
bool					is_empty_line(char *line);
bool					is_multiple_of(float pos, int x);
bool					is_id(char *line, char *str);
bool					is_playable(t_cub *cub);
int						is_type_line(char *line);
bool					is_elements_valid(t_cub *cub, char c);

#endif
