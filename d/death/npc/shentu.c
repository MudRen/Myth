//puti.c
inherit NPC;

void create()
{
       set_name("��ݱ", ({"shen tu", "tu"}));
	set("title", "�뻧");
       set("gender", "����");
	set("long", "һ������ϲ�����ʿ������������⣬վ�������������ݡ�\n");
       set("age", 30);
       set("attitude", "peaceful");

       set("per", 10);
	set("str", 30);
	set("dex", 30);
	set("cor", 30);
	set("int", 10);
	set("con", 30);

       set("max_kee", 1000);
       set("max_sen", 1000);
       set("force",1800);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 800);
	set("mana", 1500);
       set("mana_factor", 40);
       set("combat_exp", 500000);
  set("daoxing", 200000);

       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
	set_skill("staff", 120);
        set_skill("force", 100);
	set_skill("spells", 100);
	set_skill("moshenbu", 120);
	set_skill("lunhui-zhang", 120);
	set_skill("changquan", 100);
	map_skill("unarmed", "changquan");
	map_skill("dodge", "moshenbu");
	map_skill("staff", "lunhui-zhang");
	map_skill("parry", "lunhui-zhang");

setup();

        carry_object("/d/obj/armor/gujia")->wear();
        carry_object("/d/obj/weapon/staff/budd_staff")->wield();
}

�