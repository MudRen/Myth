//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({"liu hong","liuhong","liu"}));
        set("gender", "����");
        set("age", 38);
        set("title","����֪��");
        set("long","һ�����������˺ܲ������֪����");
        set("per", 10);
        set("str", 40);
        set("combat_exp",50000);
	set("daoxing",50000);	
        set("max_force",1000);
        set("force",1000);
        set("force_factor",40);
        set("max_kee",300);
        set("max_sen",300);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("sanqing-jian",80);
        set_skill("dodge",100);
      set_skill("changquan",100);
        map_skill("unarmed","changquan");
        map_skill("parry","sanqing-jian");
        map_skill("sword","sanqing-jian");
        seteuid(getuid());        

        set("inquiry", ([
                "�¹���": (: kill_ob(this_player()) :),
                "���½�": "�����ҵĽᷢ����",
                ])),
        setup();

        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/cloth/jinpao")->wear();
}
void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/jz_liuhong_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("�������ˡ�\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/jz/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}

void unconcious ()
{
  die ();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}




