//created by kuku@sjsh 2002/12

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIM"�ٻ���"NOR , ({"baihua niang", "wine"}));
        set_weight(500);
        if (clonep())
           set_default_object(__FILE__);
         else {
           set("unit", "ƿ");
           set("long","����Ǿƹ���λ�������ƾ�ʦ���ƹ����ľơ�\n");
           set("value", 0);
           set("no_sell", 1);
       }
  setup();
}

void init()
{
    call_out("destruct_me",2);
}

void destruct_me()
{
         destruct(this_object());
}

