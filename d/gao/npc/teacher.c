inherit NPC;
void create()
{
       set_name("������", ({ "kuang wenzheng", "kuang", "teacher"}));
       set("title", "��������");
       set("long","������Ͻ��������������ǵ�ɨäȫ�����ˣ�\n");
       set("gender", "����");
       set("age", 66);
	set("int", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("literate",60);
	set_skill("sword", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set("combat_exp", 10000);
  set("daoxing", 5000);

set("inquiry", ([
"name"  : "�Ϸ��տ�������������ǣ�����",
"here"  : "������Ϸ���ѧ�ã��̺�����һЩ֪ʶ��",

]) );
set("chat_chance", 5);
set("chat_msg", ({
"������˵������С������ȥ�ã�çײ�粽���С�����Ҫ���μǵã�\n",
"������ҡͷ���Ե��������Ի��������Զ�����������ֺ��������뱸����\n",
"������Цӯӯ�ظ�����к������ˣ���\n",
}) );

setup();
carry_object("/d/gao/obj/ruler")->wield();
carry_object("/d/gao/obj/changpao")->wear();
add_money("silver", 5);
}


�