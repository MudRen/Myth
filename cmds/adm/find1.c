//#pragma save_binary
// ls.c
#include <ansi.h>

string find_in_file(string file,string arg);
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int mark_loaded;
        int i, j, w, col;
        string dir;
        mixed *file;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        seteuid(getuid());
        if(!arg||arg=="") return notify_fail("��ʲô?\n");
        dir = resolve_path(me->query("cwd"));
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
                else
                return notify_fail("û�����Ŀ¼��\n");
        }

        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        write("Ŀ¼��" + dir + "\n");
        if (sizeof(file))
                for(i=0, j = sizeof(file); i<j; i++)
                {
                        if( file[i][0][0..0] == "." ) continue;
                        col=sizeof(file[i][0]);
                        if(file[i][1]>0)
            printf(find_in_file(dir+file[i][0],arg));
                }
        else write("    û���κε�����\n");
        write("\n");
        
        return 1;       
}

string find_in_file(string file,string arg)
{

        string str;
        int i,j,k;

                if(!stringp(str=read_file(file,0))) 
            return "";
                if(strsrch(str,arg)>0)
                       return "�ļ�"+file+"���ҵ�"+arg+"\n";
            return "";
}


int help(object me)
{
        write(@HELP
ָ���ʽ: find <����>
 
�ڵ�ǰĿ¼���Һ�ָ�����ݵ��ļ� 
����:
'find read_file' ���г�������read_file���ļ�.
 
HELP
        );
        return 1;
}

