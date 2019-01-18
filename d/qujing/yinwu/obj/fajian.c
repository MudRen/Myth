// by snowcat 11/22/1997

inherit ITEM;

string *names = ({
  "��«��",
  "��ʵ�",
  "ˮ����",
  "���ȹ�",
  "������",
  "�ϱۺ�",
});

void create()
{
  set_name("����", ({"fa jian", "jian"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һϸ���ķ����Ͽ���һЩӬͷ���ġ�\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("б��ͻ��$n����ȥ����\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  add_action ("do_apply", "apply");
  add_action ("do_apply", "point");
  add_action ("do_apply", "zhi");
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

int do_apply (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object xiaoyao;

  if (! arg ||
      ! (xiaoyao = present(arg,where)))
    return notify_fail ("��Ҫ�÷����ʲô��\n");

  message_vision ("$N���𷨼򣬿��������дǵض�$nһ�Ρ�\n",who,xiaoyao);
  remove_call_out ("applying");    
  call_out ("applying",2,who,xiaoyao);    
  return 1;
}

void applying (object who, object xiaoyao)
{
  if (! xiaoyao ||
      xiaoyao->query("id") != "xiao yao")
  {
    message_vision ("ʲô�漣��û������\n",who);
    return;
  }
  if (! xiaoyao->query_temp("disabled"))
  {
    message_vision ("$N����Ƥ��û��̧һ�¡�\n",xiaoyao);
    return;
  }
  message_vision ("$N����һ��һ��������ԭ�Ρ�\n",xiaoyao);
  if (xiaoyao->query("name") == "С��")
    xiaoyao->set_name(names[random(sizeof(names))],({"xiao yao","yao"}));
}
