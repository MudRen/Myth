//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
 int accept_object(object me, object ob);
void create()
{
       set_name("�׾���", ({"bai jingjing", "bai", "jingjing","master"}));
       set("long",
"��˿�������µĶ����Ӱ׹Ǿ�,����˿�����޳�����,������յ�ȡ��˿�������¹ⱦ�϶�����ʦ�㴺
ʮ�����Ƴ�ˮ����һ���������£���������������ѩ���������֮�������䣬ʵ�����������
���¡������ݡ�\n");
       set("title", HIW"�׹Ƕ���"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("color", HIC);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 40);
       set("int", 30);
       set("max_kee", 2900);
       set("max_sen", 2800);
       set("force", 4200);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
       set("daoxing", 1200000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 150);
       set_skill("dodge", 180);
       set_skill("force", 150);
       set_skill("parry", 100);
       set_skill("qin", 200);
       set_skill("sword", 180);
       set_skill("spells", 150);
   set_skill("pansi-dafa", 150);
   set_skill("lanhua-shou", 150);
   set_skill("jiuyin-xinjing", 150);
   set_skill("chixin-jian", 200);
   set_skill("yueying-wubu", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "chixin-jian");
   map_skill("dodge", "yueying-wubu");
   set("chat_chance",5);
   set("chat_msg", ({
        HIG"�׾�������������:ʮ����������˵������Ȣ�ң��ҵ��������ꡭ��ԭ��һ�ж���ƭ�ҵģ�\n"NOR,
        HIG"�׾�������������:������һ���ˣ��͸���һ̳�ƣ���˵�ǽ���������������֮�󣬿��Խ����������������κ��¡�\n"HIC,
        HIG"�׾�������������:�����Ҹ����������ºȾƣ�������˵��������и����ã���һ��Ȣ��Ϊ�ޡ�����֪����Ů�ӣ�ΪʲôҪ����˵��\n"NOR,
		HIG"�׾�������������:��֪�����ɺϻ�������ԭ����ǰÿ��������˿����ʱ���춼�����꣡\n"NOR,
		HIG"�׾�������������:�������Ͳ�����������磬����һ�������������ɡ���˵���������������������ǲ��ҵģ������Ƕ��˷��ĵ���
�֡������ǲ����и���ģ������Ҳ�����ˣ�\n"NOR,
        }));


create_family("��˿��", 2, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{

	if (((int)ob->query("combat_exp") < 100000 )){
//	this_player()->set("mark/pansi_bai", 1);
	command("shake");
	command("say ƾ�������Ϊ��");
	return;}
       	if(!ob->query_temp("marks/zui")){
//        this_player()->set("mark/pansi_bai", 1);
	  command("shake");
	  command("say ������Ե����������߾Ͱɡ�\n");
	  return ;
	}
	else{
	command("curtain");
	command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ���ҵ����£����ձ������ɣ�\n");
	command("recruit " + ob->query("id") );
        ob->set("title", HIW"����ɽ�׹Ƕ������µ���"NOR);
	ob->set("class", "yaomo");
	return ;}
}
int accept_object(object me, object ob)
{
    
    if(ob->query("name") == "[1;32m��������[2;37;0m" && ob->query("realzui"))
    {
        command("say ��,������������Ȼֻ��һ̳��ˮ���ˣ�\n");
    
	command("say �������������?лл��,���ڿ��������Ǹ��������ˡ�");
	command("jump");
    	me->set_temp("marks/zui",1);
	return 1;}
	return 0;
}

