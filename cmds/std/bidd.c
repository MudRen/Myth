#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object room,obj;
        int argg;

        seteuid( geteuid(me) );
      if(userp(me))
                return notify_fail("��ʱ����ʹ��\n");

        if( me->is_busy() ) return notify_fail("������û�пգ�\n");

        if( !arg )
                return notify_fail("ָ���ʽ��bid <����>\n");

        sscanf(arg,"%d",argg);
//����ʦ���õ�·��
        if( !(room=find_object("/d/city/paimaixing")) )
                room= clone_object("/d/city/paimaixing");
        
        if( !(obj=present("paimai shi",room)) )
        {
                obj=new("/d/city/npc/paimaishi");
                obj->move("/d/city/paimaixing");

                return notify_fail("����ʦ�����������У���û����������\n");
        }

        else
        {
                if( !(obj->query("on_paimai")) ) 
                        return notify_fail("����û����������\n");
        }

//      if( me->query("id") == obj->query("forbid") )
//              return notify_fail("�����ڱ���ֹ���뾺�ġ�\n");
        
        if( argg <= obj->query("value")*21/20 )
        {
                tell_object(me,"�����̫�͡�\n");
                return notify_fail("������"+chinese_number(obj->query("value"))+"�����ӣ�\n");
        }
        if( argg > 5000000 )
                 	return notify_fail("�����̫���ˣ��ٺ٣�\n");
        	
        if( argg > me->query("balance")/120 )
                return notify_fail("��û����ô��Ĵ�\n");

        obj->report_paimai(me,argg,obj->query("number"));
        tell_object(me,"�����"+chinese_number(argg)+"�����ӣ�\n");

        me->start_busy(2);

        return 1;

}

int help(object me)
{
   write( @HELP
ָ���ʽ: bid <����> 

��һָ��������Բ�������Ͷ�꣬��λΪ �����ӡ�
HELP
   );
   return 1;
}
