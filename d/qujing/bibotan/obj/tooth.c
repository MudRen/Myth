#include <ansi.h>

inherit ITEM;

void init();

void init()
{
  object me = this_object();
  object where = environment();

  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
	me->set("asdfghj", 0);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }

}

void create()
{
        set_name(YEL "��������" NOR, ({ "tooth" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ŵ���ɫ�����ӣ�����������������������С�\n");
                set("material", "silver");
                set("unit", "��");
		set("no_sell", 1);
		set("no_drop", 1);
		set("asdfghj", 1);
        }
        setup();
	set("is_monitored", 1);
}

