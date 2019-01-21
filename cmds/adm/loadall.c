
inherit F_CLEAN_UP;
int help(object me);
int loadall(string dir );

int main(object me, string dir)
{
	if(!dir) dir="/";
	if(dir[<1]!='/') dir+="/";
	if(file_size(dir)!=-2)
		return notify_fail(dir+"not exist��\n");
	log_file("loadall", "\n#check dir :" + dir );
	write("check dir "+dir+"\n" );
	if(loadall(dir))
    return 1;
}

int loadall(string dir )
{
	  string file,err,*dirs;

    if(!arrayp(get_dir(dir)))
		return 1;
	  dirs=get_dir(dir);
	  if(dir=="/")
	    dirs = dirs-({".git", "backup", "bin", "binaries", "cygdrive", "data", "dev", "doc", "dump", "grant", "help", "log", "proc", "temp", "u", "version"});

	foreach(file in dirs)
	{
		if( member_array(file,({"simul_efun","event"})) > -1 )
		continue;

		reset_eval_cost();
		switch(file_size(dir+file))
		{
			case -1:
				//�޷���ȡ��Ŀ¼������
				break;
			case -2:
				if(file!="."&&file!="..")
					call_out("loadall",1,dir+file+"/");
				break;
			default:

				if((dir+file)[<2..<1]==".c")
				{
					if(err=catch( load_object(dir+file) ))
						log_file("loadall", "\n	check :"+dir+file+"\n"+ err );

				}
		}
	}
	write("check dir "+dir+" is ok ^_^\n\n");
	return 1;
}
int help (object me)
{
        write(@HELP
    ����ĳ��Ŀ¼�µ�����.c�ļ�(������Ŀ¼)���Բ�������
���ܵı������

ָ���ʽ�� loadall [dir]
����      loadall /d/city/
û�� dir����dirĬ��Ϊ / ���ļ�̫����ܻῨһ�ᡣ

HELP
        );
        return 1;
}
