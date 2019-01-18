// help.c

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int found;

int search_dir(string *dirs, string arg, object me, int wildcard, int wizp);
int find_sub(mixed *filename);

int main(object me, string arg)
{
	int i;
	string file, *search;
        string *default_search;
	int wildcard;

	// If no topic specified, give the topics.
	if( !arg ) {
                color_cat(HELP_DIR + "help/topics");
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
                write(HIW"�������񻰡�"HIY"ָ�������\n"NOR);
		return file->help(me);
	}
	//Now see if it aliases to a command.
	//mon 10/27/97
	if( stringp(file =
	  me->find_command(ALIAS_D->process_global_alias(arg))) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
                write(HIW"�������񻰡�"HIY"ָ�������\n"NOR);
                return file->help(me);
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	// Using a "()" after the function name can prevent it being
	// interpreted as a user command with the same name. -- mon
	sscanf(arg, "%s()", arg);
	arg=replace_string(arg, "/", "");

        if(strsrch(arg,"*")>=0 || strsrch(arg,"?")>=0) wildcard=1;
	else wildcard=0;

	found=0;
        write("\n");

	// Finally, search the default search paths.
	// by snowcat feb 21 1998
	if (wizardp(me))
		default_search = DEFAULT_SEARCH_PATHS;
	else
		default_search = DEFAULT_PLAYER_SEARCH_PATHS;
	if( pointerp(default_search) ) {
	  if(search_dir(default_search, arg, me, wildcard, wizardp(me))>0) {
	    if(wildcard) write("�ҵ�"+chinese_number(found)+
	      "��������⡣\n");
	    return 1;
          }
	}

	return notify_fail("û��������������˵���ļ���\n");
}

// recursively search the help dir.
// mon 2/26/98
int search_dir(string *dirs, string arg, object me, int wildcard, int wizp)
{
    int i = sizeof(dirs), j;
    mixed *filenames, *sub_dir;

    while(i--) {
      filenames=get_dir(dirs[i] + arg, -1);

      if(pointerp(filenames) && sizeof(filenames)) {
        if(!wildcard && filenames[0][1]>0) {
	//without wildcard, filenames[0] must be the only match.
	//which should be the same as "dirs[i] + arg"
          me->start_more( color_filter( read_file(dirs[i] + arg)) );
/*
// 87          write(HIY"\t\t\t    ллʹ��"HIW"�������񻰡�"HIY"����ϵͳ\n"NOR);
        write("\n\n\n");
        write(HIW"\t\t\t\t\t  �������񻰡�"HIY"��ʦ��\n"NOR);
*/
	  return 1;
        }

	if(wildcard) {
          j=sizeof(filenames);
	  while(j--) {
            if(filenames[j][1]>0) {
	      write("help "+filenames[j][0]+
	        (wizp?"     ("+dirs[i]+")":"")+ "\n");
	      found++;
            }
	  }
	}
      }

      //check sub_directories
      if(pointerp(filenames=get_dir(dirs[i], -1))) {
        if(pointerp(sub_dir=filter_array(filenames, "find_sub"))) {
	  string *dirs1=({});

          j=sizeof(sub_dir);
	  while(j--) {
	    dirs1+=({dirs[i]+sub_dir[j][0]+"/"}); 
	  }

	  if(search_dir(dirs1, arg, me, wildcard, wizp)==1 
	    && !wildcard) return 1;
        }
      }
    }

    return (wildcard*found);
}

int find_sub(mixed *filename)
{
    return (filename[1]==-2);
}

int help(object me)
{
	write(@HELP
ָ���ʽ��help <����>              ���磺 help cmds
          help <��������>()        ���磺 help call_out()

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���

�����й�ָ����(command)��˵�����⣬������������ Help ֧�� wildcards 
�� '?' �� '*'�����磺 help map-m*��

HELP
	);
	return 1;
}

