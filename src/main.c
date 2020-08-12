#include "main.h"
extern rect_t jg1d,jg2d;
float rat=(float) W_WIDTH / (float) W_HEIGHT;
extern int f_pause;
extern exp_t exp_ap;
extern sound_t sd_exp_ap,sd_fon;


//sound virable;
/*HSTREAM stream;
HSAMPLE sam01 ;
HCHANNEL ch01;
int flag_SND=1;
char *sndrs="../../data/sound/sfx16.wav";*/

//Функция завершения работы программы
void prog_exit(GLFWwindow *w)
{		
	if (!glfwWindowShouldClose(w))  {
           glfwDestroyWindow(w);
       }	
	   //BASS_SampleFree(sam01);
		//BASS_Free();
	glfwTerminate();
	//printf("%s\n","Exit Ok");	
}



//Функция подсчета  и вывода FPS
void fps_counter(GLFWwindow *w, int t, char *caption, int w_mode)
{	
	
	if (fps_enable)	{
		current_time=glfwGetTime();
		frame+=1.0;
		if ((current_time - old_time)*1000 >= t) {
			frame_sum+=frame;		
			double fps= frame_sum /  (current_time) ;		
			sprintf(str_title,"%s: FPS:%.2f FPS_AVR:%.2f ",caption, frame/(t/1000), fps);		
			frame=0.0; old_time=current_time;	
			if (!w_mode)	
				glfwSetWindowTitle(w,str_title);
			printf("%s\n",str_title);
		}	
	}		
}

//Функция таймер анимации
void timer_animation(int t)
{	
	
		current_time=glfwGetTime();
		if ((current_time - old_time)*1000 >= t) {				
		 old_time=current_time;	
		 draw_animation();
		 baf_animation();
		 //printf("timer run %i \n",t);
		}			
}

int timer_recpawn_jag(int t)
{	
		
		current_time_r=glfwGetTime();
		if ((current_time_r - old_time_r)*1000 >= t) {	
			//printf("timer run %i \n",t);			
		 old_time_r=current_time_r;	
		 draw_resp(t);
		 double_score_time(t);
		hast_time(t);
		toplivo_time(t);
		
		}	
return 0;		
}

int timer_recpawn_enemy_shell(int t)
{	
		
		current_time_rs=glfwGetTime();
		if ((current_time_rs - old_time_rs)*1000 >= t) {	
			//printf("timer run %i \n",t);			
		 old_time_rs=current_time_rs;	
		 //shell_resp(t);
		 enemy_shell_resp(t);
		 //shell_resp(t);
		}	
return 0;		
}

int timer_recpawn_shell(int t)
{	
		
		current_time_rss=glfwGetTime();
		if ((current_time_rss - old_time_rss)*1000 >= t) {	
			//printf("timer run %i \n",t);			
		 old_time_rss=current_time_rss;	
		 //shell_resp(t);
		 shell_resp(t);
		 //shell_resp(t);
		}	
return 0;		
}




//Функция обработки параметров командной строки
void argc_init(int argc, char **argv)
{
	int i;
	for(i=1;i<argc;i++) {	
		if (!strcmp(argv[i],"--info")){
			gl_info=1;glfw_info=1;	
		}
		if (!strcmp(argv[i],"--full")) {
			w_mode=1;
		}
		if (!strcmp(argv[i],"--fps")){
			fps_enable=1;
		}			
	}
}

//Функция основного цикла программы
void glfw_main_loop(GLFWwindow *w)
{
	 while( done )   {
		if( glfwWindowShouldClose(w) )  {
				done = 0;
		}	
		glfwPollEvents();
		/*if (flag_SND==0) {
			if (BASS_ChannelIsActive(ch01)!=BASS_ACTIVE_PAUSED)
				BASS_ChannelPause(ch01);
			}
		else {
			if (BASS_ChannelIsActive(ch01)==BASS_ACTIVE_PAUSED)
				BASS_ChannelPlay(ch01, FALSE);
		}*/
		
		if(f_pause==0){
		ogl_draw();	
		timer_animation(5);
		timer_recpawn_jag(500);
		timer_recpawn_enemy_shell(200);
		timer_recpawn_shell(200);
		}
		fps_counter(w,F_TIME,W_CAPTION,w_mode);
		glfwSwapBuffers(w);	
		//printf("%d\n",sd_fon.f_sound);
		}
	prog_exit(w);
}


//Основная программа
int main(int argc, char **argv)
{	
	argc_init(argc, argv);
	
		BASS_Init(-1, 44100, 0, 0, NULL);
	/*printf ("Init load Error code: %d\n", BASS_ErrorGetCode());
	
	printf ("Set_device Error code: %d\n", BASS_ErrorGetCode());
	if (HIWORD(BASS_GetVersion())!=BASSVERSION) {
		printf ("ERROR version BASS.\n");
		return 1;
	}
	printf ("version BASS : %x\n",(unsigned int) BASS_GetVersion());
	*/
	//sam01=BASS_SampleLoad(FALSE, sndrs,0,0,2 , 0);
	/*if (!sam01) {
		printf ("Sample load Error code: %d\n", BASS_ErrorGetCode());
	}*/
	//ch01=BASS_SampleGetChannel(sam01, FALSE );
	/*if (!ch01) {
		printf ("ch01 load Error code: %d\n", BASS_ErrorGetCode());
	}*/
	
		

		//BASS_ChannelPlay(ch01, FALSE);
		w_handle =glfw_window_init(W_WIDTH,W_HEIGHT,W_CAPTION,w_mode) ;
	glfw_window_set_params(w_handle, W_CAPTION, SWAP_INT);
	glew_init();
    ogl_init(W_WIDTH,W_HEIGHT);
    load_textures();
    ogl_print_info(gl_info);
	glfw_print_info(glfw_info);
	glfw_callback_init(w_handle);	
	glfw_main_loop(w_handle);
	return 0;	
}


