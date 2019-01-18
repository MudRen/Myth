// hudian.c
// created by mes, updated 6-20-97 pickle
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("������", ({"hudian yao", "yao", "hu dian", "hudian", "monster"}));
  set("long","һ��������Բ�Ļ�����������ȥ���в�ǳ��\n");
  set("gender", "����");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 130000);
  set("daoxing", 100000);

  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() 
	  && living(me) ) {
    call_out("greeting", 1, me);
  }
}

void greeting(object me)
{
  int myspells, mykar, diff;
  string npcname=this_object()->query("name");

  if( !me || environment(me) != environment() ) return;

  myspells=me->query_skill("spells");
  mykar=me->query_kar(); 
  diff=40-mykar;

  if(me->query("family/family_name") == "�ݿ�ɽ�޵׶�")
    return;
  if( member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1)
    {
      command("say ʲô�������������޵׶����룡");
      kill_ob(me);
      return;
    }
  if( random(myspells+mykar) > diff) return;
  else
    {
      message_vision(CYN ""+npcname+"��$N��ȵ���߾��ʲô������������������������ȥ��\n"NOR, me);
      message_vision(npcname+"��һ�����֣�$N��ʱ�ֳ�ԭ�Σ�ԭ����"+me->query("name")+"��\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}









�