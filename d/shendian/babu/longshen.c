// repoo
#include <ansi.h>
inherit NPC;
string ask_tianshen();
void create()
{
     set_name(HIR"����"NOR, ({ "long shen", "long", "dragon" }) );
        set("gender", "����" );
     set("long",HIB
              "�˲�����\n"NOR);
 
        set("age",50);
         set("title", HIB"�˲�����"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
         set("max_kee",4100);
        set("kee",4100);
        set("spi",60);
        set("max_sen",3100);
        set("sen",3100);
         set("combat_exp",6000000);
      set("daoxing",5500000);
        set("force",6000);
        set("max_force",3000);
        set("mana",6000);
        set("max_mana",3000);
       set("force_factor",250);
        set("mana_factor",250);
        set("eff_dx", 4500000);
        set("nkgain", 1500);
        set_skill("unarmed",250);
        set_skill("dragonfight", 250);
         set_skill("parry",250);
        set_skill("dodge",250);
            set_skill("dragonstep",230);
        set_skill("fork",250);
        set_skill("fengbo-cha",180);
        set_skill("force",250);
            set_skill("dragonforce",220);
        set_skill("spells", 300);
        set_skill("seashentong", 250);
            map_skill("force","dragonforce");
              map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("parry", "fengbo-cha");
        map_skill("fork","fengbo-cha");
        map_skill("unarmed", "dragonfight");
        set("inquiry", ([
             "name" : "����ɳ��������,�˰˲���������",
                "�����" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                        ]) );
    set("chat_chance_combat", 80);
             set("chat_msg_combat", ({
                (: perform_action,"unarmed","leidong" :),
            (: cast_spell, "dragonfire" :),   
            (: cast_spell, "freez" :),   
            (: cast_spell, "hufa" :),   
            (: cast_spell, "water" :),   
       }) );
              setup();
        carry_object("/d/sea/obj/longpao")->wear();
}
void init()
{
        ::init();
        add_action("do_cast", "cast");
}
int do_cast (string arg)
{
  object who = this_player();
   if ((arg == "qiankun") || (arg == "qiankun on long shen") || (arg == "qiankun on long") || (arg == "qiankun on dragon"))
{
      tell_object(who,"������һ�ף�\n");
      return 1;
     }
  else return 0;
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  call_out ("xue",8+random(8),me,ob);  
  ::kill_ob(ob);
}
void xue (object me, object ob)
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
  message_vision ("$N"HIW"�ſ����죬�������˼��������ʱ������ӿ��һƬ��ѩ��$n������\n"NOR,me,ob);
  if ( ((int)ob->query_skill("dodge", 1)+ random(100)) > 240 )
     message_vision (HIC"$N����Ծ������У���������һ����\n"NOR,ob);
 else 
    {
     message_vision (HIW"���$N����ס�����ж���\n"NOR,ob,me);
     ob->start_busy(3+random(5));
    } 
  remove_call_out ("xue");  
  call_out ("xue",random(10)+10,me,ob);  
}
void die ()
{
  object me = this_object();
   object ob = query_temp("my_killer");
  object yi;
  string longyi_given;
   longyi_given = "/d/shendian/babu/obj/longyi.c";
    ob->set_temp("babu/longshen","done");
   if (!longyi_given->in_mud())
         {
   yi = new("/d/shendian/babu/obj/longyi");
  yi->move(ob);
   message_vision ("$N"HIY"�����Ӵܣ���������Ǵ���....\n"+HIM"һ�Գ�������$n���ϡ�\n"NOR,me,ob);
 message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+ob->query("name")+"�õ�"+HIY"����"+HIB"֮��"NOR+YEL"�ˣ�\n\n"+NOR,users() );
  destruct (this_object());
  return ;
       }
    else
       {
  message_vision ("$N"HIY"����һ�����......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/longshen") == "done")
                return "��ɱ�ң���ɱ�ң�\n";

  command("say ����֪������֮�������\n");
   command("say �����ף�ɱ���Ұɣ�\n");
   kill_ob(me);
  return "����֪�������������\n";
}
