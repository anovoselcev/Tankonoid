#include "callback.h"

extern int done,f_scena,tex_start,tex_start_00,tex_start_01,tex_exit,tex_exit_00,tex_exit_01,w,h,f_anim,p_bb,p_bp,p_of,tex_lvl_one_01,tex_lvl_one_02;
//extern rect_t bt1_d,bt2_d,ap_d,st_d;
extern int f_resp_shell,score,f_voulm,f_music;
int tx,kx,i,s_1=0,s_2=0,s_3=0,how_shell_bb=0,deltax=15,f_type_shell=1,exp_s=0,f_exp=1,f_scena_save,f_pause=0,f_last_scena;
extern float wf,hf;
extern button_t bt1,bt2,lvl_one,lvl_start,help,voulm,music,lvl_two;
extern tank_t ap,jg1,jg2,st,bh,hp_ap;
extern shell_t shell_bb[100],shell_bp[20],shell_of[10];
extern exp_t exp_ap;
extern sound_t sd_exp_ap,sd_fon,sd_move,sd_press;
extern char sndfon;
//функция реакции на нажатие клавиши
//GLFW_PRESS GLFW_REPEAT GLFW_RELEASE
void key_press(GLFWwindow *w, int key, int scancode, int action, int mods)
{
	if (( key == GLFW_KEY_ESCAPE ) && ( action == GLFW_PRESS)){
		//printf("Press - %i\n",key);
		if(f_scena==0){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			done=0;
			}
		if(f_scena==1){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=0;
			help.focus=0;
			lvl_one.focus=0;
			lvl_two.focus=0;
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		if(f_scena==2){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=1;
			help.focus=0;
			lvl_one.focus=0;
			lvl_two.focus=0;
			//sd_fon.ch=BASS_SampleGetChannel(sd_fon.sam, FALSE );
			sd_fon.f_sound=1;
		
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		if(f_scena==7){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=1;
			
			//sd_fon.ch=BASS_SampleGetChannel(sd_fon.sam, FALSE );
			sd_fon.f_sound=1;
		
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		if(f_scena==3){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=2;
			help.focus=0;
			//sd_fon.f_sound=0;
			//BASS_ChannelPlay(sd_fon.ch, FALSE);
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		if(f_scena==4){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			tank();
			//sd_fon.f_sound=0;
			help.focus=0;
			draw_shell();
			s_1=0;
			f_resp_shell=0;
			score=0;
			how_shell_bb=0;
			deltax=15;
			init_exp();
			baf_init();
			init_debaf();
			if(f_last_scena==3)
			f_scena=2;
			if(f_last_scena==8)
			f_scena=7;
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		if(f_scena==5){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			if(f_last_scena==3)
			f_scena=2;
			if(f_last_scena==8)
			f_scena=7;
			//sd_fon.f_sound=0;
			/*help.focus=0;
			tank();
			draw_shell();
			s=0;
			f_resp_shell=0;
			score=0;
			how_shell_bb=0;
			deltax=15;
			init_exp();
			baf_init();
			init_debaf();*/
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
			//printf("%d\n",f_scena);
		}
		if(f_scena==6){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=f_scena_save;
			if(f_scena>1){
				//BASS_ChannelStop(sd_fon.ch);
				//sd_fon.f_sound=0;
			}
		
		}
		
		if(f_scena==8){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=7;
			
			//sd_fon.f_sound=0;
			//BASS_ChannelPlay(sd_fon.ch, FALSE);
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		}
	if (( key == GLFW_KEY_F1) && ( action == GLFW_PRESS)&&(f_scena!=6)) {
		if(f_voulm==1)
			BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena_save=f_scena;
			f_scena=6;
			sd_fon.f_sound=1;
			
		}
	
	if (( key == GLFW_KEY_LEFT ) && (( action == GLFW_REPEAT))){
		//printf("7\n");
		}
	if (( key == GLFW_KEY_RIGHT  ) && (( action == GLFW_REPEAT))){
		
			
		}
	if (( key == GLFW_KEY_SPACE   ) && ( action == GLFW_PRESS)){
		
		}
	if (( key == GLFW_KEY_ENTER  ) && ( action == GLFW_PRESS)){

		}
		if (( key == GLFW_KEY_F9 )&&( action == GLFW_PRESS)){
		//printf("press");
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
		if(f_pause==0){
			f_pause=1;
			if(f_voulm==1)
				BASS_ChannelPause(sd_fon.ch);
			
		}
		else
		{
			f_pause=0;
			if(f_voulm==1)
				BASS_ChannelPlay(sd_fon.ch, FALSE);
		}
		//printf("%d\n",f_pause);
		}
	
}	
	


//функция реакции на ввод символов
void char_input(GLFWwindow *w, unsigned int ch)
{
	if ( ch == 'q' || ch == 'Q' )
		//done=0;
	if (ch == 'f' || ch == 'F' )
		printf("Press - %c\n",ch);	
	/*if ( ch == 'w' || ch == 'W' ){
		ap.tr_y=ap.tr_y+30;
		bh.tr_y=ap.tr_y;
		hp_ap.draw.y=ap.tr_y-40;
		for(i=0;i<p;i++){
		if(shell[i].f_shell==0)
		shell[i].tr_y=ap.tr_y;
		}
	}
	if (ch == 's' || ch == 'S' ){
		ap.tr_y=ap.tr_y-20;	
		for(i=0;i<p;i++){
		if(shell[i].f_shell==0)
		shell[i].tr_y=ap.tr_y;
		}
		bh.tr_y=ap.tr_y;
		hp_ap.tr_y=ap.tr_y-40;
	}*/
	
	if (( ch == 'a' || ch == 'A' )&&((f_scena==3)||(f_scena==8))){
		ap.tr_x=ap.tr_x-deltax;
		//BASS_ChannelPlay(sd_move.ch, FALSE);
		bh.tr_x=ap.tr_x;
		hp_ap.tr_x=ap.tr_x;
		exp_ap.tr_x=bh.tr_x-1;
		exp_ap.tr_y=bh.tr_y+90;
		//printf("a\n");
		for(i=0;i<p_bb;i++){
		if(shell_bb[i].f_shell==0)
		shell_bb[i].tr_x=ap.tr_x;
		}
		for(i=0;i<p_bp;i++){
		if(shell_bp[i].f_shell==0)
		shell_bp[i].tr_x=ap.tr_x;
		}
		for(i=0;i<p_of;i++){
		if(shell_of[i].f_shell==0)
		shell_of[i].tr_x=ap.tr_x;
		}
	}
	if (( ch == 'd' || ch == 'D' )&&((f_scena==3)||(f_scena==8))){
		
		ap.tr_x=ap.tr_x+deltax;
		//BASS_ChannelPlay(sd_move.ch, FALSE);
		bh.tr_x=ap.tr_x;
		hp_ap.tr_x=ap.tr_x;
		exp_ap.tr_x=bh.tr_x-1;
		exp_ap.tr_y=bh.tr_y+90;
		//printf("d\n");
		for(i=0;i<p_bb;i++){
		if(shell_bb[i].f_shell==0)
		shell_bb[i].tr_x=ap.tr_x;
		}
		for(i=0;i<p_bp;i++){
		if(shell_bp[i].f_shell==0)
		shell_bp[i].tr_x=ap.tr_x;
		}
		for(i=0;i<p_of;i++){
		if(shell_of[i].f_shell==0)
		shell_of[i].tr_x=ap.tr_x;
		}
	
	}
	
	if ( ch == '1' || ch == '1' ){
		f_type_shell=1;
		}
		
	if ( ch == '2' || ch == '2' ){
		f_type_shell=2;
		}
		if ( ch == '3' || ch == '3' ){
		f_type_shell=3;
		}
		
		
	
	
}



//функция реакции на нажатие кнопок мыши
void mouse_button_press(GLFWwindow *w, int button, int action, int mods)
{
	
//action is GLFW_PRESS or GLFW_RELEASE ,MBM_press=0,RBM_press=0
	if ( button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS){
		if(bt2.tex==tex_exit_01){
			if(f_voulm==1)
			BASS_ChannelPlay(sd_press.ch, FALSE);
			done=0;
			}
			
		if(((f_scena==3)||(f_scena==8))&&(s_1<p_bb)&&(f_type_shell==1)){
			shell_bb[s_1].f_shell=1;
			shell_bb[s_1].f_resp=1;
			how_shell_bb++;
			//exp_s++;
			//printf("  %d \n",exp_s);
			if((shell_bb[s_1].f_exp==1)){
			exp_ap.f_vis=1;
			shell_bb[s_1].f_exp=0;
			sd_exp_ap.f_sound=1;
			if((sd_exp_ap.f_sound==1)&&(f_voulm==1))
				BASS_ChannelPlay(sd_exp_ap.ch, FALSE);
			}
			//printf(" %d %d \n",s,score);
			
		}
		if(((f_scena==3)||(f_scena==8))&&(s_2<p_bp)&&(f_type_shell==2)){
			shell_bp[s_2].f_shell=1;
			shell_bp[s_2].f_resp=1;
			//how_shell_bb++;
			//exp_s++;
			//printf("  %d \n",exp_s);
			if((shell_bp[s_2].f_exp==1)){
			exp_ap.f_vis=1;
			shell_bp[s_2].f_exp=0;
			sd_exp_ap.f_sound=1;
			if((sd_exp_ap.f_sound==1)&&(f_voulm==1))
				BASS_ChannelPlay(sd_exp_ap.ch, FALSE);
			}
			//printf(" %d %d \n",s,score);
			
		}
		if(((f_scena==3)||(f_scena==8))&&(s_3<p_of)&&(f_type_shell==3)){
			shell_of[s_3].f_shell=1;
			shell_of[s_3].f_resp=1;
			//how_shell_bb++;
			//exp_s++;
			//printf("  %d \n",exp_s);
			if((shell_of[s_3].f_exp==1)){
			exp_ap.f_vis=1;
			shell_of[s_3].f_exp=0;
			sd_exp_ap.f_sound=1;
			if((sd_exp_ap.f_sound==1)&&(f_voulm==1))
				BASS_ChannelPlay(sd_exp_ap.ch, FALSE);
			}
			//printf(" %d %d \n",s,score);
			
		}
		//printf("%d",s);
			
		if((bt1.focus==1)&&(f_scena==0)){
			if(f_voulm==1)
			BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=1;
			help.focus=0;
		//glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);
		/*tank();
		draw_shell();
		s=0;
		f_resp_shell=0;
		score=0;
		how_shell_bb=0;
		deltax=15;
		init_exp();
		baf_init();
		init_debaf();*/
		}
		if((lvl_one.focus==1)&&(f_scena==1)){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=2;
			lvl_one.focus=0;
			lvl_two.focus=0;
			//BASS_ChannelStop(sd_fon.ch);
			help.focus=0;
			//sd_fon.f_sound=0;
			
		//if(f_shell>=3){
		//draw_animation();
		}
		if((lvl_two.focus==1)&&(f_scena==1)){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena=7;
			lvl_one.focus=0;
			lvl_two.focus=0;
			//BASS_ChannelStop(sd_fon.ch);
			//help.focus=0;
			//sd_fon.f_sound=0;
			
		//if(f_shell>=3){
		//draw_animation();
		}
		if((lvl_start.focus==1)&&((f_scena==2)||(f_scena==7))){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			if(f_scena==2){
				
				//BASS_ChannelStop(sd_fon.ch);
				//sd_fon.f_sound=0;
				help.focus=0;
				tank();
				draw_shell();
				s_1=0;
				s_2=0;
				s_3=0;
				f_type_shell=1;
				f_resp_shell=0;
				score=0;
				how_shell_bb=0;
				deltax=15;
				init_exp();
				baf_init();
				init_debaf();
				f_scena=3;
			}
			if(f_scena==7){
				help.focus=0;
				tank();
				draw_shell();
				s_1=0;
				s_2=0;
				s_3=0;
				f_type_shell=1;
				f_resp_shell=0;
				score=0;
				how_shell_bb=0;
				deltax=15;
				init_exp();
				baf_init();
				init_debaf();
				f_scena=8;
			}
			
			glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);
		}
		if((help.focus==1)&&(f_scena!=3)&&(f_scena!=6)){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			f_scena_save=f_scena;
			f_scena=6;
			help.focus=0;
			sd_fon.f_sound=1;
			
		}
		}
		if((voulm.focus==1)&&(f_scena!=3)&&(f_scena!=8)){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			if(f_voulm==1){
				//printf("voulm_off\n");
				voulm.focus=0;
				f_voulm=0;
				f_music=0;
				sd_fon.f_sound=1;
				BASS_ChannelStop(sd_fon.ch);
			}
			else{
				//printf("voulm_on\n");
				voulm.focus=0;
				f_voulm=1;
				
				sd_fon.f_sound=1;
				if(f_music==0){
					sd_fon.ch=BASS_SampleGetChannel(sd_fon.sam, FALSE );
					BASS_ChannelPlay(sd_fon.ch, FALSE);
				}
				f_music=1;
			}
			
		}
		if((music.focus==1)&&(f_scena!=3)&&(f_scena!=8)){
			if(f_voulm==1)
				BASS_ChannelPlay(sd_press.ch, FALSE);
			if(f_music==1){
				//printf("music_off\n");
				music.focus=0;
				f_music=0;
				//sd_fon.f_sound=1;
				BASS_ChannelStop(sd_fon.ch);
			}
			else{
				//printf("music_on\n");
				music.focus=0;
				f_music=1;
				sd_fon.f_sound=1;
				sd_fon.ch=BASS_SampleGetChannel(sd_fon.sam, FALSE );
				BASS_ChannelPlay(sd_fon.ch, FALSE);
			}
			
		}
		}
	
	if ( button == GLFW_MOUSE_BUTTON_MIDDLE){
		if (action == GLFW_PRESS){
			//MBM_press=1; printf("Press middle mouse button\n");;
		}
		else {
			//MBM_press=0; printf("Release middle mouse button\n");
		}
	}	
	if ( button == GLFW_MOUSE_BUTTON_RIGHT){
		if (action == GLFW_PRESS){
			//RBM_press=1; printf("Press right mouse button\n");
		}
		else {
			//RBM_press=0; printf("Release right mouse button\n");
		}	
	}
		
}

//функция реакции на движение мыши
void mouse_pos(GLFWwindow *w, double x, double y)
{
	
	//int w_width, w_height;
	//printf("mouse pos: x= %5.2f y= %5.2f\n",x,y);
	if(f_scena==0)
	{
	if(((x>=(bt1.draw.x-bt1.draw.dx)+wf/2)&&(x<=(bt1.draw.x+bt1.draw.dx)+wf/2))&&((y<=hf/2-bt1.draw.y+bt1.draw.dy)&&(y>=hf/2-bt1.draw.y-bt1.draw.dy)))
	{
	bt1.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	bt1.focus=0;
	}
	if(((x>=(bt2.draw.x-bt2.draw.dx)+wf/2)&&(x<=(bt2.draw.x+bt2.draw.dx)+wf/2))&&((y<=hf/2-bt2.draw.y+bt2.draw.dy)&&(y>=hf/2-bt2.draw.y-bt2.draw.dy)))
	{
	bt2.focus=1;
	//tex_exit=tex_exit_01;
	}
	else
	{
	//tex_exit=tex_exit_00;
	bt2.focus=0;
	}
	}
	if(f_scena!=0){
		bt1.focus=0;
		bt2.focus=0;
	}
	if(f_scena==1)
	{
	if(((x>=(lvl_one.draw.x-lvl_one.draw.dx)+wf/2)&&(x<=(lvl_one.draw.x+lvl_one.draw.dx)+wf/2))&&((y<=hf/2-lvl_one.draw.y+lvl_one.draw.dy)&&(y>=hf/2-lvl_one.draw.y-lvl_one.draw.dy)))
	{
	lvl_one.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	lvl_one.focus=0;
	}
	if(((x>=(lvl_two.draw.x-lvl_two.draw.dx)+wf/2)&&(x<=(lvl_two.draw.x+lvl_two.draw.dx)+wf/2))&&((y<=hf/2-lvl_two.draw.y+lvl_two.draw.dy)&&(y>=hf/2-lvl_two.draw.y-lvl_two.draw.dy)))
	{
	lvl_two.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	lvl_two.focus=0;
	}
	}
	if(f_scena!=1)
		lvl_one.focus=0;
	if((f_scena==2)||(f_scena==7)){
	if(((x>=(lvl_start.draw.x-lvl_start.draw.dx)+wf/2)&&(x<=(lvl_start.draw.x+lvl_start.draw.dx)+wf/2))&&((y<=hf/2-lvl_start.draw.y+lvl_start.draw.dy)&&(y>=hf/2-lvl_start.draw.y-lvl_start.draw.dy)))
	{
		//printf("focus");
	lvl_start.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	lvl_start.focus=0;
	}
	}
	if((f_scena!=2)&&(f_scena!=7))
		lvl_start.focus=0;
	if(((x>=(help.draw.x-help.draw.dx)+wf/2)&&(x<=(help.draw.x+help.draw.dx)+wf/2))&&((y <= hf/2 -help.draw.y+help.draw.dy)&&(y>=hf/2-help.draw.y-help.draw.dy))){
	help.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	help.focus=0;
	}
	if(((x>=(voulm.draw.x-voulm.draw.dx)+wf/2)&&(x<=(voulm.draw.x+voulm.draw.dx)+wf/2))&&((y <= hf/2 -voulm.draw.y+voulm.draw.dy)&&(y>=hf/2-voulm.draw.y-voulm.draw.dy))){
	voulm.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	voulm.focus=0;
	}
	if(((x>=(music.draw.x-music.draw.dx)+wf/2)&&(x<=(music.draw.x+music.draw.dx)+wf/2))&&((y <= hf/2 -music.draw.y+music.draw.dy)&&(y>=hf/2-music.draw.y-music.draw.dy))){
	music.focus=1;
	//tex_start=tex_start_01;
	}
	else
	{
	//tex_start=tex_start_00;
	music.focus=0;
	}
	if((f_scena==4)||(f_scena==5))
		glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
	tx=bh.tr_x;
	if((f_scena==3)&&(tx!=x)){
		kx=(tx-x);
		//printf("%d\n",kx);
		//printf(" %d ",kx);
		//ap.draw.x=ap.draw.x+(x-tx);
			//f(f_shell==0)
				//st.draw.x=ap.draw.x;
		//st.draw.y=ap.draw.y;
	}

	//scena(f_scena_1_1,f_scena_1_2);*/
	//c_x=x; c_y=y;	
	//glfwGetWindowSize(w, &w_width, &w_height);
	//cursor_draw(w_width, w_height, x, y, -2.0);
	
}

//функция реакции на прокрутку колеса мыши
void mouse_wheel(GLFWwindow *w, double x, double y)
{	
		
		//xx+=x;yy+=y;
		//printf("Wheel pos x= %5.2f y= %5.2f\n",xx,yy);	
}



