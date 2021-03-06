#include <ansi.h>
inherit NPC;
void create()
{
        set_name("魔礼海", ({ "tian wang", "duowen tianwang", "hai", "tianwang" }) );
        set("gender", "男性" );
        set("long",
                "魔家四将之一，使一根盘龙棍，背上一面琵琶，上有四条弦；也按\n"
                "地、水、火、风，拨动弦声，风火齐至，如青云剑一般。\n"
        );
        set("age",50);
        set("title", "多闻天王");
        set("attitude", "heroism");
        set("str",60);
        set("int",40);
        set("max_kee",5100);
        set("kee",5100);
        set("max_sen",4100);
        set("sen",3100);
        set("combat_exp",4500000);
        set("daoxing",5000000);
        set("force",6000);
        set("max_force",2500);
        set("mana",6500);
        set("max_mana",3000);
        set("force_factor", 270);
        set("mana_factor",120);

        set("eff_dx", 3500000);
        set("nkgain", 800);
        
        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",380);
        set_skill("dodge",380);
        set_skill("stick",300);
        set_skill("kusang-bang",280);
        set_skill("force",280);
        set_skill("spells", 180);
        set_skill("moshenbu", 380);
        map_skill("dodge", "moshenbu");
        map_skill("parry", "bawang-qiang");
        map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
        set("inquiry", ([
                "name" : "在下多闻天王魔礼海，奉圣谕把守西天门。",
                "here" : "这里就是西天门, 入内就是天界了。",
        ]) );

        setup();
        carry_object("/d/sea/obj/dragonstick")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("pipa",3+random(2),me,ob);  
  ::kill_ob(ob);
}


void pipa (object me, object ob)
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

  message_vision (HIY"$N掏出碧玉琵琶，竟在战场上悠然自得的弹了起来！\n"NOR,me);

  if ( (ob->query("mana")+random(500)) > 4000 )
     message_vision (HIY"$N充耳不闻，不为所动。\n"NOR,ob);
  else 
    {
     message_vision (HIY"$N就象着了魔一样，顿感头昏脑涨！\n"NOR,ob);
     damage=(me->query("mana"))/5; 
     if ( ob->query("sen") < damage ) ob->unconcious();
     else ob->add("sen",-damage);
    } 

  remove_call_out ("pipa");  
  call_out ("pipa",random(6)+5,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision (HIY"$N吓得撒腿就跑。\n"NOR,me);
  destruct (this_object());
  return ;
}
