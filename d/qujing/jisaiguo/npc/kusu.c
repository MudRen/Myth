string clean_tower();
inherit NPC;
void create()
{
       set_name("������ʦ", ({"kusu chanshi", "chanshi"}));
       set("gender", "����");
       set("age", 80);
        set("long", "һ�������С���Ϻ��У�һ�����ࡣ\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 18);
	set("str", 25);
       set("combat_exp", 150000);
  set("daoxing", 300000);

        set_skill("unarmed", 95);
        set_skill("dodge", 95);
        set_skill("parry", 95);
	set_skill("force", 95);
	set_skill("spells", 80);
	set_skill("buddhism", 80);
	set_skill("jienan-zhi", 80);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 40);
        set("mana", 30);
set("inquiry", ([
"here" : "�˵����Ǽ������⽨����¡�\n",
"ԩ��": "��ʧ�ԣ��ҵ������ѵ�⣬�಻�����ǣ�\n",
"��": "��ԭ�����������ϡ�\n",
"������" : "�������������к�Ժ��\n",     
"ɨ��" : (: clean_tower :),
]));

setup();
	carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}

string clean_tower()
{
	object me,obj,env;
	me=this_object();
	obj=this_player();
	env=environment(this_object());

	if( (string)env->query("short")!="���۱���") {
		command("say " + RANK_D->query_respect(obj) + "���ⷬ���⣬���������ˣ���������Ҳ����Ϊ����\n");
		return "��Ǹ��\n";
	}
	if( env->query("exits/enter") ) {
		command("say ����"  + RANK_D->query_respect(obj) + "�ˣ������롣\n");
		return "���Ǻ����š�\n";
	}
	command("touchy " + obj->query("id"));
	env->open_down();
	return"���Ǻ����š�\n";
}
�