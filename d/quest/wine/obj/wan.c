// wan.c �ٻ��� 

inherit ITEM;
#include <ansi.h>

void init()
{
          object me = this_object();
         object who = this_player();
         object where = environment();
         if (!wizardp(this_player())) {
                set("no_give", "�����������������ˡ�\n");
                set("no_drop", "��ô����Ķ���������������ӡ�\n");
              set("no_sell", "����������������\n");
              set("no_get","����������������\n");
              set("no_put","��Ҫ��ʲô��\n");
           }
        if (! me->query("my_owner") && interactive (who))
        me->set("my_owner",who->query("id"));
     if (userp(where))
     {
        if (me->query("owned"))
        {
            if (me->query("owned")!=where->query("id"))
            {call_out("destruct_me",1,where,me);}
        }
        else
        {
           me->set("owned",where->query("id"));
         }
     }
}

void destruct_me(object where, object me)
{
    message_vision("ǧ��ֹ�����������$n���ž���,��׷!\n",where,me);
    destruct (me);
}

void create()
{
        set_name(RED"�ٻ���"NOR, ({"baihua wan","wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ص�ҩ�裬��֪��ʲô�����ô���\n");
                set("value", 5000);
              }
        setup();
}
