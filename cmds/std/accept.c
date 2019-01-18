// accept.c
// created by snowcat on 5/30/1997

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  object obj, env;

  if (!arg)
    return notify_fail("��Ҫ����˭�Ĺ������룿\n");

  if( me->is_ghost() )
    return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");

  if( me->is_fighting() )
    return notify_fail("ս���в��ܽ��ܹ������롣\n");

  if( me->is_busy() )
    return notify_fail("���æ�����ܽ��ܹ������롣\n");

  obj = find_player(arg);
  if (!obj)
    obj = find_living(arg);    
  if (!obj)
    obj = LOGIN_D->find_body(arg);
    if (!obj)
    return notify_fail("û������ˡ�\n");
    // add by mudring@sjsh....
    if( wizardp(obj) ) return notify_fail("û������ˡ�\n");
  if (obj->query_temp("invite") != "public")
    return notify_fail(obj->query("name")+"���ڲ�û�й���������ˡ�\n");

  // mon 4/27/98
  if (env=environment(me))
     if(!env->query("outdoors"))
      return notify_fail("�㻹�ǵ�����ȥ����"+
              obj->query("name")+"������ɣ�\n");

  if (me->query_temp("accept") == obj->query("id"))
    return notify_fail("���Ѿ�����"+obj->query("name")+"�Ĺ��������ˡ�\n");

  tell_object (me,"�����"+obj->query("name")+"�Ĺ������롣\n");
  tell_object (obj, me->query("name")+"���ڽ�����Ĺ������롣\n");
//added by yudian
if ((obj->query("id")=="zhenyuan daxian")
&& ((me->query("combat_exp")<50000)
||(me->query("life/live_forever"))))
return 1;
  me->set_temp("accept",obj->query("id"));
  return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : accept <ĳ��>

���ָ����߱����������/���Ĺ�������.

HELP
    );
    return 1;
}

