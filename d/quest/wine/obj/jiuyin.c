// jiuyin.c 
// made by kuku@sjsh  2002/12
// /d/quest/wine/obj/jiuyin.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({"jiu yin"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�ݾ�����\n");
                set("unit", "��");
                set("value", 0);
              set("no_sell",1);
              set("no_put",1);
              set("no_give",1);
              set("no_get",1);
        }
       setup();
}

void init()
{
        object me = this_object();
        object where = environment();

        if (userp(where))
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

void destruct_me(object where, object me)
{
        message_vision("$N���е�$nͻȻ��ʧ����Ӱ���١�\n",where,me);
        destruct(me);
}
