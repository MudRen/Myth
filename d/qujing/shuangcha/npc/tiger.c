//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("��쵻�", ({ "lao hu","tiger","hu" }) );
   set("race", "Ұ��");
   set("age", 3);
   set("long", "һֻ���Ӻ��׺ݵ��ϻ���\n");
   
   set("str", 32);
   set("max_kee",400);
   set("kee",400);

   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
   set("verbs", ({ "bite", "claw" }) );
   set_skill("unarmed",50);
   set_skill("parry",50);
   set("combat_exp",60000);
   set_temp("apply/attack", 20);
   set_temp("apply/armor", 10);

   setup();
}
void destruct_me (object me)
{
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
        object ob=this_object()->query_temp("my_killer");
        object corpse;
        object me=this_object();
        if(ob) {
        ob->set_temp("tiger_kill","yes");
        }
        message_vision ("$N�ҽ�һ��������Ѫ���С�\n",me);
        corpse = CHAR_D->make_corpse(me,ob);
        corpse->move(environment(me));
        load_object("/obj/empty");
        me->move("/obj/empty");
        call_out ("destruct_me",3,me);
}

void destroy(object ob)
{
        destruct(ob);
        return;
}