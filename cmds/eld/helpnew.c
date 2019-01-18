// help.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;
void selete_main(string num,object ob);
void help_new(string num,object ob);
void help_1(string num,object ob);
void help_2(string num,object ob);
void help_3(string num,object ob);
void help_4(string num,object ob);
void help_5(string num,object ob);
void help_6(string num,object ob);
void help_7(string num,object ob);
void quit_help(object ob);

int main(object me, string arg)
{
	int i;
	string file, *search;
	object ob;
	ob = this_player();

	if( !arg ) {
		write(CLR);
		cat("/doc/newhelp/topics2");
		input_to("help_new", ob);
		ob->set_temp("block_msg/all",1);
		return 1;
	}
	else if ( arg=="-old" )
	{
		cat("/doc/topics1");
		return 1;
	}
	else if ( arg=="-new" )
	{
		write(CLR);
		cat("/doc/newhelp/topics2");
		ob->set_temp("block_msg/all");
		input_to("help_new",ob);
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
		return file->help(me);
	}

	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);

	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
	}

	return notify_fail("û��������������˵���ļ���\n");
}

void selete_main(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" )
	{
		write(CLR);
		cat("/doc/newhelp/topics1");
	}
	else if( num == "2" )
	{
		write(CLR);
		cat("/doc/newhelp/topics2");
		ob->set_temp("block_msg/all");
		input_to("help_new",ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�������ѡ��\n"NOR);
		write(YEL" ��"CYN"����ѡģʽĿ¼����"YEL"��"CYN"����ģʽĿ¼����"YEL"��"CYN"���˳�����\n"NOR);
		write(CYN"\n ������ѡ���1 or 2 or Q����"NOR);
		ob->set_temp("block_msg/all");
		input_to("selete_main", ob);
	}
}

void help_new(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" ||num == "3" ||num == "4" 
	  ||num == "5" ||num == "6" ||num == "7" )
	{
		write(CLR);
		cat("/doc/newhelp/"+num);
		input_to("help_"+num,ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
		write(CYN"\n ������ѡ����("YEL"1-7"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_new", ob);
	}
}

void help_1(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" )
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/1_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
		write(CYN"\n ������ѡ����("YEL"1-2"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}

void help_2(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" ||num == "3" ||num == "4" )
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/2_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
		write(CYN"\n ������ѡ����("YEL"1-4"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}

void help_3(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" ||num == "3" ||num == "4" 
	  ||num == "5" ||num == "6" ||num == "7" ||num == "8" 
          ||num == "9" ||num == "10" ||num== "11" ||num=="12")
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/3_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
                write(CYN"\n ������ѡ����("YEL"1-12"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}



void help_4(string num,object ob)
{
	ob->delete_temp("block_msg/all");

    if( num == "1" ||num == "2" ||num == "3" ||num == "4"||num == "5"||num=="6"||num == "7" ||num == "8" ||num == "9"||num == "10"||num=="11")
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/4_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
        write(CYN"\n ������ѡ����("YEL"1-6"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}

void help_5(string num,object ob)
{
	ob->delete_temp("block_msg/all");
	write(CLR);
//	ob->start_more( read_file("/doc/newhelp/5"));
	quit_help(ob);
	
}

void help_6(string num,object ob)
{
	ob->delete_temp("block_msg/all");

    if( num == "1" ||num=="2"||num=="3"||num=="4"||num=="5"||num=="6"||num=="7"||num=="8"||num=="9"||num=="10"||num=="11"||num=="12"||num=="13"||num=="14")
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/6_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
        write(CYN"\n ������ѡ����("YEL"1-2"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}

void help_7(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" ||num == "3" ||num == "4" 
          ||num == "5" ||num == "6" || num=="7" || num== "8"||num=="9")
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/7_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
               write(CYN"\n ��ѡ����Ҫ���ĵĵ�ͼ���("YEL"1-9"CYN"ѡ���ͼ��"YEL"Q"CYN"�˳�)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_map", ob);
	}
}
/*
void help_8(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" ||num == "3" ||num == "4" 
	  ||num == "5" ||num == "6" ||num == "7")
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/8_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
		write(CYN"\n ������ѡ����("YEL"1-7"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}

void help_9(string num,object ob)
{
	ob->delete_temp("block_msg/all");

	if( num == "1" ||num == "2" )
	{
		write(CLR);
		ob->start_more( read_file("/doc/newhelp/9_"+num));
		quit_help(ob);
	}
	else if( num == "q" || num == "Q" ) quit_help(ob);
	else
	{
		write(HIR"\n �Բ���û�����ѡ�\n"NOR);
		write(CYN"\n ������ѡ����("YEL"1-2"CYN"ѡ����Ӧ��Ŀ��"YEL"Q"CYN"�˳�����ϵͳ)��"NOR);
		ob->set_temp("block_msg/all");
		input_to("help_"+num, ob);
	}
}
*/
void quit_help(object ob)
{
	ob->delete_temp("block_msg/all");
	write(HIC"\n ллʹ�ð���ϵͳ��ף����������Ե����������֣�\n\n"NOR);
	return;
}	

int help(object me)
{
	write(@HELP
ָ���ʽ��help			   ������������
	��help -old		   ������ͳ����ģʽĿ¼
	��help -new		   ������ģʽĿ¼
	  help <����>              ֱ���Ķ�ָ������
          help <��������>        ��ֱ���Ķ�ָ������İ���

���ָ���ṩ����Ϸ��������Ҫ�İ�����
HELP
	);
	return 1;
}
