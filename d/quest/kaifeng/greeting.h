// snowcat

void greeting1 (object who)
{
  object me = this_object();

  if (! visible (who))
    return;
  if (me->is_fighting())
    return;

  if (who->query("obstacle/number") > 0)
  {
    string str;
    object weapon = me->query_temp("weapon");

    if (weapon)
      str = "$N�������е�"+weapon->query("name")+"��$n����";
    else
      str = "$N������$n����";
    str = str + RANK_D->query_respect(who)+"����ȡ��������ب�ţ�\n";

    message_vision (str,me,who);
  }
}

void greeting2 (object who)
{
  object me = this_object();

  if (! visible (who))
    return;
  if (me->is_fighting())
    return;

  if (who->query("quest/reward") > 0)
  {
    string str;
    str = "$N��$nһ����"+RANK_D->query_respect(who)+
          "�����������֣�����ȥ�ݼ�����̫�ڣ�\n";
    message_vision (str,me,who);
  }
}

