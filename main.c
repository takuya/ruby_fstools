#include <ruby.h>


int copyFileBySystem();

VALUE wrap_copy_file_by_sysmtem(self,src,dst)
	VALUE self,src,dst;
{

	char *p_src;
	char *p_dst;

	p_src = RSTRING_PTR(src);
	p_dst = RSTRING_PTR(dst);

	int ret = copyFileBySystem(p_src,p_dst);

	if(ret ==0 ){
	   return Qtrue;
	}else{
	   return Qfalse;
	}


}

void Init_fstools(){

	rb_cFile = rb_define_class("File",rb_cIO);
    rb_define_singleton_method(rb_cFile, "cp", wrap_copy_file_by_sysmtem, 2);
    rb_define_singleton_method(rb_cFile, "copy", wrap_copy_file_by_sysmtem, 2);

}
