<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns='http://www.w3.org/1999/xhtml' xml:lang='en' lang='en'>
<head>
<title>mesa/mesa - The Mesa 3D Graphics Library</title>
<meta name='generator' content='cgit v0.9.0.2-2-gbebe'/>
<meta name='robots' content='index, nofollow'/>
<link rel='stylesheet' type='text/css' href='http://cgit.freedesktop.org/cgit.css'/>
<link rel='alternate' title='Atom feed' href='http://cgit.freedesktop.org/mesa/mesa/atom/include/GL/glx_mangle.h?h=master' type='application/atom+xml'/>
</head>
<body>
<div id='cgit'><table id='header'>
<tr>
<td class='logo' rowspan='2'><a href='/'><img src='http://cgit.freedesktop.org/logo.png' alt='cgit logo'/></a></td>
<td class='main'><a href='/'>index</a> : <a title='mesa/mesa' href='/mesa/mesa/'>mesa/mesa</a></td><td class='form'><form method='get' action=''>
<select name='h' onchange='this.form.submit();'>
<option value='7.10'>7.10</option>
<option value='7.11'>7.11</option>
<option value='7.8'>7.8</option>
<option value='7.8-gles'>7.8-gles</option>
<option value='7.9'>7.9</option>
<option value='8.0'>8.0</option>
<option value='9.0'>9.0</option>
<option value='9.1'>9.1</option>
<option value='9.2'>9.2</option>
<option value='965-glsl'>965-glsl</option>
<option value='965-ttm'>965-ttm</option>
<option value='R300_DRIVER'>R300_DRIVER</option>
<option value='arb_copy_buffer'>arb_copy_buffer</option>
<option value='arb_fbo'>arb_fbo</option>
<option value='arb_fbo_cleanup'>arb_fbo_cleanup</option>
<option value='arb_fbo_indirect'>arb_fbo_indirect</option>
<option value='arb_geometry_shader4'>arb_geometry_shader4</option>
<option value='arb_half_float_vertex'>arb_half_float_vertex</option>
<option value='arb_map_buffer_range'>arb_map_buffer_range</option>
<option value='arb_robustness'>arb_robustness</option>
<option value='arb_sampler_objects'>arb_sampler_objects</option>
<option value='arb_sync'>arb_sync</option>
<option value='arb_vertex_array_object'>arb_vertex_array_object</option>
<option value='asm-shader-rework-1'>asm-shader-rework-1</option>
<option value='asm-shader-rework-2'>asm-shader-rework-2</option>
<option value='asm-shader-rework-3'>asm-shader-rework-3</option>
<option value='auto-cherry-for-8.0'>auto-cherry-for-8.0</option>
<option value='autoconf'>autoconf</option>
<option value='cxx-1-branch'>cxx-1-branch</option>
<option value='d3d1x-addons'>d3d1x-addons</option>
<option value='draw-instanced'>draw-instanced</option>
<option value='draw-ply'>draw-ply</option>
<option value='dri2-swapbuffers'>dri2-swapbuffers</option>
<option value='drm-gem'>drm-gem</option>
<option value='embedded-1-branch'>embedded-1-branch</option>
<option value='embedded-2-branch'>embedded-2-branch</option>
<option value='experimental-1'>experimental-1</option>
<option value='ext-provoking-vertex'>ext-provoking-vertex</option>
<option value='flex-and-bison-required'>flex-and-bison-required</option>
<option value='floating'>floating</option>
<option value='frontbuffer-removal'>frontbuffer-removal</option>
<option value='gallium-0.1'>gallium-0.1</option>
<option value='gallium-0.1-dri'>gallium-0.1-dri</option>
<option value='gallium-0.1-dri2'>gallium-0.1-dri2</option>
<option value='gallium-0.2'>gallium-0.2</option>
<option value='gallium-array-textures'>gallium-array-textures</option>
<option value='gallium-buffer-usage-cleanup'>gallium-buffer-usage-cleanup</option>
<option value='gallium-clip-state'>gallium-clip-state</option>
<option value='gallium-compute'>gallium-compute</option>
<option value='gallium-context-transfers-2'>gallium-context-transfers-2</option>
<option value='gallium-cylindrical-wrap'>gallium-cylindrical-wrap</option>
<option value='gallium-double-opcodes'>gallium-double-opcodes</option>
<option value='gallium-drm-driver-descriptor'>gallium-drm-driver-descriptor</option>
<option value='gallium-dynamicstencilref'>gallium-dynamicstencilref</option>
<option value='gallium-fb-dimensions'>gallium-fb-dimensions</option>
<option value='gallium-float-1111-format'>gallium-float-1111-format</option>
<option value='gallium-format-cleanup'>gallium-format-cleanup</option>
<option value='gallium-front-ccw'>gallium-front-ccw</option>
<option value='gallium-gpu4-texture-opcodes'>gallium-gpu4-texture-opcodes</option>
<option value='gallium-integer-opcodes'>gallium-integer-opcodes</option>
<option value='gallium-llvmpipe'>gallium-llvmpipe</option>
<option value='gallium-mesa-7.4'>gallium-mesa-7.4</option>
<option value='gallium-msaa'>gallium-msaa</option>
<option value='gallium-new-formats'>gallium-new-formats</option>
<option value='gallium-newclear'>gallium-newclear</option>
<option value='gallium-no-nvidia-opcodes'>gallium-no-nvidia-opcodes</option>
<option value='gallium-no-rhw-position'>gallium-no-rhw-position</option>
<option value='gallium-no-texture-blanket'>gallium-no-texture-blanket</option>
<option value='gallium-nopointsizeminmax'>gallium-nopointsizeminmax</option>
<option value='gallium-render-condition-predicate'>gallium-render-condition-predicate</option>
<option value='gallium-resource-sampling'>gallium-resource-sampling</option>
<option value='gallium-resources'>gallium-resources</option>
<option value='gallium-sampler-view'>gallium-sampler-view</option>
<option value='gallium-softpipe-winsys'>gallium-softpipe-winsys</option>
<option value='gallium-st-api'>gallium-st-api</option>
<option value='gallium-st-api-dri'>gallium-st-api-dri</option>
<option value='gallium-stream-out'>gallium-stream-out</option>
<option value='gallium-sw-api'>gallium-sw-api</option>
<option value='gallium-tgsi-semantic-cleanup'>gallium-tgsi-semantic-cleanup</option>
<option value='gallium-userbuf'>gallium-userbuf</option>
<option value='gallium-util-format-is-supported'>gallium-util-format-is-supported</option>
<option value='gallium-vertexelementcso'>gallium-vertexelementcso</option>
<option value='gallium_draw_llvm'>gallium_draw_llvm</option>
<option value='gallivm-call'>gallivm-call</option>
<option value='glapi-reorg'>glapi-reorg</option>
<option value='gles3'>gles3</option>
<option value='glsl-compiler-1'>glsl-compiler-1</option>
<option value='glsl-continue-return'>glsl-continue-return</option>
<option value='glsl-continue-return-7-5'>glsl-continue-return-7-5</option>
<option value='glsl-pp-rework-1'>glsl-pp-rework-1</option>
<option value='glsl-pp-rework-2'>glsl-pp-rework-2</option>
<option value='glsl-to-tgsi'>glsl-to-tgsi</option>
<option value='glsl2'>glsl2</option>
<option value='glsl2-llvm'>glsl2-llvm</option>
<option value='glsl2-lower-variable-indexing'>glsl2-lower-variable-indexing</option>
<option value='graw-tests'>graw-tests</option>
<option value='hw_gl_select'>hw_gl_select</option>
<option value='i915tex-pageflip'>i915tex-pageflip</option>
<option value='i915tex-zone-rendering'>i915tex-zone-rendering</option>
<option value='i915tex_branch'>i915tex_branch</option>
<option value='i915tex_privbuffers'>i915tex_privbuffers</option>
<option value='index-swtnl-0.1'>index-swtnl-0.1</option>
<option value='indirect-vbo'>indirect-vbo</option>
<option value='intel-2008-q3'>intel-2008-q3</option>
<option value='intel-2008-q4'>intel-2008-q4</option>
<option value='kasanen-post-process'>kasanen-post-process</option>
<option value='kasanen-post-process-v2'>kasanen-post-process-v2</option>
<option value='llvm-cliptest-viewport'>llvm-cliptest-viewport</option>
<option value='llvm-context'>llvm-context</option>
<option value='llvmpipe-duma'>llvmpipe-duma</option>
<option value='llvmpipe-wider-regs'>llvmpipe-wider-regs</option>
<option value='lp-line-rast'>lp-line-rast</option>
<option value='lp-offset-twoside'>lp-offset-twoside</option>
<option value='lp-setup-llvm'>lp-setup-llvm</option>
<option value='lp-surface-tiling'>lp-surface-tiling</option>
<option value='map-tex-branch'>map-tex-branch</option>
<option value='map-texture-image-v4'>map-texture-image-v4</option>
<option value='map-texture-image-v5'>map-texture-image-v5</option>
<option value='master' selected='selected'>master</option>
<option value='mesa'>mesa</option>
<option value='mesa_20040127_branch'>mesa_20040127_branch</option>
<option value='mesa_20040309_branch'>mesa_20040309_branch</option>
<option value='mesa_20050114_branch'>mesa_20050114_branch</option>
<option value='mesa_3_2_dev'>mesa_3_2_dev</option>
<option value='mesa_3_3_texture_env_combine2'>mesa_3_3_texture_env_combine2</option>
<option value='mesa_3_4_branch'>mesa_3_4_branch</option>
<option value='mesa_4_0_branch'>mesa_4_0_branch</option>
<option value='mesa_5_0_branch'>mesa_5_0_branch</option>
<option value='mesa_6_0_branch'>mesa_6_0_branch</option>
<option value='mesa_6_2_branch'>mesa_6_2_branch</option>
<option value='mesa_6_4_branch'>mesa_6_4_branch</option>
<option value='mesa_7_0_branch'>mesa_7_0_branch</option>
<option value='mesa_7_2_branch'>mesa_7_2_branch</option>
<option value='mesa_7_4_branch'>mesa_7_4_branch</option>
<option value='mesa_7_4_idr_staging'>mesa_7_4_idr_staging</option>
<option value='mesa_7_5_branch'>mesa_7_5_branch</option>
<option value='mesa_7_6_branch'>mesa_7_6_branch</option>
<option value='mesa_7_7_branch'>mesa_7_7_branch</option>
<option value='nv50-compiler'>nv50-compiler</option>
<option value='nvc0'>nvc0</option>
<option value='openchrome-branch'>openchrome-branch</option>
<option value='opengl-es'>opengl-es</option>
<option value='opengl-es-v2'>opengl-es-v2</option>
<option value='openvg-1.0'>openvg-1.0</option>
<option value='outputswritten64'>outputswritten64</option>
<option value='pipe-video'>pipe-video</option>
<option value='primitive-restart'>primitive-restart</option>
<option value='r300-bufmgr'>r300-bufmgr</option>
<option value='r500-support'>r500-support</option>
<option value='r6xx-r7xx-support'>r6xx-r7xx-support</option>
<option value='r6xx-rewrite'>r6xx-rewrite</option>
<option value='radeon-rewrite'>radeon-rewrite</option>
<option value='remove-copyteximage-hook'>remove-copyteximage-hook</option>
<option value='remove-driver-date'>remove-driver-date</option>
<option value='remove-max-width'>remove-max-width</option>
<option value='remove-max-width-2'>remove-max-width-2</option>
<option value='remove-redundant-helpers'>remove-redundant-helpers</option>
<option value='renderbuffer-cleanups-v2'>renderbuffer-cleanups-v2</option>
<option value='shader-file-reorg'>shader-file-reorg</option>
<option value='shader-work'>shader-work</option>
<option value='softpipe_0_1_branch'>softpipe_0_1_branch</option>
<option value='sprite-coord'>sprite-coord</option>
<option value='st-mesa-per-context-shaders'>st-mesa-per-context-shaders</option>
<option value='st-vbo'>st-vbo</option>
<option value='texfilter_float_branch'>texfilter_float_branch</option>
<option value='texformat-xrgb'>texformat-xrgb</option>
<option value='texman_0_1_branch'>texman_0_1_branch</option>
<option value='texmem-1.0'>texmem-1.0</option>
<option value='texmem_0_2_branch'>texmem_0_2_branch</option>
<option value='texmem_0_3_branch'>texmem_0_3_branch</option>
<option value='texture_rg'>texture_rg</option>
<option value='texture_rg-2'>texture_rg-2</option>
<option value='thalloc'>thalloc</option>
<option value='vbo_0_1_branch'>vbo_0_1_branch</option>
<option value='vtx-0-1-branch'>vtx-0-1-branch</option>
<option value='vtx-0-2-branch'>vtx-0-2-branch</option>
<option value='xa_branch'>xa_branch</option>
</select> <input type='submit' name='' value='switch'/></form></td></tr>
<tr><td class='sub'>The Mesa 3D Graphics Library</td><td class='sub right'>brianp</td></tr></table>
<table class='tabs'><tr><td>
<a href='/mesa/mesa/'>summary</a><a href='/mesa/mesa/refs/'>refs</a><a href='/mesa/mesa/log/include/GL/glx_mangle.h'>log</a><a class='active' href='/mesa/mesa/tree/include/GL/glx_mangle.h'>tree</a><a href='/mesa/mesa/commit/include/GL/glx_mangle.h'>commit</a><a href='/mesa/mesa/diff/include/GL/glx_mangle.h'>diff</a></td><td class='form'><form class='right' method='get' action='/mesa/mesa/log/include/GL/glx_mangle.h'>
<select name='qt'>
<option value='grep'>log msg</option>
<option value='author'>author</option>
<option value='committer'>committer</option>
<option value='range'>range</option>
</select>
<input class='txt' type='text' size='10' name='q' value=''/>
<input type='submit' value='search'/>
</form>
</td></tr></table>
<div class='path'>path: <a href='/mesa/mesa/tree/'>root</a>/<a href='/mesa/mesa/tree/include'>include</a>/<a href='/mesa/mesa/tree/include/GL'>GL</a>/<a href='/mesa/mesa/tree/include/GL/glx_mangle.h'>glx_mangle.h</a></div><div class='content'>blob: fad6c6a4764198215e21f84bef0e788bcde0fd90 (<a href='/mesa/mesa/plain/include/GL/glx_mangle.h'>plain</a>)
<table summary='blob content' class='blob'>
<tr><td class='linenumbers'><pre><a class='no' id='n1' name='n1' href='#n1'>1</a>
<a class='no' id='n2' name='n2' href='#n2'>2</a>
<a class='no' id='n3' name='n3' href='#n3'>3</a>
<a class='no' id='n4' name='n4' href='#n4'>4</a>
<a class='no' id='n5' name='n5' href='#n5'>5</a>
<a class='no' id='n6' name='n6' href='#n6'>6</a>
<a class='no' id='n7' name='n7' href='#n7'>7</a>
<a class='no' id='n8' name='n8' href='#n8'>8</a>
<a class='no' id='n9' name='n9' href='#n9'>9</a>
<a class='no' id='n10' name='n10' href='#n10'>10</a>
<a class='no' id='n11' name='n11' href='#n11'>11</a>
<a class='no' id='n12' name='n12' href='#n12'>12</a>
<a class='no' id='n13' name='n13' href='#n13'>13</a>
<a class='no' id='n14' name='n14' href='#n14'>14</a>
<a class='no' id='n15' name='n15' href='#n15'>15</a>
<a class='no' id='n16' name='n16' href='#n16'>16</a>
<a class='no' id='n17' name='n17' href='#n17'>17</a>
<a class='no' id='n18' name='n18' href='#n18'>18</a>
<a class='no' id='n19' name='n19' href='#n19'>19</a>
<a class='no' id='n20' name='n20' href='#n20'>20</a>
<a class='no' id='n21' name='n21' href='#n21'>21</a>
<a class='no' id='n22' name='n22' href='#n22'>22</a>
<a class='no' id='n23' name='n23' href='#n23'>23</a>
<a class='no' id='n24' name='n24' href='#n24'>24</a>
<a class='no' id='n25' name='n25' href='#n25'>25</a>
<a class='no' id='n26' name='n26' href='#n26'>26</a>
<a class='no' id='n27' name='n27' href='#n27'>27</a>
<a class='no' id='n28' name='n28' href='#n28'>28</a>
<a class='no' id='n29' name='n29' href='#n29'>29</a>
<a class='no' id='n30' name='n30' href='#n30'>30</a>
<a class='no' id='n31' name='n31' href='#n31'>31</a>
<a class='no' id='n32' name='n32' href='#n32'>32</a>
<a class='no' id='n33' name='n33' href='#n33'>33</a>
<a class='no' id='n34' name='n34' href='#n34'>34</a>
<a class='no' id='n35' name='n35' href='#n35'>35</a>
<a class='no' id='n36' name='n36' href='#n36'>36</a>
<a class='no' id='n37' name='n37' href='#n37'>37</a>
<a class='no' id='n38' name='n38' href='#n38'>38</a>
<a class='no' id='n39' name='n39' href='#n39'>39</a>
<a class='no' id='n40' name='n40' href='#n40'>40</a>
<a class='no' id='n41' name='n41' href='#n41'>41</a>
<a class='no' id='n42' name='n42' href='#n42'>42</a>
<a class='no' id='n43' name='n43' href='#n43'>43</a>
<a class='no' id='n44' name='n44' href='#n44'>44</a>
<a class='no' id='n45' name='n45' href='#n45'>45</a>
<a class='no' id='n46' name='n46' href='#n46'>46</a>
<a class='no' id='n47' name='n47' href='#n47'>47</a>
<a class='no' id='n48' name='n48' href='#n48'>48</a>
<a class='no' id='n49' name='n49' href='#n49'>49</a>
<a class='no' id='n50' name='n50' href='#n50'>50</a>
<a class='no' id='n51' name='n51' href='#n51'>51</a>
<a class='no' id='n52' name='n52' href='#n52'>52</a>
<a class='no' id='n53' name='n53' href='#n53'>53</a>
<a class='no' id='n54' name='n54' href='#n54'>54</a>
<a class='no' id='n55' name='n55' href='#n55'>55</a>
<a class='no' id='n56' name='n56' href='#n56'>56</a>
<a class='no' id='n57' name='n57' href='#n57'>57</a>
<a class='no' id='n58' name='n58' href='#n58'>58</a>
<a class='no' id='n59' name='n59' href='#n59'>59</a>
<a class='no' id='n60' name='n60' href='#n60'>60</a>
<a class='no' id='n61' name='n61' href='#n61'>61</a>
<a class='no' id='n62' name='n62' href='#n62'>62</a>
<a class='no' id='n63' name='n63' href='#n63'>63</a>
<a class='no' id='n64' name='n64' href='#n64'>64</a>
<a class='no' id='n65' name='n65' href='#n65'>65</a>
<a class='no' id='n66' name='n66' href='#n66'>66</a>
<a class='no' id='n67' name='n67' href='#n67'>67</a>
<a class='no' id='n68' name='n68' href='#n68'>68</a>
<a class='no' id='n69' name='n69' href='#n69'>69</a>
<a class='no' id='n70' name='n70' href='#n70'>70</a>
<a class='no' id='n71' name='n71' href='#n71'>71</a>
<a class='no' id='n72' name='n72' href='#n72'>72</a>
<a class='no' id='n73' name='n73' href='#n73'>73</a>
<a class='no' id='n74' name='n74' href='#n74'>74</a>
<a class='no' id='n75' name='n75' href='#n75'>75</a>
<a class='no' id='n76' name='n76' href='#n76'>76</a>
<a class='no' id='n77' name='n77' href='#n77'>77</a>
<a class='no' id='n78' name='n78' href='#n78'>78</a>
<a class='no' id='n79' name='n79' href='#n79'>79</a>
<a class='no' id='n80' name='n80' href='#n80'>80</a>
<a class='no' id='n81' name='n81' href='#n81'>81</a>
<a class='no' id='n82' name='n82' href='#n82'>82</a>
</pre></td>
<td class='lines'><pre><code>/*
 * Mesa 3-D graphics library
 * 
 * Copyright (C) 1999-2006  Brian Paul   All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef GLX_MANGLE_H
#define GLX_MANGLE_H

#define glXChooseVisual mglXChooseVisual
#define glXCreateContext mglXCreateContext
#define glXDestroyContext mglXDestroyContext
#define glXMakeCurrent mglXMakeCurrent
#define glXCopyContext mglXCopyContext
#define glXSwapBuffers mglXSwapBuffers
#define glXCreateGLXPixmap mglXCreateGLXPixmap
#define glXDestroyGLXPixmap mglXDestroyGLXPixmap
#define glXQueryExtension mglXQueryExtension
#define glXQueryVersion mglXQueryVersion
#define glXIsDirect mglXIsDirect
#define glXGetConfig mglXGetConfig
#define glXGetCurrentContext mglXGetCurrentContext
#define glXGetCurrentDrawable mglXGetCurrentDrawable
#define glXWaitGL mglXWaitGL
#define glXWaitX mglXWaitX
#define glXUseXFont mglXUseXFont
#define glXQueryExtensionsString mglXQueryExtensionsString
#define glXQueryServerString mglXQueryServerString
#define glXGetClientString mglXGetClientString
#define glXCreateGLXPixmapMESA mglXCreateGLXPixmapMESA
#define glXReleaseBuffersMESA mglXReleaseBuffersMESA
#define glXCopySubBufferMESA mglXCopySubBufferMESA
#define glXGetVideoSyncSGI mglXGetVideoSyncSGI
#define glXWaitVideoSyncSGI mglXWaitVideoSyncSGI

/* GLX 1.2 */
#define glXGetCurrentDisplay mglXGetCurrentDisplay 

/* GLX 1.3 */
#define glXChooseFBConfig mglXChooseFBConfig          
#define glXGetFBConfigAttrib mglXGetFBConfigAttrib       
#define glXGetFBConfigs mglXGetFBConfigs            
#define glXGetVisualFromFBConfig mglXGetVisualFromFBConfig   
#define glXCreateWindow mglXCreateWindow            
#define glXDestroyWindow mglXDestroyWindow           
#define glXCreatePixmap mglXCreatePixmap            
#define glXDestroyPixmap mglXDestroyPixmap           
#define glXCreatePbuffer mglXCreatePbuffer           
#define glXDestroyPbuffer mglXDestroyPbuffer          
#define glXQueryDrawable mglXQueryDrawable           
#define glXCreateNewContext mglXCreateNewContext        
#define glXMakeContextCurrent mglXMakeContextCurrent      
#define glXGetCurrentReadDrawable mglXGetCurrentReadDrawable  
#define glXQueryContext mglXQueryContext            
#define glXSelectEvent mglXSelectEvent             
#define glXGetSelectedEvent mglXGetSelectedEvent    

/* GLX 1.4 */
#define glXGetProcAddress mglXGetProcAddress
#define glXGetProcAddressARB mglXGetProcAddressARB


#endif
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated  by cgit v0.9.0.2-2-gbebe at 2013-07-30 08:31:42 (GMT)</div>
</div> <!-- id=cgit -->
</body>
</html>
