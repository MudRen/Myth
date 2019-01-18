#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ħ���", ({ "tian wang", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "����" );
        set("long",
                "ħ���Ľ�֮һ��ʹһ�˷��컭ꪣ�����һ��ɡ����Ի������Ԫɡ����\n"
                "ɡ�����鴩�ɣ�����ĸ�̣���ĸ�̣�ҹ���飬�ٳ��飬�ٻ��飬��ˮ\n"
                "�飬�����飬�����飬�����飬�����顣�������鴩�ɡ�װ��Ǭ����\n"
                "���֣����ɡ���ҳţ��ſ�ʱ���ذ��������޹⣬תһתǬ���ζ���\n"
        );
        set("age",50);
        set("title", "��Ŀ����");
        set("attitude", "heroism");
        set("str",60);
        set("spi",60);
        set("int",30);
        set("max_kee",6100);
        set("kee",6100);
        set("max_sen",5100);
        set("sen",5100);
        set("combat_exp",5500000);
        set("daoxing",5500000);
        set("force",6000);
        set("max_force",3000);
        set("mana",3500);
        set("max_mana",5000);
        set("force_factor", 300);
        set("mana_factor",250);


        set("eff_dx", 3500000);
        set("nkgain", 800);

        
        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",380);
        set_skill("dodge",400);
        set_skill("spear",320);
        set_skill("bawang-qiang",350);
        set_skill("force",350);
        set_skill("spells", 350);

        set_skill("moshenbu", 300);
        map_skill("dodge", "moshenbu");
        map_skill("parry", "bawang-qiang");
        map_skill("spear","bawang-qiang");
        map_skill("unarmed", "yingzhaogong");
        set("inquiry", ([
                "name" : "���¹�Ŀ����ħ��죬��ʥ�Ͱ��ض����š�",
                "here" : "������Ƕ�����, ���ھ�������ˡ�",
        ]) );

        setup();
        carry_object("/d/obj/weapon/spear/huaji")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("san",3+random(3),me,ob);  
  ::
kill_ob(ob);
}


void san (object me, object ob)
{
  object huobing;
  int damage;

  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  message_vision (HIY"$N�ӻ��г����ħɡ���������˼��������ħɡ�����޵�������$n������\n"NOR,me,ob);

  if ( ((int)ob->query_skill("dodge", 1)+ random(50)) > 400 )
     message_vision (HIY"$N����Ծ����ħɡ������������һ����\n"NOR,ob);
  else 
    {
     message_vision (HIY"���$N����ס�����ж���\n"NOR,ob,me);
     ob->start_busy(10+random(5));
    } 

  remove_call_out ("san");  
  call_out ("san",random(5)+5,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision (HIY"$N�ŵ����Ⱦ��ܡ�\n"NOR,me);
  destruct (this_object());
  return ;
}
