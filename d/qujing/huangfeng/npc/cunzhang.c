// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/cunzhang

inherit NPC;
void create()
{
       set_name("�ϴ峤", ({"cun zhang", "wang"}));

set("long","���Ҵ�峤�������������ܸɡ�\n");
       set("gender", "����");
       set("age", 61);
       set("per", 100);
	set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 5000);
       set_skill("unarmed", 15);
	set_skill("dodge", 30);
	set_skill("parry", 15);
set("inquiry", ([
"name": "�������������Ǳ���Ĵ峤��\n",
"here": "���Ҵ���Ҳ��\n",
"rumors": "�����Ʒ���������Խ��Խ�ף�������һ�ջ��۵����������治֪����Ǻã�\n",
"�Ʒ���": "��ȥ��ʮ��Զ������һ��ɽ�������˰���Ʒ��롣��ɽ�ж������֡�\n",
"����": "��˵��Щ�������ý�����������ûһ�����Ż����ģ��Ϻ���Ҳֻ����˵������������\n",
]) );

	setup();
       add_money("silver", 30+random(5));
	carry_object("/d/ourhome/obj/choupao")->wear();
}
