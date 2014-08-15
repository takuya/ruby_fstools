#include <ruby.h>

/*
 *   
 *   This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 

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
