//created 5-20-97 pickle

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;
//inherit SKILL;

void create()
{
  set_name(HIY"�Ʒɻ�"NOR, ({"huang feihu", "huang", "feihu", "huangfeihu"}));
  set ("long", @LONG
����������Ʒɻ������ܵ�һ�󽫣������
������֮�׶���̩ɽ������ʥ��ۣ��·�Ѱ
������ɫ��ţ�����䡣
LONG);
 
  set("title", HIW"����̩ɽ������ʥ���"NOR);
  set("gender", "����");
  set("age", 43);
  set("str", 55);
  set("per", 35);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
  set("combat_exp", 8000000);
  set_skill("spear", 220);
  set_skill("force", 220);
  set_skill("dodge", 220);
  set_skill("stick", 220);
  set_skill("literate", 200);
  set_skill("dali-bang", 180);
  set_skill("huoyun-qiang", 180);
  set_skill("parry", 200);
  set_skill("unarmed", 220);
set_skill("wuyue-spear", 200);
set_skill("spells", 220);
set_skill("pingtian-dafa", 220);
  set_skill("moshenbu", 180);
  set_skill("huomoforce", 220);
  set_skill("moyun-shou", 180);
map_skill("force", "huomoforce");
map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("spear", "wuyue-spear");
  map_skill("parry", "wuyue-spear");
  map_skill("stick", "dali-bang");
  map_skill("dodge", "moshenbu");
  set("max_sen", 10000);
  set("max_kee", 10000);
set("force", 10000);
set("max_force", 6000);
set("mana",6000);
set("max_mana",3000);
set("daoxing",5000000);
set("force_factor", 200);
set("mana_factor", 150);
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
                (: perform_action, "spear", "buhui" :),
                (: perform_action, "unarmed", "zhangxinlei" :),
  }) );
 
  create_family("���ƶ�", 1, "��");
  setup();
 
       carry_object("/d/obj/weapon/spear/huaji2")->wield();
//carry_object("/d/city/obj/xjdan");
  carry_object("/d/obj/armor/jinjia")->wear();
}
 
int accept_fight(object me)
{
  command("say �Ϸ����أ��������˷��������ˡ�\n");
  return 0;
}
int attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="���ƶ�") {
if (((int)ob->query("combat_exp") < 400000 )) {
command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return 0;
   }
        command("haha "+ob->query("id"));
 command("say ��������֣����Ǽ������������Ҵ���Щ������ȥ���Ұ���pk��û���У�\n");
command("recruit " + ob->query("id") );
return 0;
}
command("say " + RANK_D->query_respect(ob) +
"�����ٿ�������ǹ���գ�\n");
       return 1;
}
/*
{  
string myname=RANK_D->query_respect(me);
 if ((int)me->query_skill("spear")< 200) 
//  if ((int)me->query_skill("spear")< 200) 
    {
      command("say ��"+myname+"�ٿ�������ǹ���գ�");
      return 0;
    }
  if ((int)me->query_skill("stick") < 200 )
    {
      command("say ��"+myname+"֪��������������䣿");
      return 0;
    }
  command("say ��������֣����Ǽ������������Ҵ���Щ������ȥ���Ұ���pk��û���У�\n");
  command("recruit " + me->query("id") );
  return 1;
}
*/
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
      ob->set("title", "�����������ɽ��");
}

