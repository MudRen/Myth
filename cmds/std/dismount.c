// by snowcat feb 4 1998

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object who, string arg)
{
  object me;
  object where = environment(who);

  if (! arg ||
      ! where ||
      ! (me = present(arg,where)) ||
      ! me->query("ride/msg"))
    return notify_fail ("�����ʲô��������\n");

  if (me != who->query_temp("ridee"))
    return notify_fail ("�㲢û��"+me->query("ride/msg")+"��"+me->name()+"�ϡ�\n");
      
  message_vision ("$Nͦ���$n��Ծ������\n",who,me);
  me->set_temp("no_return",0);
  me->set_temp("rider",0);
  who->set_temp("ridee",0);          
  who->add_temp("apply/dodge",-who->query_temp("ride/dodge"));
  who->set_temp("ride/dodge",0);
  return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : mount <��������>

���ָ����������������������

HELP
);
  return 1;
}
