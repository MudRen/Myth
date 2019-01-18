#include <ansi.h>

inherit NPC;



void create()
{
        set_name("�����", ({"huo bing", "bing"}));
        set("gender", "����" );
        set("age", 33);
        set("long", "�칬�𲿴󽫣��þ�ɳ���������ͽ����ơ�\n");
        set("class", "xian");
        set("combat_exp", 100000);
        set("daoxing", 1000000);

        set("attitude", "aggressive");
        set_skill("unarmed", 80);
        set_skill("yingzhaogong", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spear", 80);
        set_skill("huoyun-qiang", 80);
        set_skill("spells", 100);
        set_skill("taiyi", 100);
        set_skill("moshenbu", 80);
        set_skill("force", 80);   
        set_skill("huomoforce", 80);
        map_skill("force", "huomoforce");
        map_skill("spear", "huoyun-qiang");
        map_skill("dodge", "moshenbu");
        map_skill("unarmed", "yingzhaogong");
        map_skill("spells", "taiyi");

        set("max_kee", 800);
        set("max_sen", 800);
        set("mana", 2000);
        set("max_mana", 2000);
        set("mana_factor", 5);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 5);


        setup();
	carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/qujing/pingding/obj/weapon11")->wield();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("penhuo",5+random(5),me,ob);  
  ::kill_ob(ob);
}

void penhuo (object me, object ob)
{
  object huobing;
  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)

    return;

  if (environment(ob) != environment(me))
    return;

  huobing = new (__DIR__"huobing");
  huobing->move(environment (me));
  me->command("exert recover");
  message_vision (HIY"ֻ��$N�������е�����һչ����ʱ�ı����ܴ����$n������\n"NOR,me,ob);
  message_vision (HIY"�������ֳ�һֻ$N��\n"NOR,huobing);

  remove_call_out ("penhuo");  
  call_out ("penhuo",random(15)+15,me,ob);  
}



void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  ob->add_temp("dntg/laojunlu_day",2);
  message_vision (HIY"$N��ʧ�ڻ�֮�С�\n"NOR,me);
  destruct (this_object());
  return ;
}
