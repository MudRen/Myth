e_vision ("$N����֣�����������͵ʲô������\n",who);
  call_out("no_steal",2,who,me);
  return 1;
}

void no_steal(object who, object me)
{
  message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��¶�׹⣬�����Ӷ���ɱ����\n",who);
  call_out("no_kill",2,who,me);
  return 1;
}

void no_kill(object who, object me)
{
  message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

void die()
{
  fully_recover (this_object());
}

void unconcious()
{
  fully_recover (this_object());
}

