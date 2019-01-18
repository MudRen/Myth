// zhangcui.c
inherit NPC;
#include "newplace.h";
#include <ansi.h>
string ask_jiang();

void create()
{
	set_name("����", ({ "teng she", "snake", "she" }));  
	set("title", "��ħ����");
	set("long", "�����ǹ��߶����е��߽���\n");
	set("gender", "����");
        set("age",31);
	set("attitude", "peaceful");
	set("str", 28);
	set("mana", 3000);
	set("max_mana", 3000);
	set("force", 4500);
	set("max_force", 4500);
	set("combat_exp", 1500000);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("dao", 300);
	set_skill("spells", 300);
	
	map_skill("spells", "dao");
	set("inquiry", ([
	"name" : "��Ҳ��֪���Լ���˭�����ܸ�����ô��\n",
	"here" : "���Ｔ��������Ｔ������ֺα�Ҫ�ʣ�\n",
	"��ħ" : "ȥ�������񽫰ɣ������ڲ��������ˡ�\n",
	"������" : (: ask_jiang :),
	]) );

	setup();

	carry_object("/d/obj/weapon/sword/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();

}
string ask_jiang()
{
   object me = this_object();
   object ob = this_player();
   if (ob->query_temp("ask_jiang")=="do")
	return "�ߣ��㲻�Ǹ��ʹ���ô��ô��\n";
   if (ob->query_temp("ask_jiang")=="ok")
	return "�ߣ�����ô����ȥ�������񽫣�\n";
   ob->set_temp("ask_jiang", "do");
   tell_object(ob,me->query("name")+"�������ѵ������ô����ô����\n");
   return "�ߣ�\n";
}
int accept_object(object who, object ob)
{
   object jiang=new("/d/wudang/npc/wulei");
   if (who->query_temp("ask_jiang")=="do"){
   if (ob->query("money_id") && ob->value() >= 10000)
   {
     who->set_temp("ask_jiang","ok");
	jiang->move(newplace[random(sizeof(newplace))]);
//	return "�ߣ�������\n";
     tell_object(who,CYN"\n"+this_object()->query("name")+"���ٺ٣���������������û��������������ȥ�ɣ��ɱ�˵��������ȥ�İ���\n\n"NOR);
     return 1;
   }else{
	command("hmm");
   	return 1;}
   }else{
	tell_object(who,CYN"\n"+this_object()->query("name")+"����¸�ң����������£������������Ҳ�֪�������ʲô�����ٺ٣�\n\n"NOR);
     return 1;
	}
   return 0;
}
