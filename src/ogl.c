#include "ogl.h"
#include<math.h>

int w=1024,h=768,f_scena=0,f_anim=0,a=7,f_speed=0,f_wall=0,gr,f_resp=0,i,p_bb=100,p_bp=20,p_of=10,dfo=5,score=0,p,p1,f_voulm=1,f_music=1; //размеры окна
float wf=1024.0,hf=768.0,left,right,u=1024.0,rad,deg,konv,alfa;//konv-konvertation
float dw=1024.0,dh=768.0,d;
int f_shell=0,j,mnoj,f_resp_shell=0,record_score,score_number,baf_int;
extern int t,kx,s_1,s_2,s_3,how_shell_bb,deltax,exp_s,f_exp,f_last_scena,f_type_shell;
extern float x,y;

// pvm - проекционно-видовая матрица
// pvm - модельно-видовая матрица
rglMat4f_t pvm,mvm,t_mvm,s_mvm,e_mvm;

//char *Txf_logo="../../data/textures/logo.png";
char *Txf_fon_01="../../data/textures/fon_001.png";
char *Txf_fon_02="../../data/textures/gr91.png";
char *Txf_name_00="../../data/textures/name_00.png";
char *Txf_start_00="../../data/textures/start_00.png";
char *Txf_exit_00="../../data/textures/exit_00.png";
char *Txf_start_01="../../data/textures/start_01.png";
char *Txf_exit_01="../../data/textures/exit_01.png";
char *Txf_tank="../../data/textures/KV-2_tank_mid.png";
char *Txf_bash="../../data/textures/KV-2_bash_mid.png";
char *Txf_shell_bb="../../data/textures/strike_1_bb_mid.png";
char *Txf_shell_bp="../../data/textures/strike_1_bp_mid.png";
char *Txf_shell_of="../../data/textures/strike_1_of_mid.png";
char *Txf_jag1="../../data/textures/Pz.Kpfw.IV-G_mid.png";
char *Txf_jag2="../../data/textures/Pz.Kpfw.IV-G_mid.png";
char *Txf_hp_line="../../data/textures/hp_line.png";
char *Txf_def_obj="../../data/textures/barricade.png";
char *Txf_enemy_shell="../../data/textures/enemy_shell.png";
char *Txf_zag_game_left="../../data/textures/zagr_game_left.png";
char *Txf_zag_game_right="../../data/textures/zagr_game_right.png";
char *Txf_sov_fon="../../data/textures/sov_fon.png";
char *Txf_exp_ap="../../data/textures/flashes.png";
char *Txf_num="../../data/textures/num_2.png";
char *Txf_heal="../../data/textures/heal.png";
char *Txf_rem="../../data/textures/rem.png";
char *Txf_gran="../../data/textures/gran.png";
char *Txf_sov="../../data/textures/double_score.png";
char *Txf_hast="../../data/textures/hast.png";
char *Txf_toplivo="../../data/textures/toplivo.png";
char *Txf_exp_enemy="../../data/textures/exp_enemy.png";
char *Txf_win="../../data/textures/WIN.png";
char *Txf_lose="../../data/textures/LOSE.png";
char *Txf_fon_win="../../data/textures/fon_win.png";
char *Txf_fon_lose="../../data/textures/fon_lose.png";
char *Txf_boom="../../data/textures/boom.png";
char *Txf_lvl_fon="../../data/textures/lvl_fon.png";
char *Txf_lvl_nm="../../data/textures/lvl_nm.png";
char *Txf_lvl_one_01="../../data/textures/lvl_one_01.png";
char *Txf_lvl_one_02="../../data/textures/lvl_one_02.png";
char *Txf_zagr_game="../../data/textures/zagr_game.png";
char *Txf_help="../../data/textures/help.png";
char *Txf_help_1="../../data/textures/help_1.png";
char *Txf_help_fon="../../data/textures/help_fon.png";
char *Txf_help_nm="../../data/textures/help_nm.png";
char *Txf_info="../../data/textures/info.png";
char *sndrs="../../data/sound/shot_my_1.wav";
char *sndfon="../../data/sound/fon_music.mp3";
char *sndrse="../../data/sound/shot_011.wav";
char *sndrm="../../data/sound/move_1.wav";
char *sndrem="../../data/sound/exp_me_1.wav";
char *sndree="../../data/sound/exp_enem_3.wav";
char *sndrbf="../../data/sound/baf_1.wav";
char *sndrpr="../../data/sound/press.wav";
char *Txf_voulm="../../data/textures/voulm.png";
char *Txf_voulm_1="../../data/textures/voulm_1.png";
char *Txf_voulm_off="../../data/textures/voulm_off.png";
char *Txf_voulm_off_1="../../data/textures/voulm_off_1.png";
char *Txf_music="../../data/textures/music.png";
char *Txf_music_1="../../data/textures/music_1.png";
char *Txf_music_off="../../data/textures/music_off.png";
char *Txf_music_off_1="../../data/textures/music_off_1.png";
char *Txf_lvl_two_01="../../data/textures/lvl_two_01.png";
char *Txf_lvl_three_01="../../data/textures/lvl_three_01.png";
char *Txf_lvl_two_02="../../data/textures/lvl_two_02.png";
char *Txf_zagr_gem="../../data/textures/zagr_gem.png";
char *Txf_fon_7="../../data/textures/fon_7.png";
char *Txf_crom="../../data/textures/crom.png";
char *Txf_tank_2="../../data/textures/tank_2.png";
char *Txf_kr="../../data/textures/kr.png";
char *Txf_fon_win_2="../../data/textures/win_2.png";
char *Txf_fon_lose_2="../../data/textures/fon_lose_2.png";
char *Txf_ram="../../data/textures/ram.png";


GLuint tex_fon_01,tex_name_00,tex_start_00,tex_exit_00,tex_start_01,tex_exit_01,tex_start=0,tex_exit=0,tex_tank,tex_shell_bb,tex_jag1,tex_fon,tex_fon_02,tex_jag2,tex_bash,tex_hp_line,tex_def_obj,tex_enemy_shell,tex_zag_game_left,tex_zag_game_right,tex_sov_fon,tex_num,tex_exp_ap,tex_heal,tex_rem,tex_gran,tex_sov,tex_hast,tex_toplivo,tex_exp_enemy,tex_boom,tex_win,tex_lose,tex_fon_win,tex_fon_lose,tex_lvl_fon,tex_lvl_nm,tex_lvl_one_01,tex_lvl_one_02,tex_zagr_game,tex_help,tex_help_1,tex_help_fon,tex_help_nm,tex_info,tex_voulm,tex_voulm_1,tex_voulm_off,tex_voulm_off_1,tex_music,tex_music_1,tex_music_off,tex_music_off_1,tex_lvl_two_01,tex_lvl_three_01,tex_logo,tex_lvl_two_02,tex_zagr_gem,tex_fon_7,tex_crom,tex_tank_2,tex_kr,tex_fon_win_2,tex_fon_lose_2,tex_shell_bp,tex_shell_of,tex_ram;

//rgl_Image_t logo;
//logo.width=330;logo.height=400;logo.


tank_t jag[7];
sound_t sd_exp_enemy[7];
shell_t shell_bb[100];
shell_t shell_bp[20];
shell_t shell_of[10];
shell_t enemy_shell[7];
tank_t def_obj[5];
exp_t exp_enemy[7];
double time, old_time;
double tx_old_time=0.0,tx_time=0.0;

sound_t sd_fon,sd_exp_ap,sd_exp_en,sd_boom,sd_move,sd_exp_me,sd_baf,sd_press;

int sound_init(){

	sd_exp_ap.sam=BASS_SampleLoad(FALSE, sndrs,0,0,2 , 0);sd_exp_ap.ch=BASS_SampleGetChannel(sd_exp_ap.sam, FALSE );sd_exp_ap.f_sound=0;

	sd_fon.sam=BASS_SampleLoad(FALSE, sndfon,0,0,2 ,BASS_SAMPLE_LOOP);sd_fon.ch=BASS_SampleGetChannel(sd_fon.sam, FALSE );sd_fon.f_sound=1;
	
	for(i=0;i<a;i++){
		
		sd_exp_enemy[i].sam=BASS_SampleLoad(FALSE, sndrse,0,0,2 , 0);sd_exp_enemy[i].ch=BASS_SampleGetChannel(sd_exp_enemy[i].sam, FALSE );sd_exp_enemy[i].f_sound=1;

	}
	
	sd_move.sam=BASS_SampleLoad(FALSE, sndrm,0,0,2 , 0);sd_move.ch=BASS_SampleGetChannel(sd_move.sam, FALSE );sd_move.f_sound=0;

	sd_exp_me.sam=BASS_SampleLoad(FALSE, sndrem,0,0,2 , 0);sd_exp_me.ch=BASS_SampleGetChannel(sd_exp_me.sam, FALSE );sd_exp_me.f_sound=0;

	sd_exp_en.sam=BASS_SampleLoad(FALSE, sndree,0,0,2 , 0);sd_exp_en.ch=BASS_SampleGetChannel(sd_exp_en.sam, FALSE );sd_exp_en.f_sound=0;

	sd_baf.sam=BASS_SampleLoad(FALSE, sndrbf,0,0,2 , 0);sd_baf.ch=BASS_SampleGetChannel(sd_baf.sam, FALSE );sd_baf.f_sound=0;

	sd_press.sam=BASS_SampleLoad(FALSE, sndrpr,0,0,2 , 0);sd_press.ch=BASS_SampleGetChannel(sd_press.sam, FALSE );sd_press.f_sound=0;

	
	return 0;
}


rect_t fn_d,nm_d,zag_game_left,zag_game_right,zagr_game,info;

int init_draw_object()
{
	fn_d.x=0;fn_d.y=0;fn_d.z=-4;fn_d.t0=0.0;fn_d.t1=1.0;fn_d.s0=0.0;fn_d.s1=1.0;fn_d.dx=dw/2;fn_d.dy=dh/2;fn_d.dz=0.0;fn_d.r=0;fn_d.g=0;fn_d.b=0;

	nm_d.x=0;nm_d.y=300;nm_d.z=1;nm_d.t0=0.0;nm_d.t1=1.0;nm_d.s0=0.0;nm_d.s1=1.0;nm_d.dx=384;nm_d.dy=64;nm_d.dz=0.0;nm_d.r=0;nm_d.g=0;nm_d.b=0;
	
	zag_game_left.x=-450;zag_game_left.y=-310;zag_game_left.z=10;zag_game_left.t0=0.0;zag_game_left.t1=1.0;zag_game_left.s0=0.0;zag_game_left.s1=1.0;zag_game_left.dx=64;zag_game_left.dy=96;zag_game_left.dz=0.0;zag_game_left.r=0;zag_game_left.g=0;zag_game_left.b=0;
	
	zag_game_right.x=450;zag_game_right.y=-310;zag_game_right.z=10;zag_game_right.t0=0.0;zag_game_right.t1=1.0;zag_game_right.s0=0.0;zag_game_right.s1=1.0;zag_game_right.dx=64;zag_game_right.dy=96;zag_game_right.dz=0.0;zag_game_right.r=0;zag_game_right.g=0;zag_game_right.b=0;

	zagr_game.x=0;zagr_game.y=356;zagr_game.z=10;zagr_game.t0=0.0;zagr_game.t1=1.0;zagr_game.s0=0.0;zagr_game.s1=1.0;zagr_game.dx=512;zagr_game.dy=32;zagr_game.dz=0.0;zagr_game.r=0;zagr_game.g=0;zagr_game.b=0;
	
	info.x=0;info.y=-50;info.z=4;info.t0=0.0;info.t1=1.0;info.s0=0.0;info.s1=1.0;info.dx=366;info.dy=280;info.dz=0.0;info.r=0;info.g=0;info.b=0;

	
	return 0;
}



tank_t ap,bh,hp_ap;

int tank()
{
	ap.draw.x=0;ap.draw.y=0;ap.draw.z=3;ap.draw.t0=0.0;ap.draw.t1=1.0;ap.draw.s0=0.0;ap.draw.s1=1.0;ap.draw.dx=32;ap.draw.dy=64;ap.draw.dz=0.0;ap.vis=1;ap.resp=0;ap.hp=3;ap.kd=0;ap.tex=0;ap.draw.r=0;ap.draw.g=0;ap.draw.b=0;ap.time_sp=1000;ap.time_rt=0;ap.tr_x=0;ap.tr_y=-250;ap.tr_z=0;
	hp_ap.draw.x=0;hp_ap.draw.y=0;hp_ap.draw.z=9;hp_ap.draw.t0=0.0;hp_ap.draw.t1=1.0;hp_ap.draw.s0=0.0;hp_ap.draw.s1=1.0;hp_ap.draw.dx=32;hp_ap.draw.dy=8;hp_ap.draw.dz=0.0;hp_ap.draw.r=0;hp_ap.draw.g=1;hp_ap.draw.b=0;hp_ap.vis=1;hp_ap.resp=0;hp_ap.hp=0;hp_ap.kd=0;hp_ap.tex=0;hp_ap.time_sp=0;hp_ap.time_rt=0;hp_ap.tr_x=0;hp_ap.tr_y=-320;hp_ap.tr_z=0;
	bh.draw.x=0;bh.draw.y=0;bh.draw.z=8;bh.draw.t0=0.0;bh.draw.t1=1.0;bh.draw.s0=0.0;bh.draw.s1=1.0;bh.draw.dx=64;bh.draw.dy=64;bh.draw.dz=0.0;bh.vis=1;bh.resp=0;bh.hp=0;bh.kd=0;bh.tex=0;bh.draw.r=0;bh.draw.g=0;bh.draw.b=0;bh.time_sp=4000;bh.time_rt=0;bh.tr_x=0;bh.tr_y=-250;bh.tr_z=0;
	u=wf/(2*4);
	left=-wf/2+u;
	right=wf/2-u;
	for(i=0;i<a;i++){
		if(i%2==0){
			jag[i].tr_x=left;
			left+=u;
		}
		if(i%2==1){
			jag[i].tr_x=right;
			right-=u;
		}

//printf(" %f %f ",left,right);

	jag[i].draw.x=0;jag[i].draw.y=0;jag[i].draw.z=8.0;jag[i].draw.t0=0.0;jag[i].draw.t1=1.0;jag[i].draw.s0=0.0;jag[i].draw.s1=1.0;jag[i].draw.dx=32;jag[i].draw.dy=64;jag[i].draw.dz=0.0;jag[i].vis=1;jag[i].resp=0;jag[i].hp=2;jag[i].kd=0;jag[i].tex=0;jag[i].draw.r=0;jag[i].draw.g=0;jag[i].draw.b=0;jag[i].time_sp=(i+1)*2000;jag[i].time_rt=0;jag[i].tr_y=160;jag[i].tr_z=0;jag[i].f_flash=0;

	}
	u=wf/(2*3);
		left=-wf/2+u;
		right=wf/2-u;
	for(i=0;i<dfo;i++){
		if(i%2==0){
			def_obj[i].tr_x=left;
			left+=u+10;
		}
		if(i%2==1){
			def_obj[i].tr_x=right;
			right-=u+10;
		}
		mnoj=pow(-1,i);
		def_obj[i].draw.x=0;def_obj[i].draw.y=rand()%20*dfo;def_obj[i].draw.z=1+mnoj*rand()%1;def_obj[i].draw.t0=0.0;def_obj[i].draw.t1=1.0;def_obj[i].draw.s0=0.0;def_obj[i].draw.s1=1.0;def_obj[i].draw.dx=96;def_obj[i].draw.dy=24;def_obj[i].draw.dz=0.0;def_obj[i].vis=1;def_obj[i].resp=0;def_obj[i].hp=2;def_obj[i].kd=0;def_obj[i].tex=0;def_obj[i].draw.r=0;def_obj[i].draw.g=0;def_obj[i].draw.b=0;def_obj[i].time_sp=4000;def_obj[i].time_rt=0;def_obj[i].tr_y=-70;def_obj[i].tr_z=0;
	}
	return 0;
}

 
int draw_shell()
{
	for(i=0;i<p_bb;i++){
		shell_bb[i].draw.x=0;shell_bb[i].draw.y=0;shell_bb[i].draw.z=-2;shell_bb[i].draw.t0=0.0;shell_bb[i].draw.t1=1.0;shell_bb[i].draw.s0=0.0;shell_bb[i].draw.s1=1.0;shell_bb[i].draw.dx=4;shell_bb[i].draw.dy=16;shell_bb[i].draw.dz=0.0;shell_bb[i].vis=1;shell_bb[i].tex=0;shell_bb[i].draw.r=0;shell_bb[i].draw.g=0;shell_bb[i].draw.b=0;shell_bb[i].tr_x=0;shell_bb[i].tr_y=-250;shell_bb[i].tr_z=0,shell_bb[i].alfa=0;shell_bb[i].f_wall=0,shell_bb[i].f_shell=0;shell_bb[i].f_resp=0;shell_bb[i].time_sps=1500,shell_bb[i].time_rts=0;shell_bb[i].f_exp=1;
	}
	for(i=0;i<p_bp;i++){
		shell_bp[i].draw.x=0;shell_bp[i].draw.y=0;shell_bp[i].draw.z=-2;shell_bp[i].draw.t0=0.0;shell_bp[i].draw.t1=1.0;shell_bp[i].draw.s0=0.0;shell_bp[i].draw.s1=1.0;shell_bp[i].draw.dx=4;shell_bp[i].draw.dy=16;shell_bp[i].draw.dz=0.0;shell_bp[i].vis=1;shell_bp[i].tex=0;shell_bp[i].draw.r=0;shell_bp[i].draw.g=0;shell_bp[i].draw.b=0;shell_bp[i].tr_x=0;shell_bp[i].tr_y=-250;shell_bp[i].tr_z=0,shell_bp[i].alfa=0;shell_bp[i].f_wall=0,shell_bp[i].f_shell=0;shell_bp[i].f_resp=0;shell_bp[i].time_sps=1500,shell_bp[i].time_rts=0;shell_bp[i].f_exp=1;
	}
	for(i=0;i<p_of;i++){
		shell_of[i].draw.x=0;shell_of[i].draw.y=0;shell_of[i].draw.z=-2;shell_of[i].draw.t0=0.0;shell_of[i].draw.t1=1.0;shell_of[i].draw.s0=0.0;shell_of[i].draw.s1=1.0;shell_of[i].draw.dx=4;shell_of[i].draw.dy=16;shell_of[i].draw.dz=0.0;shell_of[i].vis=1;shell_of[i].tex=0;shell_of[i].draw.r=0;shell_of[i].draw.g=0;shell_of[i].draw.b=0;shell_of[i].tr_x=0;shell_of[i].tr_y=-250;shell_of[i].tr_z=0,shell_of[i].alfa=0;shell_of[i].f_wall=0,shell_of[i].f_shell=0;shell_of[i].f_resp=0;shell_of[i].time_sps=1500,shell_of[i].time_rts=0;shell_of[i].f_exp=1;
	}
	for(i=0;i<a;i++){
		mnoj=pow(-1,i);
		enemy_shell[i].draw.x=0;enemy_shell[i].draw.y=0;enemy_shell[i].draw.z=9;enemy_shell[i].draw.t0=0.0;enemy_shell[i].draw.t1=1.0;enemy_shell[i].draw.s0=0.0;enemy_shell[i].draw.s1=1.0;enemy_shell[i].draw.dx=4;enemy_shell[i].draw.dy=16;enemy_shell[i].draw.dz=0.0;enemy_shell[i].vis=0;enemy_shell[i].tex=0;enemy_shell[i].draw.r=0;enemy_shell[i].draw.g=0;enemy_shell[i].draw.b=0;enemy_shell[i].tr_x=jag[i].tr_x;enemy_shell[i].tr_y=jag[i].tr_y-65;enemy_shell[i].tr_z=0,enemy_shell[i].alfa=0;enemy_shell[i].f_wall=0,enemy_shell[i].f_shell=0;enemy_shell[i].f_resp=1;enemy_shell[i].time_sps=6000+mnoj*rand()%3000;enemy_shell[i].time_rts=0;
	}
	
	return 0;
}

button_t bt1,bt2,lvl_one,lvl_start,help,voulm,music,lvl_two,lvl_three;

int init_button()
{
	bt1.draw.x=0;bt1.draw.y=-100;bt1.draw.z=2;bt1.draw.t0=0.0;bt1.draw.t1=1.0;bt1.draw.s0=0.0;bt1.draw.s1=1.0;bt1.draw.dx=128;bt1.draw.dy=64;bt1.draw.dz=0.0;bt1.focus=0;bt1.tex=tex_start;bt1.draw.r=0;bt1.draw.g=0;bt1.draw.b=0;
	bt2.draw.x=0;bt2.draw.y=-250;bt2.draw.z=3;bt2.draw.t0=0.0;bt2.draw.t1=1.0;bt2.draw.s0=0.0;bt2.draw.s1=1.0;bt2.draw.dx=128;bt2.draw.dy=64;bt2.draw.dz=0.0;bt2.focus=0;bt2.tex=tex_exit;bt2.draw.r=0;bt2.draw.g=0;bt2.draw.b=0;
	
	lvl_one.draw.x=0;lvl_one.draw.y=150;lvl_one.draw.z=3;lvl_one.draw.t0=0.0;lvl_one.draw.t1=1.0;lvl_one.draw.s0=0.0;lvl_one.draw.s1=1.0;lvl_one.draw.dx=256;lvl_one.draw.dy=42;lvl_one.draw.dz=0.0;lvl_one.focus=0;lvl_one.tex=0;lvl_one.draw.r=0;lvl_one.draw.g=0;lvl_one.draw.b=0;

	lvl_two.draw.x=0;lvl_two.draw.y=50;lvl_two.draw.z=3;lvl_two.draw.t0=0.0;lvl_two.draw.t1=1.0;lvl_two.draw.s0=0.0;lvl_two.draw.s1=1.0;lvl_two.draw.dx=256;lvl_two.draw.dy=42;lvl_two.draw.dz=0.0;lvl_two.focus=0;lvl_two.tex=0;lvl_two.draw.r=0;lvl_two.draw.g=0;lvl_two.draw.b=0;

	lvl_three.draw.x=0;lvl_three.draw.y=-50;lvl_three.draw.z=3;lvl_three.draw.t0=0.0;lvl_three.draw.t1=1.0;lvl_three.draw.s0=0.0;lvl_three.draw.s1=1.0;lvl_three.draw.dx=256;lvl_three.draw.dy=42;lvl_three.draw.dz=0.0;lvl_three.focus=0;lvl_three.tex=0;lvl_three.draw.r=0;lvl_three.draw.g=0;lvl_three.draw.b=0;

	
	lvl_start.draw.x=300;lvl_start.draw.y=-210;lvl_start.draw.z=2;lvl_start.draw.t0=0.0;lvl_start.draw.t1=1.0;lvl_start.draw.s0=0.0;lvl_start.draw.s1=1.0;lvl_start.draw.dx=128;lvl_start.draw.dy=64;lvl_start.draw.dz=0.0;lvl_start.focus=0;lvl_start.tex=tex_start;lvl_start.draw.r=0;lvl_start.draw.g=0;lvl_start.draw.b=0;
	
	help.draw.x=370;help.draw.y=-330;help.draw.z=18;help.draw.t0=0.0;help.draw.t1=1.0;help.draw.s0=0.0;help.draw.s1=1.0;help.draw.dx=128;help.draw.dy=48;help.draw.dz=0.0;help.focus=0;help.tex=tex_start;help.draw.r=0;help.draw.g=0;help.draw.b=0;

	voulm.draw.x=-480;voulm.draw.y=-330;voulm.draw.z=18;voulm.draw.t0=0.0;voulm.draw.t1=1.0;voulm.draw.s0=0.0;voulm.draw.s1=1.0;voulm.draw.dx=32;voulm.draw.dy=32;voulm.draw.dz=0.0;voulm.focus=0;voulm.tex=tex_voulm;voulm.draw.r=0;voulm.draw.g=0;voulm.draw.b=0;

	music.draw.x=-400;music.draw.y=-330;music.draw.z=18;music.draw.t0=0.0;music.draw.t1=1.0;music.draw.s0=0.0;music.draw.s1=1.0;music.draw.dx=32;music.draw.dy=32;music.draw.dz=0.0;music.focus=0;music.tex=tex_voulm;music.draw.r=0;music.draw.g=0;music.draw.b=0;

	//bt1.draw.x=0;bt1.draw.y=-300;bt1.draw.z=2;bt1.draw.t0=0.0;bt1.draw.t1=1.0;bt1.draw.s0=0.0;bt1.draw.s1=1.0;bt1.draw.dx=128;bt1.draw.dy=64;bt1.draw.dz=0.0;bt1.focus=0;bt1.tex=tex_start;bt1.draw.r=0;bt1.draw.g=0;bt1.draw.b=0;
	return 0;
}

number_t num_score,num_shell_bb,num_shell_bp,num_shell_of,ram;

int init_number(){
	
	num_score.draw.x=-220;num_score.draw.y=356;num_score.draw.z=14;num_score.draw.t0=0.0;num_score.draw.t1=1.0;num_score.draw.s0=0.0;num_score.draw.s1=1.0;num_score.draw.dx=14;num_score.draw.dy=14;num_score.draw.dz=0.0;num_score.draw.r=0;num_score.draw.g=0;num_score.draw.b=0;num_score.tex=tex_num;
	
	num_shell_bb.draw.x=225;num_shell_bb.draw.y=356;num_shell_bb.draw.z=14;num_shell_bb.draw.t0=0.0;num_shell_bb.draw.t1=1.0;num_shell_bb.draw.s0=0.0;num_shell_bb.draw.s1=1.0;num_shell_bb.draw.dx=14;num_shell_bb.draw.dy=14;num_shell_bb.draw.dz=0.0;num_shell_bb.draw.r=0;num_shell_bb.draw.g=0;num_shell_bb.draw.b=0;num_shell_bb.tex=tex_num;
	
	num_shell_bp.draw.x=350;num_shell_bp.draw.y=356;num_shell_bp.draw.z=14;num_shell_bp.draw.t0=0.0;num_shell_bp.draw.t1=1.0;num_shell_bp.draw.s0=0.0;num_shell_bp.draw.s1=1.0;num_shell_bp.draw.dx=14;num_shell_bp.draw.dy=14;num_shell_bp.draw.dz=0.0;num_shell_bp.draw.r=0;num_shell_bp.draw.g=0;num_shell_bp.draw.b=0;num_shell_bp.tex=tex_num;

	num_shell_of.draw.x=475;num_shell_of.draw.y=356;num_shell_of.draw.z=14;num_shell_of.draw.t0=0.0;num_shell_of.draw.t1=1.0;num_shell_of.draw.s0=0.0;num_shell_of.draw.s1=1.0;num_shell_of.draw.dx=14;num_shell_of.draw.dy=14;num_shell_of.draw.dz=0.0;num_shell_of.draw.r=0;num_shell_of.draw.g=0;num_shell_of.draw.b=0;num_shell_of.tex=tex_num;
	
	ram.draw.x=210;ram.draw.y=354;ram.draw.z=15;ram.draw.t0=0.0;ram.draw.t1=1.0;ram.draw.s0=0.0;ram.draw.s1=1.0;ram.draw.dx=12;ram.draw.dy=30;ram.draw.dz=0.0;ram.draw.r=0;ram.draw.g=0;ram.draw.b=0;ram.tex=tex_num;
	
	
	return 0;
}

baf_t baf_1,heal,rem,double_score,hast,toplivo;

int baf_init(){
	
	baf_1.draw.x=0;baf_1.draw.y=0;baf_1.draw.z=2;baf_1.draw.t0=0.0;baf_1.draw.t1=1.0;baf_1.draw.s0=0.0;baf_1.draw.s1=1.0;baf_1.draw.dx=4;baf_1.draw.dy=16;baf_1.draw.dz=0.0;baf_1.draw.r=0;baf_1.draw.g=0;baf_1.draw.b=0;baf_1.tr_x=0;baf_1.tr_y=-250;baf_1.tr_z=0;baf_1.tex=0;baf_1.f_vis=0;

	heal.draw.x=0;heal.draw.y=0;heal.draw.z=2;heal.draw.t0=0.0;heal.draw.t1=1.0;heal.draw.s0=0.0;heal.draw.s1=1.0;heal.draw.dx=16;heal.draw.dy=16;heal.draw.dz=0.0;heal.draw.r=0;heal.draw.g=0;heal.draw.b=0;heal.tr_x=0;heal.tr_y=-250;heal.tr_z=0;heal.tex=tex_heal;heal.f_vis=0;

	rem.draw.x=0;rem.draw.y=0;rem.draw.z=2;rem.draw.t0=0.0;rem.draw.t1=1.0;rem.draw.s0=0.0;rem.draw.s1=1.0;rem.draw.dx=20;rem.draw.dy=16;rem.draw.dz=0.0;rem.draw.r=0;rem.draw.g=0;rem.draw.b=0;rem.tr_x=0;rem.tr_y=-250;rem.tr_z=0;rem.tex=tex_rem;rem.f_vis=0;
	
	double_score.draw.x=0;double_score.draw.y=0;double_score.draw.z=2;double_score.draw.t0=0.0;double_score.draw.t1=1.0;double_score.draw.s0=0.0;double_score.draw.s1=1.0;double_score.draw.dx=25;double_score.draw.dy=25;double_score.draw.dz=0.0;double_score.draw.r=0;double_score.draw.g=0;double_score.draw.b=0;double_score.tr_x=0;double_score.tr_y=-250;double_score.tr_z=0;double_score.tex=0;double_score.f_vis=0;double_score.f_aktiv=0;double_score.time_x=0;double_score.time_old=15000;
	
	hast.draw.x=0;hast.draw.y=0;hast.draw.z=2;hast.draw.t0=0.0;hast.draw.t1=1.0;hast.draw.s0=0.0;hast.draw.s1=1.0;hast.draw.dx=12;hast.draw.dy=32;hast.draw.dz=0.0;hast.draw.r=0;hast.draw.g=0;hast.draw.b=0;hast.tr_x=0;hast.tr_y=-250;hast.tr_z=0;hast.tex=tex_hast;hast.f_vis=0;hast.f_aktiv=0;hast.time_x=0;hast.time_old=10000;
	
	toplivo.draw.x=0;toplivo.draw.y=0;toplivo.draw.z=2;toplivo.draw.t0=0.0;toplivo.draw.t1=1.0;toplivo.draw.s0=0.0;toplivo.draw.s1=1.0;toplivo.draw.dx=16;toplivo.draw.dy=16;toplivo.draw.dz=0.0;toplivo.draw.r=0;toplivo.draw.g=0;toplivo.draw.b=0;toplivo.tr_x=0;toplivo.tr_y=-250;toplivo.tr_z=0;toplivo.tex=tex_toplivo;toplivo.f_vis=0;toplivo.f_aktiv=0;toplivo.time_x=0;toplivo.time_old=15000;

	
	return 0;
}


exp_t exp_ap,boom;

int init_exp(){
	
	exp_ap.draw.x=0;exp_ap.draw.y=0;exp_ap.draw.z=19;exp_ap.draw.t0=0.0;exp_ap.draw.t1=1.0;exp_ap.draw.s0=0.0;exp_ap.draw.s1=0.0;exp_ap.draw.dx=16;exp_ap.draw.dy=32;exp_ap.draw.dz=0.0;exp_ap.draw.r=0;exp_ap.draw.g=0;exp_ap.draw.b=0;exp_ap.tr_x=bh.tr_x-1;exp_ap.tr_y=bh.tr_y+90;exp_ap.tr_z=0;exp_ap.tex=tex_exp_ap;exp_ap.f_vis=0,exp_ap.f_exp=0;exp_ap.time_x=0;exp_ap.time_old=0;

	for(i=0;i<a;i++){
	exp_enemy[i].draw.x=0;exp_enemy[i].draw.y=0;exp_enemy[i].draw.z=12;exp_enemy[i].draw.t0=0.0;exp_enemy[i].draw.t1=1.0;exp_enemy[i].draw.s0=0.0;exp_enemy[i].draw.s1=0.0;exp_enemy[i].draw.dx=16;exp_enemy[i].draw.dy=32;exp_enemy[i].draw.dz=0.0;exp_enemy[i].draw.r=0;exp_enemy[i].draw.g=0;exp_enemy[i].draw.b=0;exp_enemy[i].tr_x=jag[i].tr_x-1;exp_enemy[i].tr_y=jag[i].tr_y-90;exp_enemy[i].tr_z=0;exp_enemy[i].tex=tex_exp_ap;exp_enemy[i].f_vis=0,exp_enemy[i].f_exp=0;exp_enemy[i].time_x=0;exp_enemy[i].time_old=0;
	}
	
	boom.draw.x=0;boom.draw.y=0;boom.draw.z=19;boom.draw.t0=0.0;boom.draw.t1=1.0;boom.draw.s0=0.0;boom.draw.s1=0.0;boom.draw.dx=32;boom.draw.dy=32;boom.draw.dz=0.0;boom.draw.r=0;boom.draw.g=0;boom.draw.b=0;boom.tr_x=0;boom.tr_y=0;boom.tr_z=0;boom.tex=tex_boom;boom.f_vis=0,boom.f_exp=0;boom.time_x=0;boom.time_old=0;

	return 0;
}

debaf_t gran;

int init_debaf(){
	
	gran.draw.x=0;gran.draw.y=0;gran.draw.z=11;gran.draw.t0=0.0;gran.draw.t1=1.0;gran.draw.s0=0.0;gran.draw.s1=1.0;gran.draw.dx=20;gran.draw.dy=16;gran.draw.dz=0.0;gran.draw.r=0;gran.draw.g=0;gran.draw.b=0;gran.tr_x=0;gran.tr_y=-250;gran.tr_z=0;gran.tex=tex_gran;gran.f_vis=0;
	
	return 0;
}

void rglGetError(void)
{
	GLuint error=glGetError();
	if (error== GL_NO_ERROR)
		printf("NO ERROR \n");
	if (error== GL_INVALID_ENUM)
		printf("ERROR GL_INVALID_ENUM \n");
	if (error== GL_INVALID_VALUE)
		printf("ERROR GL_INVALID_VALUE \n");
	if (error== GL_INVALID_OPERATION)
		printf("ERROR GL_INVALID_OPERATION \n");
	if (error== GL_INVALID_FRAMEBUFFER_OPERATION)
		printf("ERROR GL_INVALID_FRAMEBUFFER_OPERATION \n");
	if (error== GL_OUT_OF_MEMORY)
		printf("ERROR GL_OUT_OF_MEMORY \n");
}

//Функция инициализации библиотеки GLEW
void glew_init(void)
{
	int err = glewInit();
	if (GLEW_OK != err)	{ 
		printf("Error: %s\n", glewGetErrorString(err));	
		glfwTerminate(); exit( EXIT_FAILURE );
	}
	else {
		printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));		
	}	
	}

int set_ortographic(int w, int h)
{
	glMatrixMode(GL_PROJECTION);		
	rglMatrixIdentity4f(pvm);
	glLoadMatrixf(pvm);
	rglOrthof(pvm,-wf/2,wf/2,-hf/2,hf/2,-20.0f, 20.0f);	
	glLoadMatrixf(pvm);
	glMatrixMode(GL_MODELVIEW);
	rglMatrixIdentity4f(mvm);
	glLoadMatrixf(mvm);

return 0;
}

int set_perspectiv(int w, int h)
{
	glMatrixMode(GL_PROJECTION);		
	rglMatrixIdentity4f(pvm);
	glLoadMatrixf(pvm);
	float rat= (float) w /(float) h;	
	rglPerspectivef(pvm, 45.0f, rat, 0.1f, 1000.0f);
	glLoadMatrixf(pvm);
	glMatrixMode(GL_MODELVIEW);
	rglMatrixIdentity4f(mvm);
	glLoadMatrixf(mvm);

return 0;
}


// flag_pvm: 0 - ortographic 1 - perspectiv
int set_pvm(int flag_pvm)
{
	if (flag_pvm) 
		set_perspectiv(w,h);
	else
		set_ortographic(w,h);

return 0;
}


//Функция изменения размеров окна
void ogl_reshape(GLFWwindow *w, int width, int height)
{
	if (height == 0)
			height = 1;	
		glViewport(0, 0, width, height);	
		ogl_init(width, height);		
}

//Функция инициализации OpenGL
void ogl_init(int width, int height)

{
	//получение размеров окна для модуля ogl
	w=width;
	h=height;
	//perescop_dx=(float)w,perescop_dy=(float)h;
	//fon_dx=(float)w,fon_dy=(float)h;
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);	
	glEnable(GL_DEPTH_TEST);
	set_pvm(0);	
	//set_ortographic(w,  h);
	//load_textures();
	init_draw_object();
	init_button();
	tank();
	draw_shell();
	init_number();
	baf_init();
	init_exp();
	init_debaf();
	sound_init();
	BASS_ChannelPlay(sd_fon.ch, FALSE);
	
}


void draw_rect_p(float x, float y, float z,float s0,float s1,float t0,float t1, float dx, float dy, float dz)
{
		glBegin(GL_TRIANGLE_STRIP);	
		
			glColor3f(1.0,0.0,0.0);
			glTexCoord2f(s0,t0);		
			glVertex3f(x-dx, y-dy, z-dz);				

			glColor3f(0.0,0.0,1.0);
			glTexCoord2f(s0,t1);		
			glVertex3f(x-dx, y+dy, z+dz);
			
			glColor3f(0.0,1.0,0.0) ;
			glTexCoord2f(s1,t0);		
			glVertex3f(x+dx, y-dy, z-dz) ;
			
			
			glColor3f(0.0,1.0,1.0) ;
			glTexCoord2f(s1,t1);			
			glVertex3f(x+dx, y+dy, z+dz) ;
			
		 glEnd();
	
}


/*
void tor_draw(float x, float y, float z,float s0,float s1,float t0,float t1, float dx, float dy, float dz)
{
	//rglMatrixIdentity4f(t_mvm);	
	
	//rglRotatef( t_mvm, angle_tor,1, 1, 0);
	//rglTranslatef(t_mvm,0.0,0.0,dz);
	//glLoadMatrixf(t_mvm);
	
	draw_rect_p(x, y, z,s0,s1,t0,t1, dx, dy,  dz);
}
*/

void draw_rect(rect_t p)
{
		glBegin(GL_TRIANGLE_STRIP);	
		
			glColor3f(p.r,p.g,p.b);
			glTexCoord2f(p.s0,p.t0);		
			glVertex3f(p.x-p.dx, p.y-p.dy, p.z-p.dz);				

			glColor3f(p.r,p.g,p.b);
			glTexCoord2f(p.s0,p.t1);		
			glVertex3f(p.x-p.dx, p.y+p.dy, p.z+p.dz);
			
			glColor3f(p.r,p.g,p.b) ;
			glTexCoord2f(p.s1,p.t0);		
			glVertex3f(p.x+p.dx, p.y-p.dy, p.z-p.dz) ;
			
			
			glColor3f(p.r,p.g,p.b) ;
			glTexCoord2f(p.s1,p.t1);			
			glVertex3f(p.x+p.dx, p.y+p.dy, p.z+p.dz) ;
			
		 glEnd();
	//printf(" %f %f %f \n",r.x,r.y,r.z);
}
int load_textures()
{ /*
		tor_init();
		ship_init();
	for(i=0;i<=N;i++){
		
			rglLoadTextures(m_txf_ship[i],&mship[i].tex_ship);
	}
	*/
	//rglLoadTextures(Txf_logo,&tex_logo);
	rglLoadTextures(Txf_fon_01,&tex_fon_01);
	rglLoadTextures(Txf_fon_02,&tex_fon_02);
	rglLoadTextures(Txf_name_00,&tex_name_00);
	rglLoadTextures(Txf_start_00,&tex_start_00);
	rglLoadTextures(Txf_exit_00,&tex_exit_00);
	rglLoadTextures(Txf_start_01,&tex_start_01);
	rglLoadTextures(Txf_exit_01,&tex_exit_01);
	rglLoadTextures(Txf_tank,&tex_tank);
	rglLoadTextures(Txf_bash,&tex_bash);
	rglLoadTextures(Txf_shell_bb,&tex_shell_bb);
	rglLoadTextures(Txf_shell_bp,&tex_shell_bp);
	rglLoadTextures(Txf_shell_of,&tex_shell_of);
	rglLoadTextures(Txf_jag1,&tex_jag1);
	rglLoadTextures(Txf_jag2,&tex_jag2);
	rglLoadTextures(Txf_hp_line,&tex_hp_line);
	rglLoadTextures(Txf_def_obj,&tex_def_obj);
	rglLoadTextures(Txf_enemy_shell,&tex_enemy_shell);
	rglLoadTextures(Txf_zag_game_left,&tex_zag_game_left);
	rglLoadTextures(Txf_zag_game_right,&tex_zag_game_right);
	rglLoadTextures(Txf_num,&tex_num);
	rglLoadTextures(Txf_sov_fon,&tex_sov_fon);
	rglLoadTextures(Txf_exp_ap,&tex_exp_ap);
	rglLoadTextures(Txf_heal,&tex_heal);
	rglLoadTextures(Txf_rem,&tex_rem);
	rglLoadTextures(Txf_gran,&tex_gran);
	rglLoadTextures(Txf_sov,&tex_sov);
	rglLoadTextures(Txf_hast,&tex_hast);
	rglLoadTextures(Txf_toplivo,&tex_toplivo);
	rglLoadTextures(Txf_exp_enemy,&tex_exp_enemy);
	rglLoadTextures(Txf_boom,&tex_boom);
	rglLoadTextures(Txf_win,&tex_win);
	rglLoadTextures(Txf_lose,&tex_lose);
	rglLoadTextures(Txf_fon_win,&tex_fon_win);
	rglLoadTextures(Txf_fon_lose,&tex_fon_lose);
	rglLoadTextures(Txf_lvl_fon,&tex_lvl_fon);
	rglLoadTextures(Txf_lvl_nm,&tex_lvl_nm);
	rglLoadTextures(Txf_lvl_one_01,&tex_lvl_one_01);
	rglLoadTextures(Txf_lvl_one_02,&tex_lvl_one_02);
	rglLoadTextures(Txf_zagr_game,&tex_zagr_game);
	rglLoadTextures(Txf_help,&tex_help);
	rglLoadTextures(Txf_help_1,&tex_help_1);
	rglLoadTextures(Txf_help_fon,&tex_help_fon);
	rglLoadTextures(Txf_help_nm,&tex_help_nm);
	rglLoadTextures(Txf_info,&tex_info);
	rglLoadTextures(Txf_voulm,&tex_voulm);
	rglLoadTextures(Txf_voulm_1,&tex_voulm_1);
	rglLoadTextures(Txf_voulm_off,&tex_voulm_off);
	rglLoadTextures(Txf_voulm_off_1,&tex_voulm_off_1);
	rglLoadTextures(Txf_music,&tex_music);
	rglLoadTextures(Txf_music_1,&tex_music_1);
	rglLoadTextures(Txf_music_off,&tex_music_off);
	rglLoadTextures(Txf_music_off_1,&tex_music_off_1);
	rglLoadTextures(Txf_lvl_two_01,&tex_lvl_two_01);
	rglLoadTextures(Txf_lvl_two_02,&tex_lvl_two_02);
	rglLoadTextures(Txf_lvl_three_01,&tex_lvl_three_01);
	rglLoadTextures(Txf_zagr_gem,&tex_zagr_gem);
	rglLoadTextures(Txf_fon_7,&tex_fon_7);
	rglLoadTextures(Txf_crom,&tex_crom);
	rglLoadTextures(Txf_tank_2,&tex_tank_2);
	rglLoadTextures(Txf_kr,&tex_kr);
	rglLoadTextures(Txf_fon_win_2,&tex_fon_win_2);
	rglLoadTextures(Txf_fon_lose_2,&tex_fon_lose_2);
	rglLoadTextures(Txf_ram,&tex_ram);
	//printf_tor_init();
	//printf_ship_init();
	
	
return 0;
}

int boom_time(int t){
	if((boom.f_vis==1)&&((f_scena==3)||(f_scena==8))){
		boom.time_x=glfwGetTime();
		if((boom.time_x - boom.time_old)*1000>=t){
			boom.time_old=boom.time_x;
			boom.f_exp+=1;
	}}

	return 0;
}

int boom_draw(){
	if(boom.f_vis==1){
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_boom);
		glTranslatef(boom.tr_x,boom.tr_y,0);
		boom.draw.s0=boom.f_exp*0.0625;
		boom.draw.s1=boom.f_exp*0.0625+0.0625;
	//printf(" %.4f  %.4f %d ",exp_ap.draw.s0,exp_ap.draw.s1,exp_ap.f_exp);
		draw_rect(boom.draw);
		boom_time(20);
	}
	if(boom.f_exp==14){
		boom.f_exp=0;
		boom.f_vis=0;
		boom.draw.s0=0;
		boom.draw.s1=0;
	}
	return 0;
}




int exp_enemy_time(int t){
	for(i=0;i<a;i++){
		if(exp_enemy[i].f_vis==1){
			exp_enemy[i].time_x=glfwGetTime();
			if((exp_enemy[i].time_x - exp_enemy[i].time_old)*1000>=t){
				exp_enemy[i].time_old=exp_enemy[i].time_x;
				exp_enemy[i].draw.s0=exp_enemy[i].f_exp*0.33;
				exp_enemy[i].draw.s1=exp_enemy[i].f_exp*0.33+0.33;
				exp_enemy[i].f_exp+=1;	
	}}}
	return 0;
}

int exp_enemy_draw(){
	
	glBindTexture(GL_TEXTURE_2D, tex_exp_enemy);
	for(i=0;i<a;i++){
		if(exp_enemy[i].f_vis==1){
			glLoadIdentity();
			glTranslatef(exp_enemy[i].tr_x,exp_enemy[i].tr_y,0);
	//printf("%d %d \n",i, exp_enemy[i].f_exp);
			draw_rect(exp_enemy[i].draw);
		}
		if(exp_enemy[i].f_exp==3){
			exp_enemy[i].f_exp=0;
			exp_enemy[i].f_vis=0;
			exp_enemy[i].draw.s0=0;
			exp_enemy[i].draw.s1=0;
			exp_enemy[i].time_old=0;
			exp_enemy[i].time_x=0;
		}
	}
	return 0;
}


int exp_time(int t){
	if(exp_ap.f_vis==1){
		tx_time=glfwGetTime();
		if((tx_time - tx_old_time)*1000>=t){
			tx_old_time=tx_time;
			exp_ap.f_exp+=1;
			sd_exp_ap.f_sound=0;
	}}
	
		
	
	return 0;
}

int exp_draw(){
	if(exp_ap.f_vis==1){
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_exp_ap);
		glTranslatef(exp_ap.tr_x,exp_ap.tr_y,0);
		exp_ap.draw.s0=exp_ap.f_exp*0.33;
		exp_ap.draw.s1=exp_ap.f_exp*0.33+0.33;
		//printf(" %.4f  %.4f %d ",exp_ap.draw.s0,exp_ap.draw.s1,exp_ap.f_exp);
		draw_rect(exp_ap.draw);
		exp_time(80);
	}
	if(exp_ap.f_exp==3){
		exp_ap.f_exp=0;
		exp_ap.f_vis=0;
		exp_ap.draw.s0=0;
		exp_ap.draw.s1=0;
	}
	return 0;
}
int baf_animation(){
	if((f_scena==3)||(f_scena==8)){
		if(baf_1.f_vis==1){
			baf_1.tr_y-=1;
		
			}
		if((baf_1.tr_y<-hf/2)){
			baf_1.f_vis=0;
			baf_1.draw.y=0;
			baf_1.draw.x=0;
			baf_int=0;
		}
		if(heal.f_vis==1){
			heal.tr_y-=1;
		}
		if((heal.tr_y<-hf/2)){
			heal.f_vis=0;
			heal.draw.y=0;
			heal.draw.x=0;
			baf_int=0;
		}
		if(rem.f_vis==1){
				rem.tr_y-=1;
			}
		if((rem.tr_y<-hf/2)){
			rem.f_vis=0;
			rem.draw.y=0;
			rem.draw.x=0;
			baf_int=0;
			}
		if(gran.f_vis==1){
			gran.tr_y-=1;
			}
		if((gran.tr_y<-hf/2)){
			gran.f_vis=0;
			gran.draw.y=0;
			gran.draw.x=0;
			baf_int=0;	
		}
		if(double_score.f_vis==1){
				double_score.tr_y-=1;
			}
		if((double_score.tr_y<-hf/2)){
			double_score.draw.y=0;
			double_score.draw.x=0;
			baf_int=0;
			double_score.f_vis=0;
		
		}
		if(hast.f_vis==1){
				hast.tr_y-=1;
			}
		if((hast.tr_y<-hf/2)){
			hast.f_vis=0;
			hast.draw.y=0;
			hast.draw.x=0;
			baf_int=0;	
		}
		if(toplivo.f_vis==1){
				toplivo.tr_y-=1;
			}
		if((toplivo.tr_y<-hf/2)){
			toplivo.draw.y=0;
			toplivo.draw.x=0;
			toplivo.f_vis=0;
			baf_int=0;	
			
	}
			
			
	}
	return 0;
}

int baf_draw(){
	
	glLoadIdentity();
	if((f_scena==3)||(f_scena==8)){
		glLoadIdentity();
		if(baf_int==2){
			baf_1.f_vis=1;
			//printf("baf\n");
			glLoadIdentity();
			glBindTexture(GL_TEXTURE_2D, tex_shell_bb);
			glTranslatef(baf_1.tr_x,baf_1.tr_y,0);
			glRotatef(45,0.0,0.0,1.0);
			draw_rect(baf_1.draw);
			}
		if(baf_int==3){
			heal.f_vis=1;
			//printf("baf\n");
			glLoadIdentity();
			glBindTexture(GL_TEXTURE_2D, tex_heal);
			glTranslatef(heal.tr_x,heal.tr_y,0);
			//glRotatef(45,0.0,0.0,1.0);
			draw_rect(heal.draw);
	
			
	}
	if(baf_int==1){
		rem.f_vis=1;
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_rem);
		glTranslatef(rem.tr_x,rem.tr_y,0);
		draw_rect(rem.draw);
		
		
	}
	if(baf_int==4){
		gran.f_vis=1;
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_gran);
		glTranslatef(gran.tr_x,gran.tr_y,0);
		draw_rect(gran.draw);
		
	}
	if((baf_int==5)){
		double_score.f_vis=1;
		glLoadIdentity();
		if(f_scena==3)
		double_score.tex=tex_sov;
		if(f_scena==8)
		double_score.tex=tex_kr;
		glBindTexture(GL_TEXTURE_2D, double_score.tex);
		glTranslatef(double_score.tr_x,double_score.tr_y,0);
		draw_rect(double_score.draw);
		
		
	}
	if(baf_int==6){
		hast.f_vis=1;
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_hast);
		glTranslatef(hast.tr_x,hast.tr_y,0);
		draw_rect(hast.draw);
		}
	if(baf_int==7){
		toplivo.f_vis=1;
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_toplivo);
		glTranslatef(toplivo.tr_x,toplivo.tr_y,0);
		draw_rect(toplivo.draw);
		}
		}
	
		
	return 0;
}

int draw_ram(){
	if((f_scena==3)||(f_scena==8)){
	if(f_type_shell==1){
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_ram);
		ram.draw.x=138;ram.draw.y=354;
		draw_rect(ram.draw);
	}
	if(f_type_shell==2){
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_ram);
		ram.draw.x=265;ram.draw.y=354;
		draw_rect(ram.draw);
	}
	if(f_type_shell==3){
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex_ram);
		ram.draw.x=390;ram.draw.y=354;
		draw_rect(ram.draw);
	}
	}
	
	return 0;
}
int d1;

int draw_number_score(int d, rect_t r){
	
	//glBindTexture(GL_TEXTURE_2D, tx);
	if(d==0){
	r.s0=0;
	r.s1=0.1;
	draw_rect(r);
	}
	//printf("%d\n",d);
	while(d>0){
		d1=(d)%10;
		r.s0=d1/10.0;
		r.s1=r.s0+0.1;
		//glBindTexture(GL_TEXTURE_2D, tx);
		draw_rect(r);
		d=d/10;
		r.x-=27;
		//printf("%d\n",d);
	}
	r.x=-220;
	return 0;
}

int k1,m; 

int draw_number_shell_bb(int k, rect_t l ,int p){
	
	//glBindTexture(GL_TEXTURE_2D, tx);
	m=0;
	k=p-k;
	if(k==0){
	l.s0=0;
	l.s1=0.1;
	draw_rect(l);
	}
	while(k>0){
		k1=(k)%10;
		l.s0=k1/10.0;
		l.s1=l.s0+0.1;
		//glBindTexture(GL_TEXTURE_2D, tx);
		draw_rect(l);
		k=k/10;
		l.x-=27;
		m++;
		//printf("%d\n",d);
	}
	l.x=l.x+m*27;
	m=0;
	
	return 0;
}




int draw_button()
{
	if(f_scena==0){
		glBindTexture(GL_TEXTURE_2D, bt1.tex);
		draw_rect(bt1.draw);
		//bt1.draw.x+=0.5;
		if(bt1.focus==0)
			bt1.tex=tex_start_00;
		if(bt1.focus==1)
			bt1.tex=tex_start_01;
		glBindTexture(GL_TEXTURE_2D, bt2.tex);
		draw_rect(bt2.draw);
		if(bt2.focus==0)
			bt2.tex=tex_exit_00;
		if(bt2.focus==1)
			bt2.tex=tex_exit_01;
	}
	if(f_scena==1){
		glBindTexture(GL_TEXTURE_2D, lvl_one.tex);
		draw_rect(lvl_one.draw);
		if(lvl_one.focus==0)
				lvl_one.tex=tex_lvl_one_01;
			if(lvl_one.focus==1)
				lvl_one.tex=tex_lvl_one_02;	
		glBindTexture(GL_TEXTURE_2D, lvl_two.tex);
		draw_rect(lvl_two.draw);
			if(lvl_two.focus==0)
				lvl_two.tex=tex_lvl_two_01;
			if(lvl_two.focus==1)
				lvl_two.tex=tex_lvl_two_02;	
		glBindTexture(GL_TEXTURE_2D, lvl_three.tex);
		draw_rect(lvl_three.draw);
		if(lvl_three.focus==0)
				lvl_three.tex=tex_lvl_three_01;
		//if(lvl_three.focus==1)
				//lvl_three.tex=tex_lvl_three_02;	
			
	}
	if((f_scena==2)||(f_scena==7)){
		glBindTexture(GL_TEXTURE_2D, lvl_start.tex);
		draw_rect(lvl_start.draw);
		//bt1.draw.x+=0.5;
		if(lvl_start.focus==0)
			lvl_start.tex=tex_start_00;
		if(lvl_start.focus==1)
			lvl_start.tex=tex_start_01;
	}
	if((f_scena!=3)&&(f_scena!=6)){
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, help.tex);
		draw_rect(help.draw);
		if(help.focus==0)
			help.tex=tex_help;
		if(help.focus==1)
			help.tex=tex_help_1;
	}
	if(f_scena!=3){
		glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, voulm.tex);
	draw_rect(voulm.draw);
	if(f_voulm==1){
		if(voulm.focus==0)
			voulm.tex=tex_voulm;
		if(voulm.focus==1)
			voulm.tex=tex_voulm_1;
	}
	if(f_voulm==0){
		if(voulm.focus==0)
			voulm.tex=tex_voulm_off;
		if(voulm.focus==1)
			voulm.tex=tex_voulm_off_1;
	}
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, music.tex);
	draw_rect(music.draw);
	if(f_music==1){
		if(music.focus==0)
			music.tex=tex_music;
		if(music.focus==1)
			music.tex=tex_music_1;
	}
	if(f_music==0){
		if(music.focus==0)
			music.tex=tex_music_off;
		if(music.focus==1)
			music.tex=tex_music_off_1;
	}
	
	
		}
		
return 0;	
}

int povorot_bash()
{
	
	rad=atan(kx/bh.draw.dy);
	//printf(".%4f\n",rad);
	konv=180/3.1415926535897932384626433832795;
	deg=konv*rad;
	//printf(".%4f\n",deg);
	
	
	
	//printf(" %5.2f ",deg);
	//printf(" %5.2f ",konv);
	
	return 0;
}

int draw_tank()
{
	glLoadIdentity();
		for(i=0;i<p_bb;i++){
			glLoadIdentity();
			if(shell_bb[i].vis==1){
				shell_bb[i].tex=tex_shell_bb;
				glBindTexture(GL_TEXTURE_2D, shell_bb[i].tex);
				glTranslatef(shell_bb[i].tr_x,shell_bb[i].tr_y,0);
			if(shell_bb[i].f_shell==0)
				shell_bb[i].alfa=deg;
			//glRotatef(shell[i].alfa,0.0,0.0,1.0);
				draw_rect(shell_bb[i].draw);
	}}
	glLoadIdentity();
		for(i=0;i<p_bp;i++){
			glLoadIdentity();
			if(shell_bp[i].vis==1){
				shell_bp[i].tex=tex_shell_bp;
				glBindTexture(GL_TEXTURE_2D, shell_bp[i].tex);
				glTranslatef(shell_bp[i].tr_x,shell_bp[i].tr_y,0);
			if(shell_bp[i].f_shell==0)
				shell_bp[i].alfa=deg;
			//glRotatef(shell[i].alfa,0.0,0.0,1.0);
				draw_rect(shell_bp[i].draw);
	}}
	glLoadIdentity();
		for(i=0;i<p_of;i++){
			glLoadIdentity();
			if(shell_of[i].vis==1){
				shell_of[i].tex=tex_shell_of;
				glBindTexture(GL_TEXTURE_2D, shell_of[i].tex);
				glTranslatef(shell_of[i].tr_x,shell_of[i].tr_y,0);
			if(shell_of[i].f_shell==0)
				shell_of[i].alfa=deg;
			//glRotatef(shell[i].alfa,0.0,0.0,1.0);
				draw_rect(shell_of[i].draw);
	}}
	
		glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,hp_ap.tex);
	glTranslatef(hp_ap.tr_x,hp_ap.tr_y,0);
	draw_rect(hp_ap.draw);
	glLoadIdentity();
	if(f_scena==3)
	ap.tex=tex_tank;
	if(f_scena==8){
	ap.tex=tex_tank_2;
	ap.draw.dy=96;
	ap.draw.dx=36;
	bh.draw.z=-3;
	hp_ap.tr_y=ap.tr_y  - ap.draw.dy -10;
	}
	glBindTexture(GL_TEXTURE_2D, ap.tex);
	glTranslatef(ap.tr_x,ap.tr_y,0);
	draw_rect(ap.draw);
	
	
	//draw_rect(hp_ap.draw);

	povorot_bash();
	bh.tex=tex_bash;
	glBindTexture(GL_TEXTURE_2D, bh.tex);
	glLoadIdentity();
	glTranslatef(bh.tr_x,bh.tr_y,0);
	//glRotatef(deg,0.0,0.0,1.0);
	
	
	draw_rect(bh.draw);
	
	
	
return 0;	
}

int draw_tank_jag()
{
glLoadIdentity();
	for(i=0;i<a;i++){
		glLoadIdentity();
		if(jag[i].vis==1){
			if(f_scena==3)
			jag[i].tex=tex_jag1;
			if(f_scena==8){
			jag[i].tex=tex_crom;
			jag[i].draw.dx=40;
			jag[i].draw.dy=100;
			}
			glBindTexture(GL_TEXTURE_2D, jag[i].tex);
			glTranslatef(jag[i].tr_x,jag[i].tr_y,0);
			draw_rect(jag[i].draw);
	}}
	for(i=0;i<dfo;i++){
		glLoadIdentity();
		if(def_obj[i].vis==1){
			def_obj[i].tex=tex_def_obj;
			glBindTexture(GL_TEXTURE_2D, def_obj[i].tex);
			glTranslatef(def_obj[i].tr_x,def_obj[i].tr_y,0);
			draw_rect(def_obj[i].draw);
	}}
	for(i=0;i<a;i++){
		glLoadIdentity();
		if(enemy_shell[i].vis==1){
			enemy_shell[i].tex=tex_enemy_shell;
			glBindTexture(GL_TEXTURE_2D, enemy_shell[i].tex);
			glTranslatef(enemy_shell[i].tr_x,enemy_shell[i].tr_y,0);
		//if(enemy_shell[i].f_shell==0)
			//enemy_shell[i].alfa=deg;
		//glRotatef(enemy_shell[i].alfa,0.0,0.0,1.0);
		draw_rect(enemy_shell[i].draw);
	}}
return 0;
}




void  ogl_draw_scena_0(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*wf+=0.3;
	hf+=0.3;
	dw-=0.3;
	dh-=0.3;
	*/
	if(f_scena==0)
		tex_fon=tex_fon_01;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	glBindTexture(GL_TEXTURE_2D, tex_name_00);
	draw_rect(nm_d);
	
	
	draw_button();
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	
}

void  ogl_draw_scena_1(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_scena==1)
		tex_fon=tex_lvl_fon;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	glBindTexture(GL_TEXTURE_2D, tex_lvl_nm);
	draw_rect(nm_d);
	draw_button();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	
}

void  ogl_draw_scena_2(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_scena==2)
		tex_fon=tex_sov_fon;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	draw_button();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	

}



void  ogl_draw_scena_3(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_scena==3)
		tex_fon=tex_fon_02;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	
		//printf("%d\n",double_score.f_aktiv);
	draw_tank_jag();
	//draw_button();
	baf_draw();
	draw_tank();
	exp_draw();
	exp_enemy_draw();
	boom_draw();
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, tex_zagr_game);
	draw_rect(zagr_game);
	draw_ram();
	/*glBindTexture(GL_TEXTURE_2D, tex_zag_game_left);
	draw_rect(zag_game_left);
	glBindTexture(GL_TEXTURE_2D, tex_zag_game_right);
	draw_rect(zag_game_right);*/
	glBindTexture(GL_TEXTURE_2D, tex_num);
	//draw_rect(num_score.draw);
	draw_number_score(score, num_score.draw);
	glBindTexture(GL_TEXTURE_2D, tex_num);
	//draw_rect(num_score.draw);
	draw_number_shell_bb(s_1, num_shell_bb.draw, p_bb);
	draw_number_shell_bb(s_2, num_shell_bp.draw, p_bp);
	draw_number_shell_bb(s_3, num_shell_of.draw, p_of);
	
	//glLoadIdentity();
	
		
}

void  ogl_draw_scena_4(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_last_scena==3)
	tex_fon=tex_fon_lose;
	if(f_last_scena==8)
	tex_fon=tex_fon_lose_2;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	glBindTexture(GL_TEXTURE_2D, tex_lose);
	draw_rect(nm_d);
	draw_button();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}

void  ogl_draw_scena_5(void)
{
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if((f_scena==5)&&(ap.tex==tex_tank))
	tex_fon=tex_fon_win;
	if((f_scena==5)&&(ap.tex==tex_tank_2))
	tex_fon=tex_fon_win_2;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	glBindTexture(GL_TEXTURE_2D, tex_win);
	draw_rect(nm_d);
	draw_button();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}

void  ogl_draw_scena_6(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_scena==6)
	tex_fon=tex_help_fon;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	glBindTexture(GL_TEXTURE_2D, tex_help_nm);
	draw_rect(nm_d);
	glBindTexture(GL_TEXTURE_2D, tex_info);
	draw_rect(info);
	draw_button();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}

void  ogl_draw_scena_7(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_scena==7)
	tex_fon=tex_zagr_gem;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	
	glBindTexture(GL_TEXTURE_2D, tex_info);
	
	draw_button();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}

void  ogl_draw_scena_8(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(f_scena==8)
	tex_fon=tex_fon_7;
	glBindTexture(GL_TEXTURE_2D, tex_fon);
	draw_rect(fn_d);
	
		//printf("%d\n",double_score.f_aktiv);
	draw_tank_jag();
	//draw_button();
	baf_draw();
	draw_tank();
	exp_draw();
	exp_enemy_draw();
	boom_draw();
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, tex_zagr_game);
	draw_rect(zagr_game);
	draw_ram();
	/*glBindTexture(GL_TEXTURE_2D, tex_zag_game_left);
	draw_rect(zag_game_left);
	glBindTexture(GL_TEXTURE_2D, tex_zag_game_right);
	draw_rect(zag_game_right);*/
	glBindTexture(GL_TEXTURE_2D, tex_num);
	//draw_rect(num_score.draw);
	draw_number_score(score, num_score.draw);
	glBindTexture(GL_TEXTURE_2D, tex_num);
	//draw_rect(num_score.draw);
	draw_number_shell_bb(s_1, num_shell_bb.draw, p_bb);
	draw_number_shell_bb(s_2, num_shell_bp.draw, p_bp);
	draw_number_shell_bb(s_3, num_shell_of.draw, p_of);
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}



int record()
{
	freopen("record.in","r",stdin);
	freopen("record.in","w",stdout);
	scanf("%d",&record_score);
	if(score>record_score){
		record_score=score;
	printf("%d ",record_score);
	}
	
	return 0;
}

int draw_anim_strike()
{
	if((f_scena==3)||(f_scena==8)){
		baf_animation();
		for(i=0;i<p_bb;i++){
			if((shell_bb[i].f_wall==0)&&(shell_bb[i].f_shell==1)&&(shell_bb[i].vis==1)){
				if(hast.f_aktiv==1)
				shell_bb[i].tr_y+=10;
				if(hast.f_aktiv==0)
				shell_bb[i].tr_y+=7;
				
			}
			if(((shell_bb[i].tr_y>=hf)||(shell_bb[i].tr_y<=-3*hf/4)||(shell_bb[i].tr_x>=wf/2)||(shell_bb[i].tr_x<=-wf/2))&&(shell_bb[i].f_shell==1)){
			
				shell_bb[i].f_wall=1;
				shell_bb[i].vis=0;
				shell_bb[i].draw.y=0;	
			}
		}
		for(i=0;i<p_bp;i++){
			if((shell_bp[i].f_wall==0)&&(shell_bp[i].f_shell==1)&&(shell_bp[i].vis==1)){
				if(hast.f_aktiv==1)
				shell_bp[i].tr_y+=14;
				if(hast.f_aktiv==0)
				shell_bp[i].tr_y+=9;
				
			}
			if(((shell_bp[i].tr_y>=hf)||(shell_bp[i].tr_y<=-3*hf/4)||(shell_bp[i].tr_x>=wf/2)||(shell_bp[i].tr_x<=-wf/2))&&(shell_bp[i].f_shell==1)){
			
				shell_bp[i].f_wall=1;
				shell_bp[i].vis=0;
				shell_bp[i].draw.y=0;	
			}
		}
		for(i=0;i<p_of;i++){
			if((shell_of[i].f_wall==0)&&(shell_of[i].f_shell==1)&&(shell_of[i].vis==1)){
				if(hast.f_aktiv==1)
				shell_of[i].tr_y+=8;
				if(hast.f_aktiv==0)
				shell_of[i].tr_y+=5;
				
			}
			if(((shell_of[i].tr_y>=hf)||(shell_of[i].tr_y<=-3*hf/4)||(shell_of[i].tr_x>=wf/2)||(shell_of[i].tr_x<=-wf/2))&&(shell_of[i].f_shell==1)){
			
				shell_of[i].f_wall=1;
				shell_of[i].vis=0;
				shell_of[i].draw.y=0;	
			}
		}
				for(i=0;i<p_bb;i++){
					for(j=0;j<a;j++){
				
					//printf(" %.4f  %.4f  %.4f %.4f\n",jag[j].tr_x,jag[j].tr_y,shell_bb[i].tr_x,shell_bb[i].draw.y);
						if((shell_bb[i].f_wall==0)&&(shell_bb[i].tr_y>=jag[j].tr_y)&&(shell_bb[i].tr_x>=jag[j].tr_x-jag[j].draw.dx)&&(shell_bb[i].tr_x<=jag[j].tr_x+jag[j].draw.dx)&&(jag[j].vis==1)){
						shell_bb[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_en.ch, FALSE);
						shell_bb[i].vis=0;
						boom.f_vis=1;
						boom.tr_x=jag[j].tr_x;
						boom.tr_y=jag[j].tr_y;
						jag[j].hp-=2;
						if((jag[j].hp<=0)&&(jag[j].vis==1)){
						jag[j].vis=0;
						jag[j].resp=1;
						//printf("contact\n");
						if(double_score.f_aktiv==0)
						score+=100;
						if(double_score.f_aktiv==1)
						score+=200;	
						baf_int=rand()%10;
						baf_1.tr_x=jag[j].tr_x;
						baf_1.tr_y=jag[j].tr_y;
						//draw_number();
						heal.tr_x=jag[j].tr_x;
						heal.tr_y=jag[j].tr_y;
						rem.tr_x=jag[j].tr_x;
						rem.tr_y=jag[j].tr_y;
						gran.tr_x=jag[j].tr_x;
						gran.tr_y=jag[j].tr_y;
						double_score.tr_x=jag[j].tr_x;
						double_score.tr_y=jag[j].tr_y;
						hast.tr_x=jag[j].tr_x;
						hast.tr_y=jag[j].tr_y;
						toplivo.tr_x=jag[j].tr_x;
						toplivo.tr_y=jag[j].tr_y;
						//printf(" %d \n",score);
			
		
				}}}}
				
				for(i=0;i<p_bp;i++){
					for(j=0;j<a;j++){
				
					//printf(" %.4f  %.4f  %.4f %.4f\n",jag[j].tr_x,jag[j].tr_y,shell_bp[i].tr_x,shell_bp[i].draw.y);
						if((shell_bp[i].f_wall==0)&&(shell_bp[i].tr_y>=jag[j].tr_y)&&(shell_bp[i].tr_x>=jag[j].tr_x-jag[j].draw.dx)&&(shell_bp[i].tr_x<=jag[j].tr_x+jag[j].draw.dx)&&(jag[j].vis==1)){
						shell_bp[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_en.ch, FALSE);
						shell_bp[i].vis=0;
						boom.f_vis=1;
						boom.tr_x=jag[j].tr_x;
						boom.tr_y=jag[j].tr_y;
						jag[j].hp-=3;
						if((jag[j].hp<=0)&&(jag[j].vis==1)){
						jag[j].vis=0;
						jag[j].resp=1;
						//printf("contact\n");
						if(double_score.f_aktiv==0)
						score+=100;
						if(double_score.f_aktiv==1)
						score+=200;	
						baf_int=rand()%10;
						baf_1.tr_x=jag[j].tr_x;
						baf_1.tr_y=jag[j].tr_y;
						//draw_number();
						heal.tr_x=jag[j].tr_x;
						heal.tr_y=jag[j].tr_y;
						rem.tr_x=jag[j].tr_x;
						rem.tr_y=jag[j].tr_y;
						gran.tr_x=jag[j].tr_x;
						gran.tr_y=jag[j].tr_y;
						double_score.tr_x=jag[j].tr_x;
						double_score.tr_y=jag[j].tr_y;
						hast.tr_x=jag[j].tr_x;
						hast.tr_y=jag[j].tr_y;
						toplivo.tr_x=jag[j].tr_x;
						toplivo.tr_y=jag[j].tr_y;
						//printf(" %d \n",score);
			
		
				}}}}
				for(i=0;i<p_of;i++){
					for(j=0;j<a;j++){
				
					//printf(" %.4f  %.4f  %.4f %.4f\n",jag[j].tr_x,jag[j].tr_y,shell_of[i].tr_x,shell_of[i].draw.y);
						if((shell_of[i].f_wall==0)&&(shell_of[i].tr_y>=jag[j].tr_y)&&(shell_of[i].tr_x>=jag[j].tr_x-jag[j].draw.dx)&&(shell_of[i].tr_x<=jag[j].tr_x+jag[j].draw.dx)&&(jag[j].vis==1)){
						shell_of[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_en.ch, FALSE);
						shell_of[i].vis=0;
						boom.f_vis=1;
						boom.tr_x=jag[j].tr_x;
						boom.tr_y=jag[j].tr_y;
						jag[j].hp-=1;
						if((jag[j].hp<=0)&&(jag[j].vis==1)){
						jag[j].vis=0;
						jag[j].resp=1;
						//printf("contact\n");
						if(double_score.f_aktiv==0)
						score+=100;
						if(double_score.f_aktiv==1)
						score+=200;	
						baf_int=rand()%10;
						baf_1.tr_x=jag[j].tr_x;
						baf_1.tr_y=jag[j].tr_y;
						//draw_number();
						heal.tr_x=jag[j].tr_x;
						heal.tr_y=jag[j].tr_y;
						rem.tr_x=jag[j].tr_x;
						rem.tr_y=jag[j].tr_y;
						gran.tr_x=jag[j].tr_x;
						gran.tr_y=jag[j].tr_y;
						double_score.tr_x=jag[j].tr_x;
						double_score.tr_y=jag[j].tr_y;
						hast.tr_x=jag[j].tr_x;
						hast.tr_y=jag[j].tr_y;
						toplivo.tr_x=jag[j].tr_x;
						toplivo.tr_y=jag[j].tr_y;
						//printf(" %d \n",score);
			
		
				}}}}
				
				for(i=0;i<p_bb;i++){
					for(j=0;j<dfo;j++){
				
					//printf(" %.4f  %.4f  %.4f %.4f\n",jag[j].tr_x,jag[j].tr_y,shell_bb[i].tr_x,shell_bb[i].draw.y);
						if((shell_bb[i].f_wall==0)&&(shell_bb[i].tr_y>=def_obj[j].tr_y+def_obj[j].draw.dy)&&(shell_bb[i].tr_x>=def_obj[j].tr_x-def_obj[j].draw.dx)&&(shell_bb[i].tr_x<=def_obj[j].tr_x+def_obj[j].draw.dx)&&(def_obj[j].vis==1)){
						shell_bb[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_en.ch, FALSE);
						shell_bb[i].vis=0;
						boom.f_vis=1;
						boom.tr_x=def_obj[j].tr_x;
						boom.tr_y=def_obj[j].tr_y+def_obj[j].draw.dy;
						def_obj[j].hp-=1;
						if(def_obj[j].hp<=0){
						def_obj[j].vis=0;
						def_obj[j].resp=1;
						//printf("contact\n");
						if(double_score.f_aktiv==0)
						score+=50;
						if(double_score.f_aktiv==1)
						score+=100;
						baf_int=rand()%10;
						
						konv=pow(-1,j);
						baf_1.tr_x=def_obj[j].tr_x;
						baf_1.tr_y=def_obj[j].tr_y;
						heal.tr_x=def_obj[j].tr_x;
						heal.tr_y=def_obj[j].tr_y;
						rem.tr_x=def_obj[j].tr_x;
						rem.tr_y=def_obj[j].tr_y;
						gran.tr_x=def_obj[j].tr_x;
						gran.tr_y=def_obj[j].tr_y;
						double_score.tr_x=def_obj[j].tr_x;
						double_score.tr_y=def_obj[j].tr_y;
						hast.tr_x=def_obj[j].tr_x;
						hast.tr_y=def_obj[j].tr_y;
						toplivo.tr_x=def_obj[j].tr_x;
						toplivo.tr_y=def_obj[j].tr_y;
						//draw_number();
				}}}}
				
				for(i=0;i<p_bp;i++){
					for(j=0;j<dfo;j++){
				
					//printf(" %.4f  %.4f  %.4f %.4f\n",jag[j].tr_x,jag[j].tr_y,shell_bp[i].tr_x,shell_bp[i].draw.y);
						if((shell_bp[i].f_wall==0)&&(shell_bp[i].tr_y>=def_obj[j].tr_y+def_obj[j].draw.dy)&&(shell_bp[i].tr_x>=def_obj[j].tr_x-def_obj[j].draw.dx)&&(shell_bp[i].tr_x<=def_obj[j].tr_x+def_obj[j].draw.dx)&&(def_obj[j].vis==1)){
						shell_bp[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_en.ch, FALSE);
						shell_bp[i].vis=0;
						boom.f_vis=1;
						boom.tr_x=def_obj[j].tr_x;
						boom.tr_y=def_obj[j].tr_y+def_obj[j].draw.dy;
						def_obj[j].hp-=1;
						if(def_obj[j].hp<=0){
						def_obj[j].vis=0;
						def_obj[j].resp=1;
						//printf("contact\n");
						if(double_score.f_aktiv==0)
						score+=50;
						if(double_score.f_aktiv==1)
						score+=100;
						baf_int=rand()%10;
						
						konv=pow(-1,j);
						baf_1.tr_x=def_obj[j].tr_x;
						baf_1.tr_y=def_obj[j].tr_y;
						heal.tr_x=def_obj[j].tr_x;
						heal.tr_y=def_obj[j].tr_y;
						rem.tr_x=def_obj[j].tr_x;
						rem.tr_y=def_obj[j].tr_y;
						gran.tr_x=def_obj[j].tr_x;
						gran.tr_y=def_obj[j].tr_y;
						double_score.tr_x=def_obj[j].tr_x;
						double_score.tr_y=def_obj[j].tr_y;
						hast.tr_x=def_obj[j].tr_x;
						hast.tr_y=def_obj[j].tr_y;
						toplivo.tr_x=def_obj[j].tr_x;
						toplivo.tr_y=def_obj[j].tr_y;
						//draw_number();
				}}}}
				
				for(i=0;i<p_of;i++){
					for(j=0;j<dfo;j++){
				
					//printf(" %.4f  %.4f  %.4f %.4f\n",jag[j].tr_x,jag[j].tr_y,shell_of[i].tr_x,shell_of[i].draw.y);
						if((shell_of[i].f_wall==0)&&(shell_of[i].tr_y>=def_obj[j].tr_y+def_obj[j].draw.dy)&&(shell_of[i].tr_x>=def_obj[j].tr_x-def_obj[j].draw.dx)&&(shell_of[i].tr_x<=def_obj[j].tr_x+def_obj[j].draw.dx)&&(def_obj[j].vis==1)){
						shell_of[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_en.ch, FALSE);
						shell_of[i].vis=0;
						boom.f_vis=1;
						boom.tr_x=def_obj[j].tr_x;
						boom.tr_y=def_obj[j].tr_y+def_obj[j].draw.dy;
						def_obj[j].hp-=2;
						if(def_obj[j].hp<=0){
						def_obj[j].vis=0;
						def_obj[j].resp=1;
						//printf("contact\n");
						if(double_score.f_aktiv==0)
						score+=50;
						if(double_score.f_aktiv==1)
						score+=100;
						baf_int=rand()%10;
						
						konv=pow(-1,j);
						baf_1.tr_x=def_obj[j].tr_x;
						baf_1.tr_y=def_obj[j].tr_y;
						heal.tr_x=def_obj[j].tr_x;
						heal.tr_y=def_obj[j].tr_y;
						rem.tr_x=def_obj[j].tr_x;
						rem.tr_y=def_obj[j].tr_y;
						gran.tr_x=def_obj[j].tr_x;
						gran.tr_y=def_obj[j].tr_y;
						double_score.tr_x=def_obj[j].tr_x;
						double_score.tr_y=def_obj[j].tr_y;
						hast.tr_x=def_obj[j].tr_x;
						hast.tr_y=def_obj[j].tr_y;
						toplivo.tr_x=def_obj[j].tr_x;
						toplivo.tr_y=def_obj[j].tr_y;
						//draw_number();
				}}}}
		
		
					if(shell_bb[i].f_wall==1){
						shell_bb[i].tr_y=0;
						shell_bb[i].tr_x=0;
						shell_bb[i].f_resp=1;
					}
				for(i=0;i<a;i++){
					if(((enemy_shell[i].vis==1)&&(jag[i].resp==0))||((enemy_shell[i].vis==1)&&(enemy_shell[i].f_shell==1))){
						if(sd_exp_enemy[i].f_sound==1){
						//printf("r");
						//printf("%d\n",sd_exp_enemy[i].f_sound);
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_enemy[i].ch, FALSE);
						sd_exp_enemy[i].f_sound=0;
						//printf("%d\n",sd_exp_enemy[i].f_sound);
						//printf("%d\n",i);
						}
						mnoj=pow(-1,i);
						enemy_shell[i].tr_y-=4+mnoj*rand()%3;
						
					}
					if((jag[i].f_flash==1)&&(enemy_shell[i].vis==1)){
						exp_enemy[i].f_vis=1;
						
						jag[i].f_flash=0;
						}
					if((enemy_shell[i].tr_y<=-hf/2)){
						enemy_shell[i].f_wall=1;
						enemy_shell[i].f_resp=1;
						enemy_shell[i].vis=0;
						enemy_shell[i].tr_y=jag[i].tr_y-50;
						enemy_shell[i].f_shell=0;
						exp_enemy[i].f_vis=0;
					}
					if((enemy_shell[i].tr_x>=(ap.tr_x-ap.draw.dx))&&(enemy_shell[i].tr_x<=(ap.tr_x+ap.draw.dx))&&(enemy_shell[i].tr_y>=ap.tr_y-ap.draw.dy)&&(enemy_shell[i].tr_y<=ap.tr_y+ap.draw.dy)){
						enemy_shell[i].f_wall=1;
						if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_me.ch, FALSE);
						enemy_shell[i].f_resp=1;
						enemy_shell[i].vis=0;
						enemy_shell[i].tr_y=jag[i].tr_y-50;
						enemy_shell[i].f_shell=0;
						ap.hp=ap.hp-1;
						boom.f_vis=1;
						boom.tr_x=ap.tr_x;
						boom.tr_y=ap.tr_y;
						if(deltax>10)
						deltax-=2;
						hp_ap.draw.dx-=16;
						//exp_enemy[i].f_vis=0;
					}
				}
				//printf("two\n");
				if((baf_1.tr_x>=ap.tr_x-1.2*ap.draw.dx)&&(baf_1.tr_x<=ap.tr_x+1.2*ap.draw.dx)&&(baf_1.tr_y>=ap.tr_y-ap.draw.dy)&&(baf_1.tr_y<=ap.tr_y+ap.draw.dy)&&(baf_int==2)){
					if(f_voulm==1)
						BASS_ChannelPlay(sd_baf.ch, FALSE);
					if(s_1>=5){
						for(i=s_1-5;i<s_1;i++){
							shell_bb[i].f_wall=0;
							shell_bb[i].vis=1;
							shell_bb[i].f_shell=0;
							shell_bb[i].tr_x=ap.tr_x;
							shell_bb[i].tr_y=ap.tr_y;
							baf_1.tr_x=0;
							baf_1.tr_y=0;
							shell_bb[i].time_rts=0;
							shell_bb[i].f_resp=0;
							shell_bb[i].f_exp=1;
					}
					s_1=s_1-5;
					}
					if(s_1<5){
						for(i=0;i<s_1;i++){
							shell_bb[i].f_wall=0;
							shell_bb[i].vis=1;
							shell_bb[i].f_shell=0;
							shell_bb[i].tr_x=ap.tr_x;
							shell_bb[i].tr_y=ap.tr_y;
							baf_1.tr_y=0;
							baf_1.tr_x=0;
							shell_bb[i].time_rts=0;
							shell_bb[i].f_resp=0;
							shell_bb[i].f_exp=1;
					}
					s_1=0;
					}
					baf_1.tr_y=0;
					baf_1.tr_x=0;
					baf_1.f_vis=0;
					baf_int=0;
				
				}
				
				if((heal.tr_x>=ap.tr_x-1.2*ap.draw.dx)&&(heal.tr_x<=ap.tr_x+1.2*ap.draw.dx)&&(heal.tr_y>=ap.tr_y-ap.draw.dy)&&(heal.tr_y<=ap.tr_y+ap.draw.dy)&&(baf_int==3)){
					if(f_voulm==1)
						BASS_ChannelPlay(sd_baf.ch, FALSE);
					if(ap.hp<3){
						ap.hp+=1;
						hp_ap.draw.dx+=16;
					}
					heal.tr_y=0;
					heal.tr_x=0;
					baf_int=0;
					heal.f_vis=0;
				}
				
				if((rem.tr_x>=ap.tr_x-1.2*ap.draw.dx)&&(rem.tr_x<=ap.tr_x+1.2*ap.draw.dx)&&(rem.tr_y>=ap.tr_y-ap.draw.dy)&&(rem.tr_y<=ap.tr_y+ap.draw.dy)&&(baf_int==1)){
					if(f_voulm==1)
						BASS_ChannelPlay(sd_baf.ch, FALSE);
				if(deltax<15){
					deltax+=3;
				}
				rem.tr_y=0;
				rem.tr_x=0;
				baf_int=0;
				rem.f_vis=0;
				}
				
				if((gran.tr_x>=ap.tr_x-1.3*ap.draw.dx)&&(gran.tr_x<=ap.tr_x+1.3*ap.draw.dx)&&(gran.tr_y>=ap.tr_y-ap.draw.dy)&&(gran.tr_y<=ap.tr_y+ap.draw.dy)&&(baf_int==4)){
					ap.hp=ap.hp-1;
					if(f_voulm==1)
						BASS_ChannelPlay(sd_exp_me.ch, FALSE);
					if(deltax>10)
					deltax-=2;
					hp_ap.draw.dx-=16;
					gran.tr_y=0;
					gran.tr_x=0;
					baf_int=0;
					gran.f_vis=0;
					boom.f_vis=1;
					boom.tr_x=ap.tr_x;
					boom.tr_y=ap.tr_y;
					
					
				}
				//printf("contact 0 \n");
				if((double_score.tr_x>=ap.tr_x-1.2*ap.draw.dx)&&(double_score.tr_x<=ap.tr_x+1.2*ap.draw.dx)&&(double_score.tr_y>=ap.tr_y-ap.draw.dy)&&(double_score.tr_y<=ap.tr_y+ap.draw.dy)&&(double_score.f_vis==1)){
					if(f_voulm==1)
						BASS_ChannelPlay(sd_baf.ch, FALSE);
					//printf("ds on\n");
					double_score.f_aktiv=1;
					//double_score.time_x=0;
					//double_score.time_old=0;
					double_score.tr_y=0;
					double_score.tr_x=0;
					baf_int=0;
					double_score.f_vis=0;
				}
				if((hast.tr_x>=ap.tr_x-1.2*ap.draw.dx)&&(hast.tr_x<=ap.tr_x+1.2*ap.draw.dx)&&(hast.tr_y>=ap.tr_y-ap.draw.dy)&&(hast.tr_y<=ap.tr_y+ap.draw.dy)&&(hast.f_vis==1)){
				if(f_voulm==1)
					BASS_ChannelPlay(sd_baf.ch, FALSE);
				//printf("hast on\n");
				hast.f_aktiv=1;
				hast.tr_x=0;
				hast.tr_y=0;
				baf_int=0;
				hast.f_vis=0;
				}
				if((toplivo.tr_x>=ap.tr_x-1.2*ap.draw.dx)&&(toplivo.tr_x<=ap.tr_x+1.2*ap.draw.dx)&&(toplivo.tr_y>=ap.tr_y-ap.draw.dy)&&(toplivo.tr_y<=ap.tr_y+ap.draw.dy)&&(toplivo.f_vis==1)){
				if(f_voulm==1)
					BASS_ChannelPlay(sd_baf.ch, FALSE);
				//printf("top on\n");
				toplivo.f_aktiv=1;
				toplivo.tr_x=0;
				toplivo.tr_y=0;
				deltax=25;
				baf_int=0;
				toplivo.f_vis=0;
				}
				}
					
				if(ap.hp==0){
					//record();
					f_last_scena=f_scena;
					ap.hp=3;
					f_scena=4;
					
				}
				if((score>=5000)&&(f_scena==3)){
					//record();
					f_last_scena=3;
					score=0;
					f_scena=5;
					
				}
				if((score>=8000)&&(f_scena==8)){
					//record();
					f_last_scena=8;
					score=0;
					f_scena=5;
					
				}
					

	
	return 0;
}



int enemy_shell_resp( int t)
{
	for(i=0;i<a;i++){
	if(enemy_shell[i].f_resp==1){
		
			enemy_shell[i].time_rts+=t;
		if(enemy_shell[i].time_rts>= enemy_shell[i].time_sps){
			if(jag[i].vis==1){
			enemy_shell[i].vis=1;
			enemy_shell[i].f_resp=0;
			enemy_shell[i].time_rts=0;
			enemy_shell[i].f_wall=0;
			enemy_shell[i].f_shell=1;
			jag[i].f_flash=1;
			sd_exp_enemy[i].f_sound=1;
			
			}
		}
}}

	return 0;
}

int shell_resp(int t)
{
	if(shell_bb[s_1].f_resp==1){
			shell_bb[s_1].time_rts+=t;
		if(shell_bb[s_1].time_rts>= shell_bb[s_1].time_sps){
			s_1++;
			f_exp=1;
			
		//printf("  %d \n",s_1);
			
			//printf("%d\n",f_resp_shell);
			}
		}
		if(shell_bp[s_2].f_resp==1){
			shell_bp[s_2].time_rts+=t;
		if(shell_bp[s_2].time_rts>= shell_bp[s_2].time_sps){
			s_2++;
			f_exp=1;
			
		//printf("  %d \n",s_1);
			
			//printf("%d\n",f_resp_shell);
			}
		}
		if(shell_of[s_3].f_resp==1){
			shell_of[s_3].time_rts+=t;
		if(shell_of[s_3].time_rts>= shell_of[s_3].time_sps){
			s_3++;
			f_exp=1;
			
		//printf("  %d \n",s_1);
			
			//printf("%d\n",f_resp_shell);
			}
		}
	return 0;
}

int draw_resp( int t)
{

for(i=0;i<a;i++){
	if(jag[i].resp==1){
		
			jag[i].time_rt+=t;
		if(jag[i].time_rt>= jag[i].time_sp){
			jag[i].vis=1;
			jag[i].hp=2;
			jag[i].resp=0;
			jag[i].time_rt=0;
			jag[i].f_flash=1;
		}
}}
	return 0;
}
int toplivo_time(int t){
	if((toplivo.f_aktiv==1)&&(f_scena==3)){	
		toplivo.time_x+=t;
		if(toplivo.time_x >= toplivo.time_old){
			toplivo.f_aktiv=0;
			toplivo.time_x=0;
			deltax=15;
			//printf("top off\n");
	}
	}
	
	return 0;
}

int hast_time(int t){
	if((hast.f_aktiv==1)&&(f_scena==3)){

		hast.time_x+=t;
		if(hast.time_x >= hast.time_old){
			hast.f_aktiv=0;
			hast.time_x=0;	
			//printf("hast off\n");
	}
	}
	

	return 0;
}

int double_score_time(int t){
	if((double_score.f_aktiv==1)&&(f_scena==3)){
		double_score.time_x+=t;
	if(double_score.time_x >= double_score.time_old){
			double_score.f_aktiv=0;
			double_score.time_x=0;
			//printf("ds off\n");
	}
	}
	return 0;
}

int draw_animation()
{
 if(ap.tr_x-ap.draw.dx<=-wf/2){
	ap.tr_x=-wf/2+ap.draw.dx;
	bh.tr_x=ap.tr_x;
	}
 if(ap.tr_x+ap.draw.dx>=wf/2){
	ap.tr_x=wf/2-ap.draw.dx;
	 bh.tr_x=ap.tr_x;
	}
 //if(bh.tr_x-bh.draw.dx<=-wf/2)
	// bh.tr_x=-wf/2+bh.draw.dx;
 //if(ap.tr_x+ap.draw.dx>=wf)
	 //bh.tr_x=wf/2-bh.draw.dx;

	draw_anim_strike();

return 0;
}




//Функция отрисовки
void  ogl_draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			
	
	
	if(f_scena==0)
	ogl_draw_scena_0();
	
	if(f_scena==1)
	ogl_draw_scena_1();

	if(f_scena==2)
	ogl_draw_scena_2();
	if(f_scena==3)
	ogl_draw_scena_3();
	if(f_scena==4)
	ogl_draw_scena_4();
	if(f_scena==5)
	ogl_draw_scena_5();
	if(f_scena==6)
	ogl_draw_scena_6();
	if(f_scena==7)
	ogl_draw_scena_7();
	if(f_scena==8)
	ogl_draw_scena_8();
//printf("%d\n",f_scena);
	exp_enemy_time(20);
	
	/*if((sd_fon.f_sound==1)&&(f_voulm==1)&&(f_music==1)){
		//printf("ya tyt\n");
		BASS_ChannelPlay(sd_fon.ch, FALSE);
		sd_fon.f_sound=0;
		}*/

}
