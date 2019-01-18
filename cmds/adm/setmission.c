//***************************************
//MUDLIB��Biographies         ����մ���   
//VERSION��Test 1.6.28   
//ENCODING��GB  
//Created Admin��By Waiwai           
//Admin Email��wkzstory@21cn.com         
//***************************************
//CMDS ADM setmission.c
// Last modified by zeus@����Ц Dec.30 1999
//Last modified by waiwai@2001/06/05

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
        int i, flag = 0;
        object ob;
        string mission, wname, wmin, file;
        string *wmission;

//    if( me->query("id") != "waiwai")
//         return notify_fail(CYN"��û��Ȩ��ʹ�����ָ�\n"NOR); //By waiwai@2001/06/05

        if( me!=this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s %s", arg, mission)!=2 )
                return notify_fail("ָ���ʽ��setmission <ʹ����> (Ŀǰ��������)\n");

        if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
                return notify_fail(WHT"��ֻ�ܸı䵱ǰ����ʹ���ߵ�����\n"NOR);

//        if( jobhood(arg)=="none" )
//                return notify_fail(WHT"��ֻ�ܸı䵱ǰ������ȼ���ʦ�Ĺ�������\n"NOR);

                mission = COLOR_D->replace_color( mission, 1);
        wmission = explode(read_file("/adm/etc/wizmission"), "\n");
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
                if( wname==ob->query("id") ) {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
                        flag = 1;
                        break;
                }
        }
        for( file = "", i=0; i<sizeof(wmission); i++) file += wmission[i] + "\n";
        if(!flag) write_file("/adm/etc/wizmission", ob->query("id") + " " + mission + "\n", 0);
        else      write_file("/adm/etc/wizmission", file, 1);
        message_vision(WHT"$N��$n�Ĺ�����������Ϊ��" NOR+ mission + "  \n"NOR, me, ob);
       //By waiwai@2001/06/05 ���Ӽ���Լ�log.
       CHANNEL_D->do_channel(me, "adm","��"+ob->name()+"("+ob->query("id")+")""�Ĺ�����������Ϊ��"NOR+mission+"\n"NOR);  
        log_file( "static/setmission", me->query("name")+"("+me->query("id")+")��" +
                ob->query("name") + "(" + ob->query("id") + ")�Ĺ�����������Ϊ��" + mission + " ʱ���ڣ�("+ COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()) )) + ") \n" );

        return 1;
}
        
int help(object me)
{
        write(@HELP

ָ���ʽ : setmission <ĳ��> (Ŀǰ��������)

�����ı���ʦ��ǰ���������˵�������� wizlist ʹ�á�

HELP
        );
        return 1;
}

