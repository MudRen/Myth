//Cracked by Roath
// backup.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;
        string file;
        object* inv;
        int     i, cur_time;

        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");
                
    cur_time = time();
    if( (cur_time-me->query("last_backup")) < 600 )             
                return notify_fail("��ٵ�ſ��Դ��档\n");
        
    me->set("last_backup", cur_time);
    
        if( (int)link_ob->save() && (int)me->save() && (int)me->backup()) {
                // backup for fabao

                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); ++i)  {
                   if( inv[i]->query("owner_id") == getuid(me) && 
                   inv[i]->query("series_no") )   {
                           inv[i]->unequip();
                           if( !(int)inv[i]->backup() )   {
                           write("����ʧ�ܡ�\n");
                   write("����ʧ�ܡ�\n");
                           return 0;
                           }
                   }
                }

        write("����������ϡ�\n");
        write("������ϡ�\n");
                return 1;
        } else {
                write("����ʧ�ܡ�\n");
        write("����ʧ�ܡ�\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ��backup

���ݵ���������ĵ�������Ī��������˺��󣬿�Ҫ����ʦ�ָ���
HELP
        );
        return 1;
}

