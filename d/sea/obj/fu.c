inherit ITEM;
int do_apply (string arg);
void create()
{
  set_name("������", ({"jinlong fu", "jinglong", "fu"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_sell", 1);
    set("no_drop", 1);
    set("unit", "��");
  
  set("long", "һ�Ż�ɫ��ֽ�������滭��β��������Ľ�����
�������Ի�(apply)���\n");
    }
    setup();
}
void init()
{
	add_action("do_apply", "apply");
}
int do_apply (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if ((! arg ||
     ! (ob = present(arg, who)))&&
	(! arg || ! (ob = present(arg, where))))
  {
    return notify_fail("��Ҫ����������ʲô�ã�\n");
  }
  if (ob == who)
  {
    message_vision ("$N������������Լ�������һ�������������䡱��һ��������������\n",who);
    message_vision ("��ʱ$Nֻ����һ�ɾ��������������̣�Ǭ�����ã�\n",who);
    who->unconcious();
  }
  else if ((string)ob->query("name") != "�˰�÷����" &&
	(string)ob->query("name")!="�Ź������" ) {

    message_vision ("$N�����������$n��һ�������������䡱��һ��������������\n",who,ob);
  }
  else
  {
	message_vision("$N�����������$n��һ�������������䡱��һ��������������\n
ֻ��$n���¹�Ӱ�ζ������������ֳ��������׭�䡣\n",who,ob);
	ob->set("OK_to_STUDY", 1);
  }
  destruct (me);
  return 1;
}

