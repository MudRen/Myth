// jiading.c

inherit NPC;

void create()
{
       set_name("Сѧͽ", ({"xuetu"}));

set("long","����СС�����Ǹ����ӣ�\n�ڰ�����ͷ����������\n");
       set("gender", "����");
       set("age", 15+random(4));
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 200+random(400));
	setup();

}

