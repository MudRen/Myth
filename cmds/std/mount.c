// by snowcat feb 4 1998

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object who, string arg)
{
  object me;
  object where = environment(who);
  object rider;
  object ridee;

  if (! arg ||
      ! where ||
      ! (me = present(arg,where)) ||
      ! me->query("ride/msg"))
    return notify_fail ("������ʲô��\n");

  ridee = who->query_temp("ridee");
  if (ridee &&
      environment(ridee) != environment(who))
   ridee = 0;

  if (ridee)
    return notify_fail ("���Ѿ�"+ridee->query("ride/msg")+"��"+ridee->name()+"���ˣ�\n");

  rider = me->query_temp("rider");
  if (rider &&
      environment(rider) != environment(me))
   rider = 0;

  if (rider)
    return notify_fail (me->name()+"���������ˣ�\n");

  if( me->query("female_only") &&
	(string)who->query("gender")=="����" )
    return notify_fail( me->name()+"�Ǹ�Ů����ġ�\n");
if(who->query_temp("ride/dodge"))  return notify_fail("�����ڲ�������������!\n");

  if(me->query("ride/need_train") &&
     me->query("owner") != who->query("id"))
    return notify_fail("����Ҫ��ѱ��"+me->name()+"����ȥ������ \n");

  message_vision ("$N������һ���������ȵ�"+me->query("ride/msg")+"��$n�ϣ�\n",who,me);
  me->set_temp("no_return",1);
  me->set_temp("rider",who);
  who->set_temp("ridee",me);
  me->move(where);
  who->set_temp("ride/dodge",me->query("ride/dodge"));
  who->add_temp("apply/dodge",me->query("ride/dodge"));
  return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : mount <��������>

���ָ����������ﵽ�������ϡ�

HELP
);
  return 1;
}
