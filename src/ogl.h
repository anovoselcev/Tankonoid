#ifndef _LAB_OGL_H
#define _LAB_OGL_H
#include "common.h"
#include "texture.h"

struct rect
{
float x,y,z,t0,s0,t1,s1,dx,dy,dz,r,g,b;
};
typedef struct rect rect_t;
//////////////////////////
struct shell
{
	rect_t draw;
	int vis;
	int tex;
	float tr_x,tr_y,tr_z,alfa,vect;
	int f_wall,f_shell,f_resp,f_exp;
	float time_sps,time_rts;
};
typedef struct shell shell_t;

struct tank
{
rect_t draw;
int vis,resp,hp,kd,f_flash;
int tex;
float time_sp,time_rt;
float tr_x,tr_y,tr_z;
};
typedef struct tank tank_t;
	
struct button
{
rect_t draw;
int focus;
int tex;
};
typedef struct button button_t;

struct number
{
rect_t draw;
int tex;
};
typedef struct number number_t;

struct baf
{
rect_t draw;
float tr_x,tr_y,tr_z;
int tex,f_vis,f_aktiv;
float time_x,time_old;
};
typedef struct baf baf_t;

struct debaf
{
rect_t draw;
float tr_x,tr_y,tr_z;
int tex,f_vis;
};
typedef struct debaf debaf_t;

struct exp
{
rect_t draw;
float tr_x,tr_y,tr_z;
int tex,f_vis,f_exp;
float time_x,time_old;
};
typedef struct exp exp_t;

struct sound
{
HSAMPLE sam;
HCHANNEL ch;
int f_sound;
};
typedef struct sound sound_t;




int draw_animation();
int draw_resp();
int enemy_shell_resp();
int tank();
int	draw_shell();
int shell_resp();
int exp_draw();
int init_exp();
int baf_init();
int init_debaf();
int toplivo_time();
int hast_time();
int double_score_time();
int sound_init();
int baf_animation();

void ogl_reshape(GLFWwindow *w, int width, int height);
void ogl_init(int width, int height);
void ogl_draw(void);
void glew_init(void);
int load_textures();


#endif
