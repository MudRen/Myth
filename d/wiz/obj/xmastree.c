#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIW"ʥ����"NOR, ({ "shengdan shu","xmas tree","tree"}));
    set_weight(5000000);
    set("unit", "��");
    set("long", "һ�ò��þ�����ʥ��������������˾�����ʥ����(card),\n"
         +"���˽���ס����(pick)����.\n");
    set("no_get","��ô�ص�ʥ������Ҳ����ߣ�\n");
    set("value", 0);
}

void init()
{
    add_action("do_pick", "pick");
}

int do_pick(string arg)
{
       object me,ob;
       me = this_player();
       if (!arg || arg!="card" ) return notify_fail("��Ҫ��ʲô��\n");

	if (me->query("yudian/card")=="got")
	{
  switch (random(1))
         {
	case 0:
         {message_vision("$N��ش����ϵ�������ˤ�˸���ƨ�ף�\n",me );break;}
	case 1:
         {message_vision("$N������צ��ʲôҲûץ�ţ�\n",me );break;}
	}
	return 1;
           }

  switch (random(2))
  {
    case 0:
          { message_vision("$N��伸�¾����������⣬������������ʥ����������������ƵƵ���֣�\n",me );break;}
       case 1:
          { message_vision("$N������צ��ץ��һ��ʥ����Ƭ��\n",me );break;}
       case 2:
       {message_vision("$N����ץ��һ�ž�����ʥ�������۵�һ��󺹣�\n",me );break;}
}
	me->set("yudian/card","got");
       ob=new("/d/wiz/obj/card.c");
       ob->move(me);
	ob->set("owner",me->query("id"));
       return 1;
}

