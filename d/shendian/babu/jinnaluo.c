#include <ansi.h>
inherit NPC;

string ask_tianshen();
 
void create()
{
   set_name(HIR"������"NOR, ({"jinna luo","luo"}));
      set("long", "�˲������еĽ�����\n");
       set("title", HIB"�˲�����"NOR);
       set("gender", "Ů��");
       set("age", 50);
       set("attitude", "peaceful");
       set("per", 10);
       set("max_kee", 3100);
       set("max_gin", 3100);
       set("max_sen", 3100);
       set("force", 3150);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3500);
       set("mana", 3500);
       set("mana_factor", 150);
       set("combat_exp", 4000000);
         set("daoxing", 4000000);
        set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("parry", 300);
        set_skill("spells", 300);
        set_skill("force", 300);
        set("inquiry", ([
                "�����" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                ]) );
   setup();
        carry_object("/d/obj/cloth/mangpao")->wear();
}
 
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/jinnaluo") == "begin")
              return "��Ҫ�Ķ����ģ�\n";
        if ( (string)me->query_temp("babu/jinnaluo") == "done")
                return "�㲻����������\n";
  command("say �ҿ��Ը���������֮�������\n");
  command("grin \n");
   command("say ������ͨ���ɣ�ȥ�����Ұ������١�\n");
  me->set_temp("babu/jinnaluo","begin");
  return "��ȥ���Ŷ��\n";
}

int accept_object(object me, object ob)
{
  string myname=RANK_D->query_rude(me), thing=(string)ob->query("id");
   if (me->query_temp("babu/jinnaluo") == "begin")
   {
     if (ob->query("id") != "wuxian qin")
    {
      command ("say ����ʲô���ã���Ҫ��");
      call_out("dropthing", 1, thing);
      return 1;
    }
  else
    {
      command ("jump "+ me->query("id"));
      command ("say "+myname+"�����");
      command ("say ���ǵ���ȫ���ѹ���");
      command ("say ��֧����ȥ����֮������㻹��ȥ���������˲���");
      me->set_temp("babu/jinnaluo","done");
      call_out("destroy", 1, ob);
      return 1;
    }
  }
  else
  {
  command ("say ����Ҷ�������");
  }
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
void dropthing(string thing)
{
  command("drop "+thing);
  return;
}
