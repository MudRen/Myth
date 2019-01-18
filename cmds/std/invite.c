// invite.c
// mon 3/8/97

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *killer, callname, id, *host;

	if( !arg )
		return notify_fail("��������˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("��������˭��\n");

	message_vision("$N��$n˵������ӭ"+RANK_D->query_respect(obj)
               +"�пն����Ҽ�������� \n", me, obj);
        host=obj->query_temp("invited");
        id=me->query("id");
        if(host) {
          if(member_array(id,host)>-1) return 1;
          host=host+({id});
        } else {
          host=({id});
        }
        obj->set_temp("invited",host);

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : invite|yaoqing <����>
 
������˵���������͡�

 
HELP
    );
    return 1;
}
 
