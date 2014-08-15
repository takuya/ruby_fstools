#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#if defined(__APPLE__) || defined(__FreeBSD__)
#include <copyfile.h>
#else
#include <sys/sendfile.h>
#endif


/**
 * 指定したファイルコピーする
 *
 * 参考資料 
 *  http://stackoverflow.com/questions/2180079/how-can-i-copy-a-file-on-unix-using-c
 */

int copyFileBySystem( char *src, char *dst ){
	struct stat st;
	int ret;
	int i_fd = open(src, O_RDONLY );
	if( i_fd < 0  ){
		return -1;
	}
	fstat( i_fd, &st );

	//printf("%d", st.st_mode);

	int o_fd = open(dst, O_WRONLY|O_CREAT, st.st_mode );
	if( o_fd < 0  ){
		close( i_fd  );
	 	return -1;
	}

#if defined(__APPLE__) || defined(__FreeBSD__)
    copyfile_state_t cst  = copyfile_state_alloc();
    ret = fcopyfile(i_fd, o_fd, cst , COPYFILE_ALL );
#else
    off_t len = 0;
    ret = sendfile(o_fd, i_fd, &len, st.st_size);
#endif

    close(i_fd);
    close(o_fd);

    return ret;
}
//int main (void){
//
//	char *src = "/Users/takuya/Desktop/src.png";
//	char *dst = "/Users/takuya/Desktop/dst.png";
//
//	int res = copyFileBySystem(src,dst);
//	
//}
