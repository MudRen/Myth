//Cracked by Roath
 
#include <ansi.h>
inherit NPC;

int buy_jiasha(object me);
int ask_qujing(object me);
int so_gui(object me);
int hao_bu_hao(object me);
int buyao_qian(object me);
void create()
{
   set_name("������", ({ "jielai heshang", "heshang", "bonze" }));
   set("long", @LONG
������ݣ������䣬��Ź�ͷ��
LONG);
   set("gender", "����");
   set("age", 35);
   set("title", "�����");
   set("attitude", "peaceful");
   set("rank_info/self", "ƶɮ");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jinguzhou" :)
   }) );
	     set("chat_chance", 20);
	     set("chat_msg", ({
	       "�����д�����˵��������һ��[ʾ��]���챦���ģ�\n"
               "�����д����غ�����ƶɮ����������ġ�\n",
               "�����д����ؽе����������ģ�����һ�ƣ����������֮�֣��׹�һ˿���ó�����ʥ֮����������������񣻷��ٶ������߷�����\n",
               "�����д�����˵�������������Ǳ���������˿���ɽ�����Ϊ�ߡ��ɶ�֯�ͣ���Ů���ɣ������ط��廨�죬ƬƬ���ѽ��ء�����ɢ�鶷ױ����ɫ��Ʈ���籦�ޡ�\n",
               "�����д�����˵������������������������ƣ�����һ�β��Ʒɡ���������͸���⣬����ɽǰ������������Ƕ�������������������Ƕ���\n",
               "�����д����ؽе������������Ľ�����ҹ���飬�ܶ���һ����ĸ�̡�����ȫ��ԭ���壬Ҳ������˱��ܡ�\n",
               "�����д�����˵���������ģ���ʱ�۵�����ʥ�Ŵ�����ʱ�۵���ǧ�����͸���ޣ���ʥ�Ŵ���������������¡�\n",
               "�����д�����˵�������������ϱ��������飬Ħ���飬�ٳ��飬�����飻�����Ǻ���解���ɺ����ҹ���飬�����ӡ�͵���߰ף��������졣\n",
               "�����д�����˵������������ӯ�գ���������ʥ����������ӯ�գ��ճ�����أ����������ʥ��Ӱ�������硣��ɽ������������Ӱ��������������\n",
               "�����д�����˵�����ر�������������ߵ�����������顣ʫԻ������ΡΡ�������������������ۡ����Ľ������취�������ܴ��ǻ۵ơ�\n",
               "�����д�����˵��������ׯ�Ͻ����磬�����徻��������Դӷ������ĺ����˭�ܸҶ�ɮ����\n",
                (: random_move :)
        }));
        set("inquiry", ([
	"������": (: buy_jiasha :),
        "ȡ��": (: ask_qujing :),
        "��ô��":(:so_gui :),
        "���벻��":(:hao_bu_hao :),
        "��ҪǮ":(:buyao_qian :),
        ]) );



   setup();
carry_object("/d/obj/weapon/staff/gangzhang")->wield();
   carry_object("/d/nanhai/obj/sengpao")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}
void init()
{
        object ob=this_object();
	object me=this_player();
	::init();
	add_action("do_kill", "kill");
	if (! interactive(me))
	return;
	if( (int)me->query("eff_kee") < (int)me->query("max_kee")*3/4 )
   	
	switch (random(2))
	  {
    	case 0:
    	{	
	command("say ��λ"+ me->query("rank_info/respect")+"��ɫ��̫�ã��������㿴����\n");
	command("exert lifeheal "+me->query("id") );
	command("exert recover");
	}
	break;
	case 1:
	{
	command("pat "+ me->query("id"));
	command("say ��λ"+ me->query("rank_info/respect")+"Ҫע������Ŷ��\n");
	}
	break;
	}

	if( me->is_fighting() )
	{
	command("sigh" + me->query("id"));
	message_vision(HIY"$N����$n̾����ԨԨ�౨����ʱ�˰�����λ"+me->query("rank_info/respect")+
		"����һ�䣬�������������سɷ�\n"NOR,ob,me);
	message_vision(HIY"$N���գ�������ٴ���ȥ�ˡ�\n"NOR,me);
	me->remove_all_killer();	
	}
}
int so_gui(object me)
{
	message_vision(HIY"�����кô����в��ô�����ҪǮ�����в�ҪǮ����\n"NOR,me);
	return 1;
}	            
int hao_bu_hao(object me)
{
	message_vision(HIY"���������ģ����ó��٣���������������֮�ѣ���������֮�֣����Ǻô�,\n"NOR,me);
	message_vision(HIY"��̰���ֻ�����ɮ����ի����ĺ��У��پ�����ķ����Ѽ�������֮�棬����ǲ��ô���\n"NOR,me);
	return 1;
}	            
int buyao_qian(object me)
{
	message_vision(HIY"����𷨣�����������ǿ�����ģ���Ҫ������ǧ���������ҪǮ,\n"NOR,me);
	message_vision(HIY"������������������ϲ������ҷ𣬳��ܵ����ҽ�������Ը���������ҽ����Ե������ǲ�ҪǮ��\n"NOR,me);
	return 1;
}	            
int buy_jiasha(object me)
{
	message_vision(HIY"�������������ǧ���ƽ�\n"NOR,me);
	return 1;
}	            

int ask_qujing(object me)
{       
	
	object jiasha=new("/d/obj/cloth/jiasha2");
	me=this_player();
	if( me->query("obstacle/jz") != "done") 
	return notify_fail("ȡ��������ȡ������\n");
		message_vision(HIY"��������Ȼ����ȡ�澭���ˡ�\n"NOR, me);
                message_vision(HIY"��ͽ�������Ĵ͸��㣬��������ȡ���澭��\n"NOR, me);
                jiasha->move(me);
		message_vision(HIW"$N��$nһ��"+jiasha->name()+"��\n"NOR, this_object(), me);
		message_vision(HIW"�����ֳ���������������һ�������ϣ���ʧ�ڿ���"NOR,me);
                message_vision(HIW"�㲻������Ĥ�ݣ�����������ȥ��\n"NOR,me);         
		destruct(this_object());
		return 1;
}
int do_kill(string arg)
{
  object me = this_player();
  object ob = this_object();

  if (arg)
  {
	message_vision(HIY"$N����$n̾����ԨԨ�౨����ʱ�˰�����λ"+me->query("rank_info/respect")+
			"����һ�䣬�������������سɷ�\n"NOR,ob,me);
	message_vision(HIY"$N���գ�������ٴ���ȥ�ˡ�\n"NOR,me);
    return 1;
  }
  return 0;
}

