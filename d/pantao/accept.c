// accept.c
// created by snowcat on 5/30/1997

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  object obj;

  if (!arg)
    return notify_fail("��Ҫ����˭�Ĺ������룿\n");

  obj = find_player(arg);
  if (!obj)
    obj = find_living(arg);    
  if (!obj)
    obj = LOGIN_D->find_body(arg);
  if (!obj)
    return notify_fail("û������ˡ�\n");

  if (obj->query_temp("invite") != "public")
    return notify_fail(obj->query("name")+"���ڲ�û�й���������ˡ�\n");

  tell_object (me,"�����"+obj->query("name")+"�Ĺ������롣\n");
  tell_object (obj, me->query("name")+"���ڽ�����Ĺ������롣\n");
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

