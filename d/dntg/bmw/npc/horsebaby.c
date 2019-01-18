#include <ansi.h>
#include <dbase.h>

inherit NPC;

void create()
{
  set_name("С����", ({ "ma zai", "zai" }) );
  set("race", "Ұ��");
  set("age", 2);
  set("long", "һֻ����������С���̣���ʹ��ȫ���������վ������\n");
  set("per", 10+random(20));
  set("eff_kee", 50);
  set("eff_sen", 50);
  set("combat_exp", 0);
  set("daoxing", 0);

  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 10);


  setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);

        set("chat_msg", ({
            "С���̷�������Ľ�����\n",
            "С����һ����С�ģ�ˤ���ڵ��ϡ�\n",
            "С���̴��Ŵ�����\n",
            "С����̧��ǰ�ȣ�������վ������\n",
        }) );

        add_action("do_feed", "feed");
}

int do_feed(string arg)
{
        object me,feeob;
        object hb = this_object();

        me = this_player();
        
   
        if ( !arg || !(feeob=present(arg, me)) )
           return notify_fail("��Ҫ��С����ιʲô�ԣ�\n");

        else if (arg != "grass") 
           return notify_fail("�ⶫ��С���̳Բ��ˡ�\n");  

        else 
                { 
                if (me->query("kee")>10)  me->add("kee",-10); 
                else
                   {
                   me->unconcious();
                   return 1;
                   }

                destruct(feeob);



                if ( random(20) != 0 )
                message_vision("$N��С����ι��һЩ��ݣ�С���̽����ζ�ĳ���������\n", me);

                else
                  {
                  object smallhorse;
                  message_vision("С���̳���С�ݣ�ǰ��һ�վ��������\n" , me,);
                  smallhorse = new (__DIR__"smallhorse");
                  smallhorse->move(environment());
                  destruct(hb);
                  }
                }
        return 1;
}
�
